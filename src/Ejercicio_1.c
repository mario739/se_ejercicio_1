/*=============================================================================
 * Program: Ejercicio_1
 * Date: 2021/07/06
 * Version: 1
 *===========================================================================*/


#include "Ejercicio_1.h"


static gpioMap_t secuencia1[]={LEDB,LED1,LED2,LED3};;
static gpioMap_t secuencia2[]={LED3,LED2,LED1,LEDB};
static gpioMap_t * psecuencia = &secuencia1[0];

static uint8_t i = 0;
static uint8_t sequence = 0;
static uint16_t tiempo=150;;

int main( void )
{

   boardInit();

     while( true )
   {
	   if(!leerTecla(TEC1))
	   {
		   printf("tecla TEC1 presionada:Secuencia Uno");
	   }
	   if(!leerTecla(TEC4))
	   {
		   printf("tecla TEC4 presionada:Secuencia Dos");
	   }
	   if(!leerTecla(TEC2))
	   {
	   		printf("tecla TEC2 presionada:Velocidad Uno");
	   }
	   if(!leerTecla(TEC3))
	   {
	        printf("tecla TEC4 presionada:Velocidad Uno");
	   }
	   activarSecuencia(psecuencia,tiempo);

   }
   return 0;
}
bool_t encenderLed(gpioMap_t led)
{

	gpioWrite(led, ON );
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


