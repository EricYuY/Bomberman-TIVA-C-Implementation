#include "tm4c123gh6pm.h"
#include "Nokia5110.h"
#include <stdint.h>

#define DC                      (*((volatile unsigned long *)0x40004100))
#define DC_COMMAND              0
#define DC_DATA                 0x40
#define RESET                   (*((volatile unsigned long *)0x40004200))
#define RESET_LOW               0
#define RESET_HIGH              0x80
#define COMMAND                 0
#define DATA                    1


void static lcdwrite(uint8_t tipo, char dato){
  if(tipo == COMMAND){
    while((SSI0_SR_R&SSI_SR_BSY)==SSI_SR_BSY){}; // espera que el buffer de transmisión esté vacío
    DC = DC_COMMAND;
    SSI0_DR_R = dato;                            // se envió comando
    while((SSI0_SR_R&SSI_SR_BSY)==SSI_SR_BSY){}; // espera que el buffer de transmisión esté vacío
  } else{
    while((SSI0_SR_R&SSI_SR_TNF)==0){};          // espera a que el buffer de transmisión no esté lleno
    DC = DC_DATA;
    SSI0_DR_R = dato;                            // se envió dato
  }
}

//****************************************************************************************/
//*****                           InicializaNokia5110                                *****/
//****************************************************************************************/
//***** Inicializa el Nokia 5110, asumiendo un reloj del sistema de 50MHz            *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void InicializaNokia5110(void){
  volatile unsigned long delay;
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_SSI0;                  // se habilita SSI0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;                 // se habilita el puerto A
  while(!(SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0));         // se espera a que se active
  GPIO_PORTA_DIR_R |= 0xC0;                             // PA6, PA7 como salidas
  GPIO_PORTA_AFSEL_R |= 0x2C;                           // se habilitan funciones alternas en PA2, PA3, PA5
  GPIO_PORTA_AFSEL_R &= ~0xC0;                          // se deshabilitan funciones alternas en PA6, PA7
  GPIO_PORTA_DEN_R |= 0xEC;                             // se habilitan funciones digitales en PA2, PA3, PA5, PA6, PA7
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFF0F00FF)+0x00202200; // se configura PA2, PA3, PA5 como SSI
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0x00FFFFFF)+0x00000000; // se configura PA6, PA7 como GPIO
  GPIO_PORTA_AMSEL_R &= ~0xEC;                          // se deshabilitan funciones analógicas en PA2, PA3, PA5, PA6, PA7

  SSI0_CR1_R &= ~SSI_CR1_SSE;                           // se deshabilita el SSI
  SSI0_CR1_R &= ~SSI_CR1_MS;                            // se configura como modo maestro
  SSI0_CC_R = (SSI0_CC_R&~SSI_CC_CS_M)+SSI_CC_CS_SYSPLL;// se configura el reloj del sistema/PLL como clock source(fuente de reloj)
  SSI0_CPSR_R = (SSI0_CPSR_R&~SSI_CPSR_CPSDVSR_M)+16;   // divisor de reloj para 3.125 MHz SSIClk (50 MHz PIOSC/16)
  SSI0_CR0_R &= ~(SSI_CR0_SCR_M |       // SCR = 0 (3.125 Mbps data rate)
                  SSI_CR0_SPH |         // SPH = 0
                  SSI_CR0_SPO);         // SPO = 0
                                        // FRF = Freescale format
  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_FRF_M)+SSI_CR0_FRF_MOTO;
                                        // DSS = 8-bit data
  SSI0_CR0_R = (SSI0_CR0_R&~SSI_CR0_DSS_M)+SSI_CR0_DSS_8;
  SSI0_CR1_R |= SSI_CR1_SSE;            // se habilita el SSI

  RESET = RESET_LOW;                    // resetea el LCD
  for(delay=0; delay<10; delay=delay+1);// delay  100 ns
  RESET = RESET_HIGH;                   // lógica negada

  lcdwrite(COMMAND, 0x21);              // chip active; horizontal addressing mode (V = 0); use extended instruction set (H = 1)
                                        // set LCD Vop (contrast), which may require some tweaking:
  lcdwrite(COMMAND, CONTRAST);          // establecer contraste
  lcdwrite(COMMAND, 0x04);              // establecer coeficiente de temperatura
  lcdwrite(COMMAND, 0x14);              // LCD bias mode 1:48

  lcdwrite(COMMAND, 0x20);              // se debe enviar 0x20 antes de modificar el modo de control del display
  lcdwrite(COMMAND, 0x0C);              // poner el control del display en modo normal // 0x0D para modo inverso
}
//****************************************************************************************/
//*****                             EscribirCaracter                                 *****/
//****************************************************************************************/
//***** Escribe un carácter de 5x8 pixeles en la pantalla en la posición actual del  *****/
//***** cursor. El cursor irá a la siguiente columna para escribir el siguiente      *****/
//***** carácter.                                                                    *****/
//****************************************************************************************/
//***** ENTRADAS:    carácter a imprimir                                             *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void EscribirCaracter(uint8_t data){
  int i;
  lcdwrite(DATA, 0x00);                 // blank vertical line padding
  for(i=0; i<5; i=i+1){
    lcdwrite(DATA, ASCII[data - 0x20][i]);
  }
  lcdwrite(DATA, 0x00);                 // blank vertical line padding
}

