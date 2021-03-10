#include <stdlib.h>
#include <time.h>
#include "Bomberman.h"
#include "Nokia5110.h"


const uint8_t DisenoPersonajes[]={0x08,0x09,0x0F,0x08,0x0A,0x05,0x05,0x0A};
/*
const uint8_t juegoinicio [] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x53, 0x03,
        0x27, 0xFF, 0x1F, 0x0F, 0x4F, 0x0F, 0x1F, 0xFF, 0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xCF, 0x0F, 0x1F,
        0xFF, 0x03, 0x03, 0x4F, 0x0F, 0x1F, 0xFF, 0x1F, 0x0F, 0xAF, 0x8F, 0x9F, 0xFF, 0x0F, 0x0F, 0xDF,
        0xCF, 0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xCF, 0x0F, 0x1F, 0xFF, 0x6F, 0x2F, 0xAF, 0x0F, 0x1F, 0xFF,
        0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x63, 0x33, 0x33, 0x01, 0x04,
        0x0E, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE,
        0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE,
        0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
        0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC,
        0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
const uint8_t juegoinicio2 [] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x03, 0x53, 0x03,
        0x27, 0xFF, 0x1F, 0x0F, 0x4F, 0x0F, 0x1F, 0xFF, 0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xCF, 0x0F, 0x1F,
        0xFF, 0x03, 0x03, 0x4F, 0x0F, 0x1F, 0xFF, 0x1F, 0x0F, 0xAF, 0x8F, 0x9F, 0xFF, 0x0F, 0x0F, 0xDF,
        0xCF, 0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xCF, 0x0F, 0x1F, 0xFF, 0x6F, 0x2F, 0xAF, 0x0F, 0x1F, 0xFF,
        0x0F, 0x0F, 0xDF, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x07, 0x63, 0x33, 0x33, 0x01, 0x04,
        0x0E, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE,
        0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE,
        0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE,
        0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC,
        0xFC, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xBF, 0xBF, 0x5F, 0x5F, 0xFF, 0xFF, 0x0F, 0x0F, 0xAF, 0x8F, 0xFF, 0x1F, 0x1F, 0xFF,
        0x1F, 0xFF, 0x0F, 0xFF, 0xFF, 0x9F, 0x5F, 0xFF, 0x3F, 0x1F, 0x5F, 0x9F, 0xFF, 0xFF, 0xFF, 0x1F,
        0xFF, 0x1F, 0xFF, 0x1F, 0x1F, 0xDF, 0x1F, 0xFF, 0xFF, 0x1F, 0x5F, 0x1F, 0xFF, 0xFF, 0xFF, 0xDF,
        0x0F, 0xDF, 0x3F, 0x1F, 0x5F, 0x9F, 0xFF, 0x3F, 0x1F, 0xDF, 0x9F, 0xFF, 0x0F, 0xFF, 0xFF, 0x1F,
        0x5F, 0x1F, 0xFF, 0xFF, 0x5F, 0x5F, 0xBF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE,
        0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFF,
        0xFE, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};
*/

void Delay(uint32_t num){
    uint32_t i;
    for(i=0;i<num;i++);
}
///////////////////////////////////////// Numero aleatorio entre 3-5 /////////////////////
uint8_t Aleatorio(){
    uint8_t numAleatorio=3, temp;
    temp = rand()%20;
    if(temp == 18){
        numAleatorio = 4;
    }
    if(temp == 19){
        numAleatorio = 5;
    }

    return numAleatorio;
}

//****************************************************************************************
//*****                            GenerarMapa                                       *****
//****************************************************************************************
//***** Crea un arreglo bidimensional que contiene los valores que definen el        *****
//***** escenario incial (paredes, bloques rompibles)                                *****
//****************************************************************************************
//***** ENTRADAS:    mapa[columnas][filas]                                           *****
//***** SALIDA:      Ninguna                                                         *****
//****************************************************************************************
void GenerarMapa(uint8_t mapa[columnas][filas]){
    srand(time(NULL));
    uint8_t i,j;
    for(i = 0;i < columnas;i++){
        for(j=0; j<filas;j++){
            if(i==0 ||j==0 || i==columnas -1 || j== filas -1) //bordes
                mapa[i][j] = 1;
            else{
                if(i%2==0 && j%2==0)
                    mapa[i][j] = 1;
                else{
                    if((i==1 && (j==1||j==2)) || (j==1 && i== 2) || (i==columnas-2 && (j==filas-3||j==filas-2)) || (j==filas-2 && i== columnas-3))//zona movible inicial
                        mapa[i][j] = 0;
                    else
                        mapa[i][j] = rand()%2 + 2; // 3=> espacio libre, 2=> destruible
                }
            }
        }
    }
}

