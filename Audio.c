#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "notes.h"
#include "Audio.h"

const float  Notas[]={
                      e4,e4,c4,e4,g4,g4

                      ,c4,g4,e4,g4,b4,a4,g4

                      ,e4,g4,a4,f4,g4,e4,c4,a4

                      ,c4,

                      0
};

const float Bomba[]={e2};

//****************************************************************************************
//*****                            ConfiguraPWM                                      *****
//****************************************************************************************
//***** Habilita puertos para el PWM                                                 *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************

void ConfiguraPWM(void){
    unsigned long temp;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOD;
    temp = SYSCTL_RCGC2_R;
    GPIO_PORTD_DIR_R |= 0x01; //pin PD0
    GPIO_PORTD_AMSEL_R &= ~(0x01);
    // Función alterna habilitada
    GPIO_PORTD_AFSEL_R |= 0x01;
    // PD0 conectado a M1PWM0
    GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0xFFFFFFF0) | 0x5;
    GPIO_PORTD_DEN_R |= 0x01;


    // Activamos señal de reloj para módulo PWM1
    SYSCTL_RCGCPWM_R |= SYSCTL_RCGCPWM_R1;
    while(!(SYSCTL_PRPWM_R & SYSCTL_PRPWM_R1));
    // Configuramos divisor de frecuencia con 4
    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
    SYSCTL_RCC_R &= ~SYSCTL_RCC_PWMDIV_M;
    SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_4;
    // Generador 0: Modo cuenta descendente, inhabilitado
    PWM1_0_CTL_R &= ~(0x03FF);
    // PWM A: a 1 en load, a 0 en cmpA
    PWM1_0_GENA_R = (PWM1_0_GENA_R & 0xFFFFF000) | 0x08C;
    // frecuencia base = 100Hz
    PWM1_0_LOAD_R = (PWM1_0_LOAD_R & 0xFFFF0000) | 0x9C3F;
    // Ciclo de trabajo = 20%
    PWM1_0_CMPA_R = (PWM1_0_CMPA_R & 0xFFFF0000) | 0x7CFF;
    // Habilitamos el generador 0
    PWM1_0_CTL_R |= PWM_0_CTL_ENABLE;
    // Habilitamos la señal PWM
    PWM1_ENABLE_R |= PWM_ENABLE_PWM0EN;
}

//****************************************************************************************
//*****                            PlayBackgroundMusic                               *****
//****************************************************************************************
//***** Reproduce la musica de fondo del juego                                       *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************

void PlayBackgroundMusic(uint8_t *n) {

    uint8_t DutyCycle = 50;
    float frecuencia;

    frecuencia = Notas[*n];

    //Registros
    PWM1_0_LOAD_R = 4000000 / frecuencia;     //Frecuencia en el registro
    PWM1_0_CMPA_R = (4000000/frecuencia) * (1- DutyCycle/100.0);  //Dutycycle en el registro
    //siguiente frecuencia de la cancion
    (*n)++ ;
    //reset song
    if(frecuencia == 0){
     (*n)=0;
    }

}

//****************************************************************************************
//*****                            PlayBomb                                          *****
//****************************************************************************************
//*****         Reproduce el sonido de la bomba                                      *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************

void PlayBomb(){

    uint8_t DutyCycle = 50;
    float frecuencia;

   frecuencia = Bomba[0];
   //Registros
   PWM1_0_LOAD_R = 4000000 / frecuencia;     //Frecuencia en el registro
   PWM1_0_CMPA_R = (4000000/frecuencia) * (1- DutyCycle/100.0);  //Dutycycle en el registro

}

