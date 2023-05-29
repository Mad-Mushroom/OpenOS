/* OpenOS Shell
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"

class Shell {
    public:
        const char* Username;
        char command_buffer[128];
        uint_8 bufferSize;
};
Shell shell;

void initShell(){
    shell.Username = "user";
}

void RunShell(){
    PrintString(shell.Username);
    PrintString("> ");
}

void ParseCommand(){
    char command[128];
    uint_8 args;
    uint_8 index;
    while(shell.command_buffer[index] != 0 && shell.command_buffer[index] != ' ' && args == 0){
        command[index] = shell.command_buffer[index];
        index++;
    }args++;

    if(char_contains(command, 5, "clear")) ClearScreen();
    else { PrintString("\n\rCould not find command '"); PrintString(command); PrintString("'!\n\r"); }
    for(int i=0; i<128; i++) command[i] = 0;
    return;
}

void Shell_EnterPressed(){
    ParseCommand();
    shell.bufferSize = 0;
    for(int i=0; i<128; i++) shell.command_buffer[i] = 0;
    PrintString("\n\r");
    RunShell();
}

void Shell_BackspacePressed(){
    if(shell.bufferSize > 0){
        SetCursorPosition(CursorPosition - 1);
	    PrintChar(' ');
	    SetCursorPosition(CursorPosition - 1);
        shell.command_buffer[shell.bufferSize] = 0;
        shell.bufferSize--;
    }
}

void Shell_AddChar(char chr){
    shell.command_buffer[shell.bufferSize] = chr;
    shell.bufferSize++;
}