//****************************************************************************************/
//*****                             Pintarescenario                                  *****/
//****************************************************************************************/
//***** Genera un mapa de bits (escenario) que representa el escenario del juego     *****/
//***** a partir del arreglo bidimensional(mapa)                                     *****/
//****************************************************************************************/
//***** ENTRADAS:    mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              escenario: arreglo vacio que se convertira en el mapa de bits   *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void Pintarescenario(uint8_t mapa[columnas][filas],uint8_t escenario[]){
    uint8_t i,j,k;
    for(j=0;j<filas;j++){
        for(i=0;i<columnas;i++){
            if(mapa[i][j]==1){
                 for(k=0;k<filas;k+=2){
                    if(j==k){
                        escenario[i*ancho +k*84/2]  |= 0x0F;
                        escenario[i*ancho+1+k*84/2] |= 0x0F;
                        escenario[i*ancho+2+k*84/2] |= 0x0F;
                        escenario[i*ancho+3+k*84/2] |= 0x0F;
                    }else if(j==k+1){
                        escenario[i*ancho+k*84/2]   |= 0xF0;
                        escenario[i*ancho+1+k*84/2] |= 0xF0;
                        escenario[i*ancho+2+k*84/2] |= 0xF0;
                        escenario[i*ancho+3+k*84/2] |= 0xF0;}    }
            }else if(mapa[i][j]==0 || mapa[i][j]==3){
                    for(k=0;k<filas;k+=2){
                        if(j==k){
                        escenario[i*ancho +k*84/2]   &= ~(0x0F);
                        escenario[i*ancho+1+k*84/2]  &= ~(0x0F);
                        escenario[i*ancho+2+k*84/2]  &= ~(0x0F);
                        escenario[i*ancho+3+k*84/2]  &= ~(0x0F);
                    }else if(j==k+1){
                        escenario[i*ancho+k*84/2]    &= ~(0xF0);
                        escenario[i*ancho+1+k*84/2]  &= ~(0xF0);
                        escenario[i*ancho+2+k*84/2]  &= ~(0xF0);
                        escenario[i*ancho+3+k*84/2]  &= ~(0xF0);}    }
            }else if(mapa[i][j]==2){
                     for(k=0;k<filas;k+=2){
                        if(j==k){
                        escenario[i*ancho +k*84/2]  |= 0x09;
                        escenario[i*ancho+1+k*84/2] |= 0x06;
                        escenario[i*ancho+2+k*84/2] |= 0x06;
                        escenario[i*ancho+3+k*84/2] |= 0x09;
                    }else if(j==k+1){
                        escenario[i*ancho+k*84/2]   |= 0x90;
                        escenario[i*ancho+1+k*84/2] |= 0x60;
                        escenario[i*ancho+2+k*84/2] |= 0x60;
                        escenario[i*ancho+3+k*84/2] |= 0x90;}    }
            }else if(mapa[i][j]==4){
                for(k=0;k<filas;k+=2){
                   if(j==k){
                   escenario[i*ancho +k*84/2]  |= 0x02;
                   escenario[i*ancho+1+k*84/2] |= 0x03;
                   escenario[i*ancho+2+k*84/2] |= 0x0C;
                   escenario[i*ancho+3+k*84/2] |= 0x04;
               }else if(j==k+1){
                   escenario[i*ancho+k*84/2]   |= 0x20;
                   escenario[i*ancho+1+k*84/2] |= 0x30;
                   escenario[i*ancho+2+k*84/2] |= 0xC0;
                   escenario[i*ancho+3+k*84/2] |= 0x40;}    }
            }else if(mapa[i][j]==5){
                for(k=0;k<filas;k+=2){
                   if(j==k){
                   escenario[i*ancho +k*84/2]  |= 0x02;
                   escenario[i*ancho+1+k*84/2] |= 0x05;
                   escenario[i*ancho+2+k*84/2] |= 0x0A;
                   escenario[i*ancho+3+k*84/2] |= 0x04;
               }else if(j==k+1){
                   escenario[i*ancho+k*84/2]   |= 0x20;
                   escenario[i*ancho+1+k*84/2] |= 0x50;
                   escenario[i*ancho+2+k*84/2] |= 0xA0;
                   escenario[i*ancho+3+k*84/2] |= 0x40;}    }
            }else if(mapa[i][j]==6){
                for(k=0;k<filas;k+=2){
                   if(j==k){
                   escenario[i*ancho +k*84/2]  |= 0x06;
                   escenario[i*ancho+1+k*84/2] |= 0x0D;
                   escenario[i*ancho+2+k*84/2] |= 0x09;
                   escenario[i*ancho+3+k*84/2] |= 0x06;
               }else if(j==k+1){
                   escenario[i*ancho+k*84/2]   |= 0x60;
                   escenario[i*ancho+1+k*84/2] |= 0xD0;
                   escenario[i*ancho+2+k*84/2] |= 0x90;
                   escenario[i*ancho+3+k*84/2] |= 0x60;}    }
        }
        }
    }
}

