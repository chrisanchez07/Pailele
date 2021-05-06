/*
 * ISD_4002.h
 *
 *  Created on: 19/092014
 *      Author: Christian
 */

#ifndef sensores_H_
#define sensores_H_

#include "derivative.h"
#include <mc9s08jm60.h>                /* I/O map for MC9S08JM60CLDE */

#define vueltas	4 //indica el numero de vueltas que da antes de parar

//variables de sensores
extern int sensor_fi,sensor_fd,sensor_i,sensor_d,sensor_ii,sensor_dd;
extern unsigned int sensor_max,sensor_min;
extern unsigned int mitad_sensores,umbral_blanco,umbral_negro;

extern char contador_vueltas,flag_vuelta;
extern char fuera;//variable de estado del carro

int filtro (char canal,int orden); 
void sensores(void);
void umbral_norm(void);


#endif /* sensores_H_ */
