/* OpenOS Shell
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#include "../Kernel.h"

class Shell {
    public:
        const char* Username;
};
Shell shell;

void initShell(){
    shell.Username = "user";
}

void RunShell(){
    PrintString(shell.Username);
    PrintString("> ");
}