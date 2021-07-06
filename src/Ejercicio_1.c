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
gpioMap_t secuencia[]={LEDB,LED1,LED2,LED3};
gpioMap_t secuencia1[]={LED3,LED2,LED1,LEDB};;
gpioMap_t secuencia2[]={LED1,LED3,LEDB,LED2};
gpioMap_t * psecuencia = secuencia1;
uint8_t i = 0;
int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();
   delay_t delay;
   delayConfig( &delay, 500 );
   // ----- Repeat for ever -------------------------
   while( true )
   {

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
	   activarSecuencia(psecuencia);

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
	return gpioRead(tecla);
}

void activarSecuencia(gpioMap_t activarsecuencia[])
{
	for(i=0;i<=3;i++)
	{
		//encenderLed(activarsecuencia[i]);
		if(i==0)
		{
			gpioWrite(activarsecuencia[0], ON );
			gpioWrite(activarsecuencia[1], OFF );
			gpioWrite(activarsecuencia[2], OFF );
			gpioWrite(activarsecuencia[3], OFF );
		}
		if(i==1)
		{
			gpioWrite(activarsecuencia[0], OFF );
		    gpioWrite(activarsecuencia[1], ON );
			gpioWrite(activarsecuencia[2], OFF );
			gpioWrite(activarsecuencia[3], OFF );
	    }
		if(i==2)
	    {
			gpioWrite(activarsecuencia[0], OFF );
			gpioWrite(activarsecuencia[1], OFF );
			gpioWrite(activarsecuencia[2], ON );
			gpioWrite(activarsecuencia[3], OFF );
	    }
		if(i==3)
		{
			gpioWrite(activarsecuencia[0], OFF);
			gpioWrite(activarsecuencia[1], OFF );
			gpioWrite(activarsecuencia[2], OFF );
			gpioWrite(activarsecuencia[3], ON );
		}
		delay(400);
		//activarsecuencia++;
	}
	i=0;
	return;
}

void prender_secuencia()
{

}



