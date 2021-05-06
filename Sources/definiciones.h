/*
 * Includes.h
 *
 *  Created on: 19/09/2014
 *      Author: Christian
 */

#define LED    PTCD_PTCD4


unsigned int sensor_max,sensor_min;
unsigned int mitad_sensores,umbral_blanco,umbral_negro;
int sensor_fi,sensor_fd,sensor_i,sensor_d,sensor_ii,sensor_dd;
char fuera;//variable de estado del carro
char contador_vueltas,flag_vuelta;//variables para contar vueltas

//variables de control
long int suma_izq,suma_der;
unsigned int kp,kd,di;
long int PID,proporcional,integral,derivada,integral_max,derivada_max,velocidad,area,error,error_max,error_ant;

//Variables de propositos especificos

