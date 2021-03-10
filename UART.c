#include "tm4c123gh6pm.h"
#include "UART.h"
#define FALSE       0
#define TRUE       1

//****************************************************************************************/
//*****                             ConfigPtoSerial                                  *****/
//****************************************************************************************/
//***** Inicializa el puerto serial a 50MHz, 9600bps, sin paridad, 8 bits de dato    *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ConfigPtoSerial(){
    //Activar reloj para UART0
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
    while(!(SYSCTL_PRUART_R & SYSCTL_PRUART_R0));
    //Inhabilitamos el módulo UART
    UART0_CTL_R &= ~(UART_CTL_UARTEN);
    //Configurar velocidad 9600 bps  // Fclksys = 50MHz
    UART0_IBRD_R = (UART0_IBRD_R & ~(0xFFFF))|325;
    UART0_FBRD_R = (UART0_FBRD_R & ~(0x3F))|33;
    //Configurar 8 bits de datos, sin paridad, 1 bit de parada y FIFOs habilitados
    UART0_LCRH_R =(UART0_LCRH_R & ~(0x11))| 0x70;
    //Habilitamos el módulo UART0, el módulo de transmisión y el módulo de recepción
    UART0_CTL_R |= UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN;
    //Configuración de PA0 y PA1 como U0Rx Y U0Tx
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
    while(!( SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0));
    GPIO_PORTA_AFSEL_R |= 0x03;
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & ~(0x11))|0x11;
    GPIO_PORTA_AMSEL_R &= ~(0x03);
    GPIO_PORTA_DEN_R |= 0x03;
}

//****************************************************************************************/
//*****                               SondeaTecla                                    *****/
//****************************************************************************************/
//***** Inicializa el puerto serial a 50MHz, 9600bps, sin paridad, 8 bits de dato    *****/
//****************************************************************************************/
//***** ENTRADAS:    datoRxPtr: puntero que guarda el dato recibido                  *****/
//***** SALIDA:      0: No hay dato recibido                                         *****/
//*****              1: Hay dato recibido                                            *****/
//****************************************************************************************/
uint8_t SondeaTecla(uint8_t *datoRxPtr){
 uint8_t hayDatoRx;
 hayDatoRx = FALSE;
 if(!(UART0_FR_R & UART_FR_RXFE)){
 *datoRxPtr = (uint8_t)UART0_DR_R;
 hayDatoRx = TRUE;
 }
 return hayDatoRx;
}

//****************************************************************************************/
//*****                             VaciarBufferRx                                   *****/
//****************************************************************************************/
//***** Vacía el buffer de recepción del UART0                                       *****/
//****************************************************************************************/
//***** ENTRADAS:    datoRx: variable donde se guarda el dato recibido               *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void VaciarBufferRx(uint8_t datoRx){
    while(!(UART0_FR_R & UART_FR_RXFE)){
        datoRx = (uint8_t)UART0_DR_R;
    }
}
