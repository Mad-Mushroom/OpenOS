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
    uint_8 index = 0;
    uint_8 result;
    while(*charPtr != 0){
        if(arr[index] == *charPtr){
            result++;
        }
        index++;
        charPtr++;
    }
    if(result == len){
        result = 0;
        return true;
    }
    else{
        result = 0;
        return false;
    }
}