//****************************************************************************************/
//*****                               Pintarjugador                                  *****/
//****************************************************************************************/
//***** Modifica un mapa de bits (escenario) de forma que se muestre la posicion     *****/
//***** del jugador                                                                  *****/
//****************************************************************************************/
//***** ENTRADAS:    jn: jugador                                                     *****/
//*****              n : numero del jugador (1 o 2)                                  *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//*****              ACCION: 1=> Pintar , 0 => Borrar                                *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarJugador(Personaje jn, uint8_t n, uint8_t escenario[], uint8_t ACCION){ //ACCION=1 =>PINTA , ACCION = 0 => BORRA // n => numero del jugador
    uint8_t k;
        if(ACCION){
        if(jn.vida==1){
            for(k=0;k<filas;k+=2){
                  if(jn.y==k){
                      escenario[jn.x*ancho +k*84/2]  = (escenario[jn.x*ancho +k*84/2]   & ~(0x01))|DisenoPersonajes[4*n-4];
                      escenario[jn.x*ancho+1+k*84/2] = (escenario[jn.x*ancho+1 +k*84/2] & ~(0x01))|DisenoPersonajes[4*n-3];
                      escenario[jn.x*ancho+2+k*84/2] = (escenario[jn.x*ancho+2 +k*84/2] & ~(0x01))|DisenoPersonajes[4*n-2];
                      escenario[jn.x*ancho+3+k*84/2] = (escenario[jn.x*ancho+3 +k*84/2] & ~(0x01))|DisenoPersonajes[4*n-1];
                  }else if(jn.y==k+1){
                      escenario[jn.x*ancho +k*84/2]  = (escenario[jn.x*ancho +k*84/2] & ~(0x10))|((DisenoPersonajes[4*n-4])<<4);
                      escenario[jn.x*ancho+1+k*84/2] = (escenario[jn.x*ancho+1 +k*84/2] & ~(0x10))|((DisenoPersonajes[4*n-3])<<4);
                      escenario[jn.x*ancho+2+k*84/2] = (escenario[jn.x*ancho+2 +k*84/2] & ~(0x10))|((DisenoPersonajes[4*n-2])<<4);
                      escenario[jn.x*ancho+3+k*84/2] = (escenario[jn.x*ancho+3 +k*84/2] & ~(0x10))|((DisenoPersonajes[4*n-1])<<4);}    }

              }
        }else{
            for(k=0;k<filas;k+=2){
                      if(jn.y==k){
                          escenario[jn.x*ancho +k*84/2]   &= ~(0x0F);
                          escenario[jn.x*ancho+1+k*84/2]  &= ~(0x0F);
                          escenario[jn.x*ancho+2+k*84/2]  &= ~(0x0F);
                          escenario[jn.x*ancho+3+k*84/2]  &= ~(0x0F);
                      }else if(jn.y ==k+1){
                          escenario[jn.x*ancho +k*84/2]   &= ~(0xF0);
                          escenario[jn.x*ancho+1+k*84/2]  &= ~(0xF0);
                          escenario[jn.x*ancho+2+k*84/2]  &= ~(0xF0);
                          escenario[jn.x*ancho+3+k*84/2]  &= ~(0xF0);}
              }
        }
}

