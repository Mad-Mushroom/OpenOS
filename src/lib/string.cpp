/* OpenOS Kernel
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"

bool char_contains(char arr[], uint_8 len, const char* ch){
    if(len <= 0) return false;
    char cch[len];
    uint_8* charPtr = (uint_8*)ch;
    uint_16 index = 0;
    uint_8 result;
    while(*charPtr != 0){
        cch[index] = *charPtr;
        index++;
        charPtr++;
    }
    for(int i=0; i<len; i++){
        if(arr[i] == cch[i]){
            result++;
        }
    }
    if(result >= len) return true;
    else return false;
}