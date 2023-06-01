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
	PrintString("Starting OpenOS...", BACKGROUND_BLACK | FOREGROUND_WHITE);
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
	if(VERBOSE == true) PrintString("\n\n\rInitialized Verbose Mode.");
	InitializeIDT();
	if(VERBOSE == true) PrintString("\n\rInitialized IDT.");
	MainKeyboardHandler = KeyboardHandler;
	if(VERBOSE == true) PrintString("\n\rInitialized Keyboard Handler.");
	initShell();
	if(VERBOSE == true) PrintString("\n\rInitialized Shell.");
	if(VERBOSE == true) PrintString("\n\n\rDone.");
}

void shutdown(){
	ClearScreen(BACKGROUND_BLACK | FOREGROUND_YELLOW);
	SetCursorPosition(PositionFromCoords(VGA_WIDTH/2-(33/2)-1, VGA_HEIGHT/2));
	PrintString("It's safe to turn off the PC now.", BACKGROUND_BLACK | FOREGROUND_YELLOW); // 33
	SetCursorPosition(PositionFromCoords(VGA_WIDTH/2-(14/2)-1, VGA_HEIGHT-1));
	PrintString("System halted.", BACKGROUND_BLACK | FOREGROUND_RED);
	SetCursorPosition(VGA_HEIGHT * VGA_WIDTH);
	while(true) asm("hlt");
}

extern "C" void _start() {
	BootScreen();
	init();
	StartScreen();
	RunShell();

	return;
}
