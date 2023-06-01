/* OpenOS Shell
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"
#include "../lib/string.cpp"

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
    //char command[128];
    char arguments[8][16];
    uint_8 args;
    uint_8 index;
    /*while(shell.command_buffer[index] != 0 && shell.command_buffer[index] != ' ' && args == 0){
        command[index] = shell.command_buffer[index];
        index++;
    }args++;*/
    while(shell.command_buffer[index] != 0){
        if(shell.command_buffer[index] == ' '){ args++; }
        else arguments[args][index] = shell.command_buffer[index];
        index++;
    }
    

    if(char_contains(arguments[0], 5, "clear")){ ClearScreen(); }
    else if(char_contains(arguments[0], 4, "info")){ PrintString("\n\r"); PrintVersion(); }
    else if(char_contains(arguments[0], 8, "template")){ PrintString("\n\r"); PrintString("You discovered a Easter Egg!\n\r"); }
    else if(char_contains(arguments[0], 8, "shutdown")){ shutdown(); }
    else if(char_contains(arguments[0], 4, "help")){ PrintString("\n\r== OpenOS Help ==\n\n\rinfo - information about OS\n\rclear - clears screen\n\rshutdown - shutdown PC\n\rhelp - display this text\n\r"); }
    else if(char_contains(arguments[0], 4, "echo")){ for(int i=1; i<args; i++){ PrintString(arguments[i]); } PrintString("\n\r"); }
    else { PrintString("\n\rCould not find command '"); PrintString(arguments[0]); PrintString("'!\n\r"); }
    for(int i=0; i<128; i++) arguments[0][i] = 0;
    args = 0;
    index = 0;
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