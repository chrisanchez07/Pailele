/*
 * ISD_4002.c
 *
 *  Created on: 19/09/2014	
 *      Author: Christian
 */

#include "sensores.h"

/*FUNCION PARA FILTRO MOVE AVERAGE*/
/*	El orden del filtro determina cuantas muestras se toman para realizar el promedio que suaviza la señal*/
int filtro (char canal,int orden) 
  {
  int q,salida_filtro;
  salida_filtro=0;  
  for(q=1;q<=orden;q++) 
    {
    ADCSC1_ADCH=canal;
    while (ADCSC1_COCO==0)
    	{}
    salida_filtro+=ADCR;     
    }
  salida_filtro/=orden; 
  return salida_filtro;
  }
/*FUNCION DE LECTURA DE LOS SENSORES DE LINEA*/
void sensores(void) 
  {  
  sensor_fd=filtro(5,4);
  sensor_fi=filtro(4,4);
  sensor_d=filtro(8,4);
  sensor_i=filtro(3,4);
  sensor_dd=filtro(9,4);
  sensor_ii=filtro(2,4);
    
  if((sensor_fi<umbral_blanco) && (sensor_i<umbral_blanco) && (sensor_ii<umbral_blanco) && (sensor_fd<umbral_blanco) && (sensor_d<umbral_blanco) && (sensor_dd<umbral_blanco)) 
    {
    fuera=1;
    } 
  else
    {
    fuera=0;
    }
  
  if((sensor_ii>umbral_negro)  &&  (sensor_dd>umbral_negro))//funcion para contar vueltas 
    {
    if(flag_vuelta==0)
      {
      contador_vueltas+=1;
      flag_vuelta=1;
      } 
                 
    if (contador_vueltas==vueltas)//condicion para parar el carro
      {
      fuera=3;
      }
    }
    
  if((sensor_ii<umbral_blanco)  &&  (sensor_dd<umbral_blanco))//cuando ha pasado la linea de indicacion de vueltas blanquea la bandera, esto evita el error que cuente muchas vueltas con una sola linea
      {
      flag_vuelta=0;      
      }        
  
  }

void umbral_norm(void)
	{
	//ubicar alguno de los dos sensores frontales sobre la linea negra de tal modo que 
	//en alguno de los dos se obtenga la maxima lectura
	sensores();
	if(sensor_fi>sensor_fd) 
	  {
	  sensor_max=sensor_fi;
	  } 
	else
	  {
	  sensor_max=sensor_fd;
	  } 	  
	if(sensor_dd<sensor_ii) 
	  {
	  sensor_min=sensor_dd;
	  } 
	else   
	  {
	  sensor_min=sensor_ii;
	  } 	
	mitad_sensores=((sensor_max-sensor_min)/2)+sensor_min;			
	}	
