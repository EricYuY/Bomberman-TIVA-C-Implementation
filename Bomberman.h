#ifndef BOMBERMAN_H_
#define BOMBERMAN_H_
#include <stdint.h>
#include "tm4c123gh6pm.h"

#define columnas 21
#define filas 11
#define ancho 4
#define largo 4
#define duracionBomb 23
#define BombasMax 3
#define RangoMax  4
#define DURACIONJUEGO       720 //3 min

/*****                       JUGADOR                              *****/
typedef struct{
   uint8_t x,y;         // POSX, POSY
   uint8_t cantbomb;    // nÚmero de bombas que el personaje puede poner
   uint8_t RangBomb;    // rango de las bombas puestas
   uint8_t vida;        // vida = 1 => Jugador vivo // vida = 0 => Jugador muerto
   uint8_t puntaje;     // Puntaje del jugador
}Personaje;
//////////////////////////////////BOMBA///////////////////////////////////
typedef struct{
    uint8_t x, y;       // POSX, POSY
    uint8_t Rango;      // rango de la bomba
    uint8_t contador;   // contador de la duración de la bomba
    uint8_t origen;     // origen = 1 => Bomba puesta por el jugador 1 // origen = 2 => Bomba puesta por el jugador 2
} Bomb;

//****************************************************************************************
//*****                            GenerarMapa                                       *****
//****************************************************************************************
//***** Crea un arreglo bidimensional que contiene los valores que definen el        *****
//***** escenario incial (paredes, bloques rompibles)                                *****
//****************************************************************************************
//***** ENTRADAS:    mapa[columnas][filas]                                           *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************
void GenerarMapa(uint8_t mapa[columnas][filas]);

//****************************************************************************************/
//*****                             Pintarescenario                                  *****/
//****************************************************************************************/
//***** Genera un mapa de bits (escenario) que representa el escenario del juego     *****/
//***** a partir del arreglo bidimensional(mapa)                                     *****/
//****************************************************************************************/
//***** ENTRADAS:    mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              escenario: arreglo vacío que se convertirá en el mapa de bits   *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void Pintarescenario(uint8_t mapa[columnas][filas],uint8_t escenario[]);

//****************************************************************************************/
//*****                               Pintarjugador                                  *****/
//****************************************************************************************/
//***** Modifica un mapa de bits (escenario) de forma que se muestre la posición     *****/
//***** del jugador                                                                  *****/
//****************************************************************************************/
//***** ENTRADAS:    jn: jugador                                                     *****/
//*****              n : número del jugador (1 o 2)                                  *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//*****              ACCION: 1=> Pintar , 0 => Borrar                                *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarJugador(Personaje jn, uint8_t n, uint8_t escenario[], uint8_t ACCION);

//****************************************************************************************/
//*****                             ValidarMovJugador                                *****/
//****************************************************************************************/
//***** Verifica que el jugador se pueda mover en la dirección indicada por la tecla *****/
//***** presionada y mueve al jugador en esa dirección si es que se puede.            *****/
//****************************************************************************************/
//***** ENTRADAS:    tecla: tecla presionada                                         *****/
//*****              jn   : jugador                                                  *****/
//*****              n : número del jugador (1 o 2)                                  *****/
//*****              mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//*****              ACCION: 1=> Pintar , 0 => Borrar                                *****/
//***** SALIDA:      jn                                                              *****/
//****************************************************************************************/
Personaje ValidarMovJugador( uint8_t tecla, Personaje jn, uint8_t n, uint8_t mapa[columnas][filas],uint8_t escenario[]);

//****************************************************************************************/
//*****                             ValidarExplosión                                 *****/
//****************************************************************************************/
//***** Verifica que se pueda poner la bomba en la posición del jugador jn, además   *****/
//***** inica el conteo de la misma, desaparece las paredes cercanas a la explosión  *****/
//****************************************************************************************/
//***** ENTRADAS:    tecla: tecla presionada                                         *****/
//*****              mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              Bomba   : contiene información sobre las bombas                 *****/
//*****              j1   : jugador 1                                                *****/
//*****              j2   : jugador 2                                                *****/
//*****              BombasActivas : arreglo que contiene info. sobre las bombas     *****/
//*****                              puestas                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ValidarExplosion( uint8_t tecla, uint8_t mapa[columnas][filas], Bomb Bomba[BombasMax*2], Personaje* j1,Personaje* j2, uint8_t BombasActivas[2]);

//****************************************************************************************/
//*****                               AplicarPowerUp                                 *****/
//****************************************************************************************/
//***** Valida que el jugador haya tomado un power-up y de haberlo hecho lo aplica   *****/
//****************************************************************************************/
//***** ENTRADAS:    mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              jn: jugador                                                     *****/
//***** SALIDA:      jn                                                              *****/
//****************************************************************************************/
Personaje AplicarPowerUp(uint8_t mapa[columnas][filas], Personaje jn);

//****************************************************************************************/
//*****                         ConfigTemporizador250ms                              *****/
//****************************************************************************************/
//***** Configura el temporizador del sistema a 250ms a una frecuencia del sistema   *****/
//***** de 50MHz                                                                     *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ConfigTemporizador250ms();

//****************************************************************************************/
//*****                         ValidarFinTemporizador250ms                          *****/
//****************************************************************************************/
//***** Valida que temporizador del sistema haya terminado de contar lo 250ms        *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      0: No terminó de contar                                         *****/
//*****              1: Terminó de contar                                            *****/
//****************************************************************************************/
uint8_t ValidarFinTemporizador250ms();

//****************************************************************************************/
//*****                               PintarTiempo                                   *****/
//****************************************************************************************/
//***** Pinta en la pantalla una barra que indica cuánto tiempo transcurrió.         *****/
//***** Diseñada para un tiempo de 3 minutos.                                        *****/
//****************************************************************************************/
//***** ENTRADAS:    temp: variable que indica cuánto tiempo pasó                    *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarTiempo(uint16_t temp, uint8_t escenario[]);
//void MostrarPantalladeInicio(uint32_t* i);

#endif /* BOMBERMAN_H_ */
