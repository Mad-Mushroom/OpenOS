/* OpenOS Kernel
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#include "Kernel.h"

extern const char Logo[];
extern const char License[];
extern const char Alpha[];
extern const char BetaFish[];

void BootScreen(){
	ClearScreen(BACKGROUND_BLACK | FOREGROUND_WHITE);
	SetCursorPosition(0);
	PrintString("Starting OpenOS...", BACKGROUND_BLACK | FOREGROUND_WHITE);
}

void StartScreen(){
	ClearScreen(DEFAULT_BACKGROUND | DEFAULT_FOREGROUND);
	SetCursorPosition(0);
    /*PrintString("   ____                    ____   _____ \n");
    PrintString("  / __ \\                  / __ \\ / ____|\n");
    PrintString(" | |  | |_ __   ___ _ __ | |  | | (___  \n");
    PrintString(" | |  | | '_ \\ / _ \\ '_ \\| |  | |\\___ \\ \n");
    PrintString(" | |__| | |_) |  __/ | | | |__| |____) |\n");
    PrintString("  \\____/| .__/ \\___|_| |_|\\____/|_____/ \n");
    PrintString("        | |                               \n");
    PrintString("        |_|                                \n");*/
	PrintString(Logo);
	PrintVersion();
	PrintString("Copyright (c) 2023 MadMushroom\n");
    if(LIGHT) PrintString("------------------------------------------\n\n");
	if(!LIGHT) PrintString(Alpha);
}

void ALPHA(){
	PrintString(Alpha);
}

void BETA(){
	PrintString(BetaFish);
}

void init(){
	if(VERBOSE == true) PrintString("\n\nInitialized Verbose Mode.");
	InitializeIDT();
	if(VERBOSE == true) PrintString("\nInitialized IDT.");
	MainKeyboardHandler = KeyboardHandler;
	if(VERBOSE == true) PrintString("\nInitialized Keyboard Handler.");
	initShell();
	if(VERBOSE == true) PrintString("\nInitialized Shell.");
	if(VERBOSE == true) PrintString("\n\nDone.");
}

void shutdown(bool noShowMode){
	shutdownShell();
	if(!noShowMode) ClearScreen(BACKGROUND_BLACK | FOREGROUND_YELLOW);
	if(!noShowMode) SetCursorPosition(PositionFromCoords(VGA_WIDTH/2-(33/2)-1, VGA_HEIGHT/2));
	if(!noShowMode) PrintString("It's safe to turn off the PC now.", BACKGROUND_BLACK | FOREGROUND_YELLOW); // 33
	if(!noShowMode) SetCursorPosition(PositionFromCoords(VGA_WIDTH/2-(14/2)-1, VGA_HEIGHT-1));
	if(!noShowMode) PrintString("System halted.", BACKGROUND_BLACK | FOREGROUND_RED);
	SetCursorPosition(VGA_HEIGHT * VGA_WIDTH);
	while(true) asm("hlt");
}

void license(){
	PrintString(License);
}

extern "C" void _start() {
	BootScreen();
	init();
	StartScreen();
	RunShell();

	return;
}
