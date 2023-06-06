/* OpenOS VGA Screen Driver
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../Kernel.h"
#include "../system/IO.h"

#define VGA_MEMORY (char*)0xb8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

extern uint_16 CursorPosition;

void SetCursorPosition(uint_16 position);
void ClearScreen(uint_64 ClearColor = DEFAULT_BACKGROUND | DEFAULT_FOREGROUND);
uint_16 PositionFromCoords(uint_8 x, uint_8 y);
void PrintChar(char chr, uint_8 color = DEFAULT_BACKGROUND | DEFAULT_FOREGROUND);
void Scroll(int lines);
void PrintString(const char* str, uint_8 color = DEFAULT_BACKGROUND | DEFAULT_FOREGROUND);
void PrintVersion(bool detailed = false);
const char* FloatToString(float value, uint_8 decimalPlaces);

const char* HexToString(uint_8 value);
const char* HexToString(uint_32 value);
const char* HexToString(uint_64 value);
const char* HexToString(uint_16 value);
const char* HexToString(char value);
const char* HexToString(short value);
const char* HexToString(int value);
const char* HexToString(long long value);

const char* IntegerToString(uint_8 value);
const char* IntegerToString(uint_32 value);
const char* IntegerToString(uint_64 value);
const char* IntegerToString(uint_16 value);
const char* IntegerToString(char value);
const char* IntegerToString(short value);
const char* IntegerToString(int value);
const char* IntegerToString(long long value);