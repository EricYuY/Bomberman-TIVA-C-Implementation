#include <stdint.h>
#ifndef UART_H_
#define UART_H_

//****************************************************************************************/
//*****                             ConfigPtoSerial                                  *****/
//****************************************************************************************/
//***** Inicializa el puerto serial a 50MHz, 9600bps, sin paridad, 8 bits de dato    *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ConfigPtoSerial();

//****************************************************************************************/
//*****                               SondeaTecla                                    *****/
//****************************************************************************************/
//***** Inicializa el puerto serial a 50MHz, 9600bps, sin paridad, 8 bits de dato    *****/
//****************************************************************************************/
//***** ENTRADAS:    datoRxPtr: puntero que guarda el dato recibido                  *****/
//***** SALIDA:      0: No hay dato recibido                                         *****/
//*****              1: Hay dato recibido                                            *****/
//****************************************************************************************/
uint8_t SondeaTecla(uint8_t *datoRxPtr);

//****************************************************************************************/
//*****                             VaciarBufferRx                                   *****/
//****************************************************************************************/
//***** Vac�a el buffer de recepci�n del UART0                                       *****/
//****************************************************************************************/
//***** ENTRADAS:    datoRx: variable donde se guarda el dato recibido               *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void VaciarBufferRx(uint8_t datoRx);

#endif /* UART_H_ */