//****************************************************************************************/
//*****                             ValidarMovJugador                                *****/
//****************************************************************************************/
//***** Verifica que el jugador se pueda mover en la direccion indicada por la tecla *****/
//***** presionada y mueve al jugador en esa dirección si es que se puede            *****/
//****************************************************************************************/
//***** ENTRADAS:    tecla: tecla presionada                                         *****/
//*****              jn   : jugador                                                  *****/
//*****              n : numero del jugador (1 o 2)                                  *****/
//*****              mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//*****              ACCION: 1=> Pintar , 0 => Borrar                                *****/
//***** SALIDA:      jn                                                              *****/
//****************************************************************************************/
Personaje ValidarMovJugador( uint8_t tecla, Personaje jn, uint8_t n, uint8_t mapa[columnas][filas],uint8_t escenario[]){
    if(n==1){
        if(tecla=='a'){
           Delay(40);
            if(mapa[(jn.x) -1][jn.y]!=1 && mapa[(jn.x)-1][jn.y]!=2 && mapa[(jn.x)-1][jn.y]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.x = jn.x-1;
            }
        }else if(tecla=='d'){
            Delay(40);
            if(mapa[(jn.x+1)][jn.y]!=1 && mapa[(jn.x+1)][jn.y]!=2 && mapa[(jn.x+1)][jn.y]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.x = jn.x+1;
            }
        }else if(tecla=='s'){
            Delay(40);
            if(mapa[(jn.x)][jn.y+1]!=1 && mapa[(jn.x)][jn.y+1]!=2 && mapa[(jn.x)][jn.y+1]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.y = jn.y+1;
            }
        }else if(tecla=='w'){
            Delay(40);
              if(mapa[(jn.x)][jn.y-1]!=1 && mapa[(jn.x)][jn.y-1]!=2 && mapa[(jn.x)][jn.y-1]!=6){
                  PintarJugador(jn,1,escenario,0);
                  jn.y = jn.y-1;
              }
        }
    }
    if(n==2){
        if(tecla=='j'){
           Delay(40);
            if(mapa[(jn.x) -1][jn.y]!=1 && mapa[(jn.x)-1][jn.y]!=2 && mapa[(jn.x)-1][jn.y]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.x = jn.x-1;
            }
        }else if(tecla=='l'){
            Delay(40);
            if(mapa[(jn.x+1)][jn.y]!=1 && mapa[(jn.x+1)][jn.y]!=2 && mapa[(jn.x+1)][jn.y]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.x = jn.x+1;
            }
        }else if(tecla=='k'){
            Delay(40);
            if(mapa[(jn.x)][jn.y+1]!=1 && mapa[(jn.x)][jn.y+1]!=2 && mapa[(jn.x)][jn.y+1]!=6){
                PintarJugador(jn,1,escenario,0);
                jn.y = jn.y+1;
            }
        }else if(tecla=='i'){
            Delay(40);
              if(mapa[(jn.x)][jn.y-1]!=1 && mapa[(jn.x)][jn.y-1]!=2 && mapa[(jn.x)][jn.y-1]!=6){
                  PintarJugador(jn,1,escenario,0);
                  jn.y = jn.y-1;
              }
        }
    }
    return jn;
}
void SumarPuntaje (uint8_t *PuntajeJn){   //funcion sumar puntaje
    *PuntajeJn++;
}
void RomperBloques(uint8_t PosBombaX, uint8_t PosBombaY, uint8_t RangoBomba, uint8_t mapa[columnas][filas], Personaje* j1,Personaje* j2,uint8_t Bomborigen){
    uint8_t i, ParaBomb= 0;
    // X+
    for(i=0;((i<=RangoBomba) && (ParaBomb != 1));i++){
        if(mapa[PosBombaX + i][PosBombaY]==2){
            mapa[PosBombaX + i][PosBombaY]= Aleatorio();
            ParaBomb = 1;
            if(Bomborigen == 1)
                (*j1).puntaje++; // Si rompe bloque suma puntaje del jugador
            else if(Bomborigen ==2)
                (*j2).puntaje++;
        }
        else if(mapa[PosBombaX + i][PosBombaY]==1){
            ParaBomb = 1;
        }
        else if(mapa[PosBombaX + i][PosBombaY]==4 || mapa[PosBombaX + i][PosBombaY]==5) {
            mapa[PosBombaX + i][PosBombaY]= 3;
        }
    }
    ParaBomb = 0;

    // X-
    for(i=0;((i<=RangoBomba) && (ParaBomb != 1));i++){
        if(mapa[PosBombaX - i][PosBombaY]==2){
            mapa[PosBombaX - i][PosBombaY]= Aleatorio();
            ParaBomb = 1;
            if(Bomborigen == 1)
                (*j1).puntaje++; // Si rompe bloque suma puntaje del jugador
            else if(Bomborigen ==2)
                (*j2).puntaje++;
        }
        else if(mapa[PosBombaX - i][PosBombaY]==1){
            ParaBomb = 1;
        }
        else if(mapa[PosBombaX - i][PosBombaY]==4 || mapa[PosBombaX- i][PosBombaY]==5) {
            mapa[PosBombaX - i][PosBombaY]= 3;
        }
    }
    ParaBomb = 0;

    // Y+
    for(i=0;((i<=RangoBomba) && (ParaBomb != 1));i++){
        if(mapa[PosBombaX][PosBombaY + i]==2){
            mapa[PosBombaX][PosBombaY+ i]= Aleatorio();
            ParaBomb = 1;
            if(Bomborigen == 1)
                (*j1).puntaje++; // Si rompe bloque suma puntaje del jugador
            else if(Bomborigen ==2)
                (*j2).puntaje++;
        }
        else if(mapa[PosBombaX][PosBombaY + i]==1){
            ParaBomb = 1;
        }
        else if(mapa[PosBombaX][PosBombaY + i]==4 || mapa[PosBombaX][PosBombaY + i]==5) {
            mapa[PosBombaX][PosBombaY + i]= 3;
        }
    }
    ParaBomb = 0;

    //Y-
    for(i=0;((i<=RangoBomba) && (ParaBomb != 1));i++){
        if(mapa[PosBombaX][PosBombaY - i]==2){
            mapa[PosBombaX][PosBombaY - i]= Aleatorio();
            ParaBomb = 1;
            if(Bomborigen == 1)
                (*j1).puntaje++; // Si rompe bloque suma puntaje del jugador
            else if(Bomborigen ==2)
                (*j2).puntaje++;
        }
        else if(mapa[PosBombaX][PosBombaY - i]==1){
            ParaBomb = 1;
        }
        else if(mapa[PosBombaX][PosBombaY - i]==4 || mapa[PosBombaX][PosBombaY - i]==5) {
            mapa[PosBombaX][PosBombaY - i]= 3;
        }
    }
    ParaBomb = 0;
}
void MatarJugadores(Personaje* j1, Personaje* j2, uint8_t PosBombaX, uint8_t PosBombaY, uint8_t RangoBomba ) {
    uint8_t i;
    for(i=0;(i<=RangoBomba);i++){
        //X+
        if(PosBombaX + i == (*j1).x && PosBombaY == (*j1).y){
                (*j1).vida = 0;
        }
        //X-
        if(PosBombaX - i == (*j1).x && PosBombaY == (*j1).y){
                (*j1).vida = 0;
        }
        //Y+
        if(PosBombaX == (*j1).x && PosBombaY + i== (*j1).y){
                (*j1).vida = 0;
        }
        //Y-
        if(PosBombaX == (*j1).x && PosBombaY - i== (*j1).y){
                (*j1).vida = 0;
        }
    }
    for(i=0;(i<=RangoBomba);i++){
        //X+
         if(PosBombaX + i == (*j2).x && PosBombaY == (*j2).y){
                 (*j2).vida = 0;
         }
         //X-
         if(PosBombaX - i == (*j2).x && PosBombaY == (*j2).y){
                 (*j2).vida = 0;
         }
         //Y+
         if(PosBombaX == (*j2).x && PosBombaY + i== (*j2).y){
                 (*j2).vida = 0;
         }
         //Y-
         if(PosBombaX == (*j2).x && PosBombaY - i== (*j2).y){
                 (*j2).vida = 0;
         }
     }

}
void ExplotarBomba (Personaje* j1,Personaje* j2,uint8_t mapa[columnas][filas], Bomb Bomba[BombasMax*2], uint8_t BombasActivas[2]){
    uint8_t i;
    for(i=0;i<BombasMax;i++){
        if(Bomba[i].contador == duracionBomb ){
            mapa[(Bomba[i].x)][Bomba[i].y]= 3;
            MatarJugadores(j1,j2, Bomba[i].x, Bomba[i].y, Bomba[i].Rango);
            RomperBloques(Bomba[i].x, Bomba[i].y , Bomba[i].Rango, mapa,j1,j2,Bomba[i].origen);
            Bomba[i].x = 0;
            Bomba[i].y = 0;
            Bomba[i].Rango = 0;
            Bomba[i].contador = 0;
            if(Bomba[i].origen == 1) {
                BombasActivas[0]--;
            }
            else if( Bomba[i].origen == 2){
                BombasActivas[1]--;
            }
        }
    }
}
void ConteoBomba(Bomb Bomba[BombasMax*2]){
    uint8_t i;
    for(i=0;i<BombasMax*2;i++){
        if(Bomba[i].contador >= 1 && Bomba[i].contador < duracionBomb ){
            Bomba[i].contador++;
        }
    }
}
void IniciaBomba (Bomb Bomba[BombasMax*2], Personaje* jn, uint8_t n, uint8_t mapa[columnas][filas]) {
    uint8_t i, BombaPuesta = 0;
        for(i=0;((i<BombasMax*2) && (BombaPuesta != 1));i++){
            if(Bomba[i].x == 0 && Bomba[i].y == 0){
                Bomba[i].x = (*jn).x;
                Bomba[i].y = (*jn).y;
                Bomba[i].Rango = (*jn).RangBomb;
                Bomba[i].contador = 1;
                Bomba[i].origen = n;
                mapa[(Bomba[i].x)][Bomba[i].y]=6;
                BombaPuesta = 1;
            }
        }
}
//****************************************************************************************/
//*****                             ValidarExplosion                                 *****/
//****************************************************************************************/
//***** Verifica que se pueda poner la bomba en la posicion del jugador jn, ademas   *****/
//***** inica el conteo de la misma, desaparece las paredes cercanas a la explosion  *****/
//****************************************************************************************/
//***** ENTRADAS:    tecla: tecla presionada                                         *****/
//*****              mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              Bomba   : contiene informacion sobre las bombas                 *****/
//*****              j1   : jugador 1                                                *****/
//*****              j2   : jugador 2                                                *****/
//*****              BombasActivas : arreglo que contiene info. sobre las bombas     *****/
//*****                              puestas                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ValidarExplosion( uint8_t tecla, uint8_t mapa[columnas][filas], Bomb Bomba[BombasMax*2], Personaje* j1,Personaje* j2, uint8_t BombasActivas[2]){
    uint8_t BombEnable,teclaBombJ1 =0x72 , teclaBombJ2 = 0x6F;

    if(tecla == teclaBombJ1){
       if((*j1).cantbomb > BombasActivas[0]){
               BombEnable = 1;
               BombasActivas[0]++;
       }
       if(BombEnable == 1){
           IniciaBomba(Bomba, j1, 1, mapa);
       }
   }

    if(tecla == teclaBombJ2){
        if((*j2).cantbomb > BombasActivas[1]){
                BombEnable = 1;
                BombasActivas[1]++;
        }
        if(BombEnable == 1){
            IniciaBomba(Bomba, j2, 2, mapa);
        }
    }

    ConteoBomba(Bomba);
    ExplotarBomba (j1,j2,mapa, Bomba, BombasActivas);
}

