/* Copyright 2015, Eduardo Filomena, Juan Manuel Reta
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "leds.h"       /* <= own header */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



void InicializarLeds( void)
{
	Chip_GPIO_Init(LPC_GPIO_PORT);

	Chip_SCU_PinMux(2,0,MD_PUP,FUNC4);  /* remapea P2_0  en GPIO5[0], LED0R y habilita el
	pull up*/
	Chip_SCU_PinMux(2,1,MD_PUP,FUNC4);  /* remapea P2_1  en GPIO5[1], LED0G y habilita
	el pull up */
	Chip_SCU_PinMux(2,2,MD_PUP,FUNC4);  /* remapea P2_2  en GPIO5[2], LED0B y habilita el
	pull up */
	Chip_SCU_PinMux(2,10,MD_PUP,FUNC0); /* remapea P2_10 en GPIO0[14], LED1 y habilita
	el pull up */
	Chip_SCU_PinMux(2,11,MD_PUP,FUNC0); /* remapea P2_11 en GPIO1[11], LED2 y habilita
	el pull up */
	Chip_SCU_PinMux(2,12,MD_PUP,FUNC0); /* remapea P2_12 en GPIO1[12], LED3 y habilita
	el pull up */

	Chip_GPIO_SetDir(LPC_GPIO_PORT,5,(1<<0)|(1<<1)|(1<<2),1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,0,(1<<14),1);
	Chip_GPIO_SetDir(LPC_GPIO_PORT,1,(1<<11)|(1<<12),1);

}


void Ledon(Led)
{

	switch(Led)
{
		case 1:
		Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,0,14);   //Amarillo Led 1
		break;
		case 2:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,11);   //Rojo Led 2
		break;
		case 3:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,1,12);   //Verde Led 3
     	break;
		case 4:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,0);   //Rojo RGB
		break;
		case 5:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,1);   //Verde RGB
		break;
		case 6:
			Chip_GPIO_SetPinOutHigh(LPC_GPIO_PORT,5,2);   //Azul RGB

	break;
	}

}
void Ledoff(Led)
{


	switch(Led)
{
		case 1:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,0,14);   //Amarillo Led 1
		break;
		case 2:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,11);   //Rojo Led 2
		break;
		case 3:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,1,12);   //Verde Led 3
     	break;
		case 4:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,0);   //Rojo RGB
		break;
		case 5:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,1);   //Verde RGB
		break;
		case 6:
			Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT,5,2);   //Azul RGB

	break;
	}
}

void invertir(int Led)
{

	switch(Led)
{
		case 1:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,0,14);   //Amarillo Led 1
		break;
		case 2:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,1,11);   //Rojo Led 2
		break;
		case 3:
     	Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,1,12);   //Verde Led 3
     	break;
		case 4:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,5,0);   //Rojo RGB
		break;
		case 5:
		Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,5,1);   //Verde RGB
		break;
		case 6:
	    Chip_GPIO_SetPinToggle(LPC_GPIO_PORT,5,2);   //Azul RGB

	break;
	}

}










/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

