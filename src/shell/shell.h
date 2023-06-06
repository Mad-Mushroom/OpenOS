/* OpenOS Shell
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

/*#pragma once

#include "../Kernel.h"
#include "../lib/string.h"
#include "../lib/stdio.h"
#include "../driver/VGA_Screen.h"

class Shell {
    public:
        const char* Username;
        char command_buffer[256];
        uint_8 bufferSize;
        uint_8 isRunning;
};

void initShell();
void shutdownShell();
void displayHelp();
void displayDevHelp();
void info(char* argument);
void RunShell();
void ParseCommand();
void Shell_EnterPressed();
void Shell_BackspacePressed();
void Shell_UpPressed();
void Shell_AddChar(char chr);*/