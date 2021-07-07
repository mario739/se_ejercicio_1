/*=============================================================================
 * Program: Ejercicio_1
 * Date: 2021/07/06
 * Version: 1
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __EJERCICIO_1_H__
#define __EJERCICIO_1_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdint.h>
#include <stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include "sapi.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/


/*Funcion para encender un led en particular que resibe como parametro
  el led que se quiere encender  y entrega un 1 si la funcion se ejecuto
 *
 */
static bool_t encenderLed(gpioMap_t led);

/*Funcion para apagar todos los leds, que no tiene parametros de entrada y entrega
  como salida si la funcion se ejecuto correctamente
 *
 */
static bool_t apagarLeds();

/*Funcion para leer si una tecla esta presionada que resibe como parametro de
 entrada una variable de tipo gpioMap_t que tiene que ser un tecla y entrega como salida una
 variable de tipo bool_t que es el estado de la tecla.
 *
 */
static bool_t leerTecla(gpioMap_t tecla);

/*Funcion para activar la secuencia de los leds que resibe como parametro un puntero
 de tipo gpioMap_t y una variable de tipo uint16_t que son la secuencia deseada y el
 tiempo de retardo al momento se hacer la transicion.
 *
 */
static void activarSecuencia(gpioMap_t *psecuencia2,uint16_t tiempo);


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __EJERCICIO_1_H__ */
