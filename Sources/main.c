#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "Includes.h"

#ifdef __cplusplus
extern "C"
#endif
void MCU_init(void); /* Device initialization function declaration */

void retardo (long int t);


void main(void) {
  MCU_init();	/* call Device Initialization */
 
  DisableInterrupts;
  
  umbral_norm();  /* Calculo del valor de el set_point, definicion de Kp y algunas variables*/
    
  /*		INICIALIZACION DE VARIABLES		*/
  
	umbral_blanco=(mitad_sensores>>1);
	umbral_negro=(sensor_max*3)/4;
	error_max=(sensor_max*2);
	
	integral=0;
	derivada=0;
  
    fuera=0;//Variable de estado dle carro
    contador_vueltas=0;//variable de numero de vueltas del carro
    flag_vuelta=0;//bandera de contador de vueltas
    
    derivada_max=12;//declaraciones wind-up
    integral_max=6000;//declaraciones wash out
    
    //Inicializacion de las variables de control
    if(PTBD_PTBD0==1) 
      {
      velocidad=32600; 
      kp=6;
      kd=7050;//7050
      di=850; //900
      } else{
            velocidad=32600; 
            kp=7;//7
            kd=7150;//7150
            di=950; //900
            }
    /*FIN Inicializacion de variables*/
    

  LED=1;
  motores(0,0);
  retardo (3000);//Tiempo de seguridad
  LED=0;  

  EnableInterrupts; /* enable interrupts */ 

  for(;;) {
	  
	  motores(velocidad+PID,velocidad-PID);
	  
	  if (fuera==3)//fuera=3-- parar!!
		{ 
		kp=0;
		kd=0;
		velocidad=0;
		motores(0,0);
		for(;;)
			{
			LED=~LED;
			retardo(1000);
			}    
		}

	  
	  
	  
    /* __RESET_WATCHDOG(); By default COP is disabled with device init. When enabling, also reset the watchdog. */
  } /* loop forever */
  /* please make sure that you never leave main */
}



void retardo (long int t)//Funcion de retardo
{
unsigned int i,j;
  {
  for (i=0;i<t;i++)
    {	
    for (j=0;j<115;j++)
      {	
      asm (nop);
      }
    }
  }
}



