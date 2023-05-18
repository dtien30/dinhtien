/*
 * button.c
 *
 *  Created on: May 17, 2023
 *      Author: dangd
 */
#include "button.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE; //trang thai on dinh truoc do
int TimerForKeyPress = 200; //2s

void SubKeyProcess(){
	//TODO
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}
void getkeyInput(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){// truong hop nhan tha
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				//TODO
				SubKeyProcess();
				TimerForKeyPress = 200;
			}
		}else{ // truong hop nhan de
			TimerForKeyPress --;
			if(TimerForKeyPress == 0){
				//TODO
				if(KeyReg2 == PRESSED_STATE){
					SubKeyProcess();
				}
				TimerForKeyPress = 200;
			}
		}

	}
}