////////////////////////////////////// Aplicar Power Ups ////////////////////////////////////
//Aumentar Rango
uint8_t AumentarRango(uint8_t Rango){
    if(Rango < RangoMax){
        Rango++;
    }
    return Rango;
}
//Aumentar Bombas
uint8_t AumentarBombas(uint8_t nBombas){
    if(nBombas < BombasMax){
        nBombas++;
    }
    return nBombas;
}

//****************************************************************************************/
//*****                               AplicarPowerUp                                 *****/
//****************************************************************************************/
//***** Valida que el jugador haya tomado un power-up y de haberlo hecho lo aplica   *****/
//****************************************************************************************/
//***** ENTRADAS:    mapa: arreglo bidimensional con los datos del escenario         *****/
//*****              jn: jugador                                                     *****/
//***** SALIDA:      jn                                                              *****/
//****************************************************************************************/
Personaje AplicarPowerUp(uint8_t mapa[columnas][filas], Personaje jn){

    if(mapa[jn.x][jn.y] == 4 || mapa[jn.x][jn.y] == 5){
        if(mapa[jn.x][jn.y] == 5) {
            jn.RangBomb = AumentarRango(jn.RangBomb);
        }
        if(mapa[jn.x][jn.y] == 4){
            jn.cantbomb = AumentarBombas(jn.cantbomb);
        }
        mapa[jn.x][jn.y] = 3;
    }
    return jn;
}
//****************************************************************************************/
//*****                         ConfigTemporizador250ms                              *****/
//****************************************************************************************/
//***** Configura el temporizador del sistema a 250ms a una frecuencia del sistema   *****/
//***** de 50MHz                                                                     *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void ConfigTemporizador250ms() {
    NVIC_ST_CTRL_R &= ~NVIC_ST_CTRL_ENABLE;
    NVIC_ST_RELOAD_R = 0xBEBC1F;
    NVIC_ST_CTRL_R |= NVIC_ST_CTRL_ENABLE | NVIC_ST_CTRL_CLK_SRC;
}
//****************************************************************************************/
//*****                         ValidarFinTemporizador250ms                          *****/
//****************************************************************************************/
//***** Valida que temporizador del sistema haya terminado de contar lo 250ms        *****/
//****************************************************************************************/
//***** ENTRADAS:    Ninguna                                                         *****/
//***** SALIDA:      0: No termino de contar                                         *****/
//*****              1: Termino de contar                                            *****/
//****************************************************************************************/
uint8_t ValidarFinTemporizador250ms(){
    uint8_t FIN = 0;
    if(!(NVIC_ST_CTRL_R & NVIC_ST_CTRL_COUNT))
        FIN = 1;
    return FIN;
}

