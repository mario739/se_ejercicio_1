/*=============================================================================
 * Program: Ejercicio_1
 * Date: 2021/07/06
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "Ejercicio_1.h"
#include<stdio.h>
#include<stdlib.h>
//#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

gpioMap_t secuencia1[]={LEDB,LED1,LED2,LED3};;
gpioMap_t secuencia2[]={LED3,LED2,LED1,LEDB};
gpioMap_t * psecuencia = &secuencia1[0];

uint8_t i = 0;
uint8_t sequence = 0;
uint16_t tiempo=150;;

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   //delay_t delay;
   //delayConfig( &delay, 500 );
   // ----- Repeat for ever -------------------------
   while( true )
   {
	   if(!leerTecla(TEC1))
	   {
		   printf("tecla TEC1 presionada");
	   }
	   else
	   {
		   printf("tecla TEC1 no presionada");
	   }
	   if(!leerTecla(TEC4))
	   {
		   printf("tecla TEC4 presionada");
	   }
	   else
	   {
		   printf("tecla TEC4 no presionada");
	   }

	   if(!leerTecla(TEC2))
	   {
	   		printf("tecla TEC1 presionada");
	   }
	   else
	   {
	   		printf("tecla TEC1 no presionada");
	   }
	   if(!leerTecla(TEC3))
	   {
	        printf("tecla TEC4 presionada");
	   }
	   else
	   {
	   		printf("tecla TEC4 no presionada");
	   }


	   //encenderLed(LED1);
	  // printf("led prendido");
	 /*  if(!leerTecla(TEC1))
	   {
		   apagarLeds();
		  //delayWrite( &delay, 150 );
	   }
	   else
	   {
		   encenderLed(LED3);
	   }

*/
	   //delayWrite( &delay, 150 );
	  // activarSecuencia(secuencia2);
	   activarSecuencia(psecuencia,tiempo);

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

bool_t encenderLed(gpioMap_t led)
{
	gpioWrite(led, ON );
	/* if(delayRead(&delay))
	 {
		 delayWrite( &delay, 150 );
		 return 1;
	 }*/
	//return 1;
	delay(100);
	return 1;
}
bool_t apagarLeds()
{
	gpioWrite(LEDB, OFF );
	gpioWrite(LED1, OFF );
	gpioWrite(LED2, OFF );
	gpioWrite(LED3, OFF );
	return 1;
}

bool_t leerTecla(gpioMap_t tecla)
{
	if(!gpioRead(tecla))
	{
		if(tecla==TEC1)
		{
			psecuencia = &secuencia1[0];
		}
		if(tecla==TEC4)
		{
			psecuencia = &secuencia2[0];
		}
		if(tecla==TEC2)
		{
			tiempo=150;
		}
		if(tecla==TEC3)
		{
			tiempo=750;
		}

	}
	return gpioRead(tecla);
}
void activarSecuencia(gpioMap_t * psecuencia2,uint16_t tiempo)
{
	for(i=0;i<=3;i++)
		{
		if(i==0)
		{
		gpioWrite(* psecuencia2, ON );
		gpioWrite(*(psecuencia2+1), OFF );
		gpioWrite(* (psecuencia2+2), OFF );
		gpioWrite(* (psecuencia2+3), OFF );
		}
		if(i==1)
		{
		gpioWrite(* psecuencia2, OFF );
		gpioWrite(* (psecuencia2+1), ON );
		gpioWrite(* (psecuencia2+2), OFF );
		gpioWrite(* (psecuencia2+3), OFF );
				}
		if(i==2)
		{
		gpioWrite(* psecuencia2, OFF );
		gpioWrite(* (psecuencia2+1), OFF );
		gpioWrite(* (psecuencia2+2), ON );
		gpioWrite(* (psecuencia2+3), OFF );
		}
		if(i==3)
		{
		gpioWrite(* psecuencia2, OFF );
		gpioWrite(* (psecuencia2+1), OFF );
		gpioWrite(* (psecuencia2+2), OFF );
		gpioWrite(* (psecuencia2+3), ON );
		}
		delay(tiempo);
		}
		i=0;
	}