//****************************************************************************************/
//*****                              EscribirCadena                                  *****/
//****************************************************************************************/
//***** Escribe una cadena de caracteres en la pantalla en la posición actual del    *****/
//***** cursor.                                                                      *****/
//****************************************************************************************/
//***** ENTRADAS:    puntero a cadena ASCII-Z                                        *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void EscribirCadena(char *ptr){
  while(*ptr){
      EscribirCaracter((unsigned char)*ptr);
    ptr = ptr + 1;
  }
}

//****************************************************************************************/
//*****                              EscribirNumero                                  *****/
//****************************************************************************************/
//***** Escribe un número decimal de 8 bits en la pantalla en la posición actual del *****/
//***** cursor.                                                                      *****/
//****************************************************************************************/
//***** ENTRADAS:    número sin signo de 8 bit                                       *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void EscribirNumero(uint8_t n){
  if(n < 10){
   // EscribirCadena("    ");
    EscribirCaracter(n+'0'); /* n está entre 0 y 9 */
  } else if(n<100){
   // EscribirCadena("   ");
    EscribirCaracter(n/10+'0'); /* decenas */
    EscribirCaracter(n%10+'0'); /* unidades */
  } else if(n<1000){
   // EscribirCadena("  ");
    EscribirCaracter(n/100+'0'); /* centenas */
    n = n%100;
    EscribirCaracter(n/10+'0'); /* decenas */
    EscribirCaracter(n%10+'0'); /* unidades */
  }
}

//****************************************************************************************/
//*****                                PonerCursor                                   *****/
//****************************************************************************************/
//***** Mueve el cursor a la posición XY deseada.                                    *****/
//***** X=0 es la primera columna de la izquierda, Y=0 es la primera fila superior   *****/
//****************************************************************************************/
//***** ENTRADAS:    newX: nueva posición X del cursor (0<=newX<=11)                 *****/
//*****              newY: nueva posición Y del cursor (0<=newY<=5)                  *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PonerCursor(uint8_t newX, uint8_t  newY){
  if((newX > 11) || (newY > 5)){        // posición no posible
    return;                             // hacer nada
  }
  // multiplica newX por 7 porque cada carácter ocupa 7 columnas
  lcdwrite(COMMAND, 0x80|(newX*7));     // poniendo el bit 7 (0x80) actualiza la posición X
  lcdwrite(COMMAND, 0x40|newY);         // poniendo el bit 6 (0x40) actualiza la posición Y
}

//****************************************************************************************/
//*****                              BorrarPantalla                                  *****/
//****************************************************************************************/
//***** Borra la pantalla y pone el cursor en la esquina superior izquierda de la    *****/
//***** pantalla (0,0)                                                               *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void BorrarPantalla(){
  int i;
  for(i=0; i<(MAX_X*MAX_Y/8); i=i+1){
    lcdwrite(DATA, 0x00);
  }
  PonerCursor(0, 0);
}

//****************************************************************************************/
//*****                              PintarPantalla                                  *****/
//****************************************************************************************/
//***** Pinta la pantalla completa con un mapa de bits de 48 x 84                    *****/
//****************************************************************************************/
//***** ENTRADAS:    puntero a un mapa de bits de 504 bytes                          *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarPantalla( uint8_t *ptr){
  int i;
  PonerCursor(0, 0);
  for(i=0; i<(MAX_X*MAX_Y/8); i=i+1){
    lcdwrite(DATA, ptr[i]);
  }
}

//****************************************************************************************/
//*****                           PintarPantallaconst                                *****/
//****************************************************************************************/
//***** Pinta la pantalla completa con un mapa de bits de 48 x 84                    *****/
//****************************************************************************************/
//***** ENTRADAS:    puntero a un mapa de bits de 504 bytes (const)                  *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarPantallaconst(const uint8_t *ptr){
    int i;
    PonerCursor(0, 0);
    for(i=0; i<(MAX_X*MAX_Y/8); i=i+1){
      lcdwrite(DATA, ptr[i]);
    }
}

