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
        // Variables
        const char* Username;
        bool initialized = false;

        // Functions
        void init();
        void run();
};

void Shell::init(){
    malloc(sizeof(Shell));
    Username = "user";
    initialized = true;
}

void Shell::run(){
    if(!initialized){ ncErr("Shell not initialized!\nCannot run Shell!\n\nRebooting might solve this Error."); return; }
    PrintString(Username);
    PrintString(">");
}