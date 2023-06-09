/* OpenOS Keyboard Driver
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"
#include "../shell/shell.cpp"

bool LeftShiftPressed = false;
bool RightShiftPressed = false;
uint_8 LastScancode;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr) {
	if (chr != 0) {
		switch (LeftShiftPressed | RightShiftPressed)
		{
		case true:
			Shell_AddChar(chr - 32);
			break;
		case false:
			Shell_AddChar(chr);
			break;
		}

	}
	else {
		switch (scanCode) {
		case 0x8E: //Backspace
			//Shell_BackspacePressed();
			break;
		case 0x2A: //Left Shift
			//LeftShiftPressed = true;
			break;
		case 0xAA: //Left Shift Released
			//LeftShiftPressed = false;
		case 0x36: //Right Shift
			//RightShiftPressed = true;
			break;
		case 0xB6: //Right Shift Released
			//RightShiftPressed = false;
			break;
		case 0x9C: //Enter
			//PrintString("\n\r");
			Shell_EnterPressed();
			break;
		}
	}
}

void KeyboardHandler0xE0(uint_8 scanCode) {
	switch (scanCode)
	{
	case 0x50:
		//SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
	case 0x48:
		//Shell_UpPressed();
		//SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
	default:
		break;
	}

}
void KeyboardHandler(uint_8 scanCode, uint_8 chr) {

	switch (LastScancode) {
	case 0xE0:
		KeyboardHandler0xE0(scanCode);
		break;
	default:
		StandardKeyboardHandler(scanCode, chr);
	}

	LastScancode = scanCode;
}