//****************************************************************************************/
//*****                               PintarTiempo                                   *****/
//****************************************************************************************/
//***** Pinta en la pantalla una barra que indica cuanto tiempo transcurrio.         *****/
//***** Disenada para un tiempo de 3 minutos.                                        *****/
//****************************************************************************************/
//***** ENTRADAS:    temp: variable que indica cuanto tiempo paso                    *****/
//*****              escenario: mapa de bits que representa el escenario del juego   *****/
//***** SALIDA:      Ninguna                                                         *****/
//****************************************************************************************/
void PintarTiempo(uint16_t temp, uint8_t escenario[]){
    uint8_t i;
    if(temp == DURACIONJUEGO/12){
        for(i=0;i<7;i++){
            escenario[420+i] |= 0xEF;
        }
    }else if(temp == DURACIONJUEGO/6){
        for(i=0;i<7;i++){
            escenario[420+7+i] |= 0xEF;
        }
    }else if(temp == DURACIONJUEGO/4){
        for(i=0;i<7;i++){
            escenario[420+2*7+i] |= 0xEF;
        }
    }else if(temp == DURACIONJUEGO/3){
        for(i=0;i<7;i++){
            escenario[420+3*7+i] |= 0xEF;
        }
    }else if(temp == 5*DURACIONJUEGO/12){
        for(i=0;i<7;i++){
            escenario[420+4*7+i] |= 0xEF;
        }
    }else if(temp == DURACIONJUEGO/2){
        for(i=0;i<7;i++){
            escenario[420+5*7+i] |= 0xEF;
        }
    }else if(temp == 7*DURACIONJUEGO/12){
        for(i=0;i<7;i++){
            escenario[420+6*7+i] |= 0xEF;
        }
    }else if(temp == 2*DURACIONJUEGO/3){
        for(i=0;i<7;i++){
            escenario[420+7*7+i] |= 0xEF;
        }
    }else if(temp == 3*DURACIONJUEGO/4){
        for(i=0;i<7;i++){
            escenario[420+8*7+i] |= 0xEF;
        }
    }else if(temp == 5*DURACIONJUEGO/6){
        for(i=0;i<7;i++){
            escenario[420+9*7+i] |= 0xEF;
        }
    }else if(temp == 11*DURACIONJUEGO/2){
        for(i=0;i<7;i++){
            escenario[420+10*7+i] |= 0xEF;
        }
    }else if(temp == DURACIONJUEGO){
        for(i=0;i<7;i++){
            escenario[420+11*7+i] |= 0xEF;
        }
    }
}
/*
void MostrarPantalladeInicio(uint32_t* i){
    if(*i==2083334)
        *i=0;
    if(*i==0)
        PintarPantallaconst(juegoinicio);
    if(*i==1041667)
        PintarPantallaconst(juegoinicio2);
    *i++;
}
*/
