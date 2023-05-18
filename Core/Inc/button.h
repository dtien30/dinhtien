/*
 * button.h
 *
 *  Created on: May 14, 2023
 *      Author: dangd
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

void getkeyInput();

#endif /* INC_BUTTON_H_ */
