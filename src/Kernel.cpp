/* OpenOS Kernel
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#include "Kernel.h"

void BootScreen(){
	ClearScreen(BACKGROUND_BLACK | FOREGROUND_WHITE);
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("Starting OpenOS...");
}

void StartScreen(){
	ClearScreen(BACKGROUND_BLUE | FOREGROUND_WHITE);
	SetCursorPosition(PositionFromCoords(0, 0));
    PrintString("   ____                    ____   _____ \n\r");
    PrintString("  / __ \\                  / __ \\ / ____|\n\r");
    PrintString(" | |  | |_ __   ___ _ __ | |  | | (___  \n\r");
    PrintString(" | |  | | '_ \\ / _ \\ '_ \\| |  | |\\___ \\ \n\r");
    PrintString(" | |__| | |_) |  __/ | | | |__| |____) |\n\r");
    PrintString("  \\____/| .__/ \\___|_| |_|\\____/|_____/ \n\r");
    PrintString("        | |                               \n\r");
    PrintString("        |_|                                \n\r");
	PrintVersion();
	PrintString("Copyright (c) 2023 MadMushroom\n\r");
    PrintString("------------------------------------------\n\n\r");
}

void init(){
	InitializeIDT();
	MainKeyboardHandler = KeyboardHandler;
	initShell();
}

extern "C" void _start() {
	BootScreen();
	init();
	StartScreen();
	RunShell();

	return;
}
