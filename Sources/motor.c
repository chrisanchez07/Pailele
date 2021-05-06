/*
 * ISD_4002.c
 *
 *  Created on: May 14, 2014
 *      Author: IvanD
 */

#include "motor.h"

void motores ( long int vel_der, long int vel_izq)    //VELOCIDAD MAXIMA --> 32000
{
int vd,vi;

if (vel_der<-32600)
	{
	vd=32600;
 	IN1=1; 
	IN2=0; 
	}
else if(vel_der > 32600)
	{
	vd=32600;
 	IN1=0;
	IN2=1; 
	}
else if(vel_der < 0)
	{
	vd=(int)(-1*vel_der);
 	IN1=1;
	IN2=0; 
	}
else if(vel_der == 0)
	{										
	vd=32600;
 	IN1=1; 
	IN2=1; 
	}
else 
	{
	vd=(int)(vel_der);
	IN1=0; 
	IN2=1; 
	} 
	
if (vel_izq<-32600)
	{
	vi=32600;
 	IN3=0; 
	IN4=1; 
	}
else if(vel_izq > 32600)
	{
	vi=32600;
 	IN3=1; 
	IN4=0; 
	}
else if(vel_izq < 0)
	{
	vi=(int)(-1*vel_izq);
	IN3=0; 
	IN4=1; 
	}
	
else if(vel_izq == 0)
	{
	vi=16000;
	IN3=1; 
	IN4=1; 
	}
else
	{
	vi=(int)(vel_izq);
	IN3=1; 
	IN4=0; 
	}
	
	/*  CAMBIO DE VELOCIDADES */

  (void)(TPM2C0SC == 0);         
  TPM2C0V = vi;                     
  (void)(TPM2C1SC == 0);              
  TPM2C1V = vd;                     
  }
