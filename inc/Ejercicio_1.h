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
#include "sapi.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/


bool_t encenderLed(gpioMap_t led);
bool_t apagarLeds();
bool_t leerTecla(gpioMap_t tecla);
void activarSecuencia(gpioMap_t *activarsecuecia);


/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __EJERCICIO_1_H__ */
