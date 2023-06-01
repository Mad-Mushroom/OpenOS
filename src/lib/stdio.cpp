/* OpenOS stdio
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"

void printf(const char* str, uint_8 color = DEFAULT_BACKGROUND | DEFAULT_FOREGROUND){
    //if(CursorPosition > VGA_WIDTH * (VGA_HEIGHT - 1)) Scroll(1);
    PrintString(str, color);
}