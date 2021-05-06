/*
 * motor.h
 *
 *  Created on: 19/09/2014
 *      Author: Christian
 */

#ifndef motor_H_
#define motor_H_

#include "derivative.h"
#include <mc9s08jm60.h>                /* I/O map for MC9S08JM60CLDE */


//definiciones para control de motores
#define IN1   PTED_PTED0
#define IN2   PTED_PTED1
#define IN3   PTFD_PTFD1
#define IN4   PTFD_PTFD0

void motores ( long int vel_der, long int vel_izq) ;

#endif /* motor.h */
