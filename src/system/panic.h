/* OpenOS Panic
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"

#define pVGA_MEMORY (char*)0xb8000
#define pVGA_WIDTH 80
#define pVGA_HEIGHT 25

typedef unsigned char uint_8;
typedef unsigned short uint_16;
typedef unsigned int uint_32;
typedef unsigned long long uint_64;

void kpanic(const char* msg);