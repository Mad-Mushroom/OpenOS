/* OpenOS IDT
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"
#include "../driver/VGA_Screen.cpp"

struct IDT64{
  uint_16 offset_low;
  uint_16 selector;
  uint_8 ist;
  uint_8 types_attr;
  uint_16 offset_mid;
  uint_32 offset_high;
  uint_32 zero;
};

void InitializeIDT();
extern void(*MainKeyboardHandler)(uint_8 scanCode, uint_8 chr);