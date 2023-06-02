/* OpenOS Shell
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"
#include "../lib/string.cpp"
#include "../lib/stdio.cpp"

class Shell {
    public:
        const char* Username;
        char command_buffer[128];
        uint_8 bufferSize;
};
Shell shell;

void initShell(){
    shell.Username = "User";
}

void displayHelp(){
    printf("\n\r== OpenOS Help ==\n\n\r");
    printf("info - information about OS\n\r");
    printf("clear - clears screen\n\r");
    printf("shutdown - shutdown PC\n\r");
    printf("help - display this text\n\r");
    
    if(VERBOSE) printf("\n\rAren't you a Dev?\n\r");
}

void displayDevHelp(){
    printf("\n\r== OpenOS Dev Help ==\n\n\r");
    printf("scroll - scroll 1 time\n\r");
    printf("devhelp - display this text\n\r");
    
    if(!VERBOSE) printf("\n\rHow do you now?\n\r");
}

void RunShell(){
    printf(shell.Username);
    printf("> ");
}

void ParseCommand(){
    //char command[128];
    char arguments[8][16];
    uint_8 args;
    uint_8 index;

    while(shell.command_buffer[index] != 0){
        if(shell.command_buffer[index] == ' '){ args++; index++; }
        else{ arguments[args][index] = shell.command_buffer[index]; }
        index++;
    }

    if(arguments[0][0] == 0){ }
    /* User Commands */
    else if(char_contains(arguments[0], "clear")){ ClearScreen(); }
    else if(char_contains(arguments[0], "info")){ printf("\n\r"); PrintVersion(true); }
    else if(char_contains(arguments[0], "shutdown")){ shutdown(); }
    else if(char_contains(arguments[0], "help")){ displayHelp(); }
    else if(char_contains(arguments[0], "echo")){ printf("\n\r"); for(int i=1; i<args; i++){ printf(arguments[i]); } }
    else if(char_contains(arguments[0], "lines")){ printf("\n\r"); printf("Total lines of code: "); printf(TOTAL_LINES); printf("\n\r"); }
    /* Dev Commands */
    else if(char_contains(arguments[0], "devhelp")){ displayDevHelp(); }
    else if(char_contains(arguments[0], "scroll")){ Scroll(1); }
    else if(char_contains(arguments[0], "template")){ printf("\n\r"); printf("You discovered a Easter Egg!\n\r"); }
    /* Error Messages */
    else { printf("\n\rCould not find command '"); printf(arguments[0]); printf("'!\n\r"); }
    for(int i=0; i<128; i++) arguments[0][i] = 0;
    args = 0;
    index = 0;
    return;
}

void Shell_EnterPressed(){
    if(CursorPosition > VGA_WIDTH * (VGA_HEIGHT - 1) && !LIGHT) Scroll(1);
    if(CursorPosition > VGA_WIDTH * (VGA_HEIGHT - 1) && LIGHT) ClearScreen();
    ParseCommand();
    shell.bufferSize = 0;
    for(int i=0; i<128; i++) shell.command_buffer[i] = 0;
    printf("\n\r");
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