/*=============================================================================
 * Program: Ejercicio_1
 * Date: 2021/07/06
 * Version: 1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "Ejercicio_1.h"
//#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

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
	   if(!leerTecla(TEC1))
	   {
		   apagarLeds();
		   delayWrite( &delay, 150 );
	   }
	   else
	   {
		   encenderLed(LED3);
	   }

   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}

bool_t encenderLed(gpioMap_t led)
{
	gpioWrite(led, ON );
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

void activarSecuencia(gpioMap_t *activarsecuencia)
{

}




