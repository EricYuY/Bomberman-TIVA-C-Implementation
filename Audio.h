#ifndef AUDIO_H_
#define AUDIO_H_
#include <stdint.h>
#include "tm4c123gh6pm.h"

#define Delay 250000


//****************************************************************************************
//*****                            ConfiguraPWM                                      *****
//****************************************************************************************
//***** Habilita puertos para el PWM                                                 *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************
void ConfiguraPWM();


//****************************************************************************************
//*****                            PlayBackgroundMusic                               *****
//****************************************************************************************
//***** Reproduce la musica de fondo del juego                                       *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************

void PlayBackgroundMusic(uint8_t * n);


//****************************************************************************************
//*****                            PlayBomb                                          *****
//****************************************************************************************
//*****         Reproduce el sonido de la bomba                                      *****
//****************************************************************************************
//***** ENTRADAS:    Ninguna                                                         *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************

void PlayBomb();



#endif /* AUDIO_H_ */
