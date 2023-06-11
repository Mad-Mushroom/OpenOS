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
        char commandBuffer[512];
        uint_16 bufferSize;
};
Shell shell;

void initShell(){
    malloc(sizeof(shell));
    shell.Username = "user";
}

void RunShell(){
    PrintString(shell.Username);
    PrintString("> ");
}

void ParseCommand(){
    char arguments[16][32];
    uint_16 index;
    uint_16 index2;
    uint_8 args;

    while(shell.commandBuffer[index] != 0){
        if(shell.commandBuffer[index] == ' '){ args++; index++; index2 = 0; }
        else { arguments[args][index2] = shell.commandBuffer[index]; index++; index2++; }
    }

    
}

void Shell_EnterPressed(){
    
}