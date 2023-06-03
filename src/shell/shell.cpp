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
    printf("\n== OpenOS Help ==\n\n");
    printf("info - information about OS\n");
    printf("clear - clears screen\n");
    printf("shutdown - shutdown PC\n");
    printf("help - display this text\n");
    
    if(VERBOSE) printf("\nAren't you a Dev?\n");
}

void displayDevHelp(){
    printf("\n== OpenOS Dev Help ==\n\n");
    printf("scroll - scroll 1 time\n");
    printf("devhelp - display this text\n");
    
    if(!VERBOSE) printf("\nHow do you now?\n");
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

    if(VERBOSE) PrintString("\n");
    while(shell.command_buffer[index] != 0){
        if(shell.command_buffer[index] == ' '){ args++; index++; }
        else{ arguments[args][index] = shell.command_buffer[index]; }
        if(VERBOSE) PrintChar(shell.command_buffer[index]);
        if(VERBOSE) PrintString(" - ");
        if(VERBOSE) PrintChar(arguments[args][index]);
        if(VERBOSE) PrintString("\n");
        index++;
    }

    if(arguments[0][0] == 0){ }
    /* User Commands */
    else if(char_contains(arguments[0], "clear")){ ClearScreen(); }
    else if(char_contains(arguments[0], "info")){ printf("\n"); PrintVersion(true); }
    else if(char_contains(arguments[0], "shutdown")){ shutdown(); }
    else if(char_contains(arguments[0], "help")){ displayHelp(); }
    else if(char_contains(arguments[0], "echo")){ printf("\n"); for(int i=1; i<args; i++){ printf(arguments[i]); } }
    else if(char_contains(arguments[0], "lines")){ printf("\n"); printf("Total lines of code: "); printf(TOTAL_LINES); printf("\n"); }
    else if(char_contains(arguments[0], "license")){ printf("\n"); license(); }
    /* Dev Commands */
    else if(char_contains(arguments[0], "devhelp")){ displayDevHelp(); }
    else if(char_contains(arguments[0], "scroll")){ Scroll(1); }
    else if(char_contains(arguments[0], "template")){ printf("\n"); printf("You discovered a Easter Egg!\n"); }
    /* Error Messages */
    else { printf("\n\rCould not find command '"); printf(arguments[0]); printf("'!\n"); }
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