/* OpenOS IO
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "../../Kernel.h"
#include "../../driver/VGA_Screen.cpp"

struct MemoryMapEntry {
    uint_64 BaseAddress;
    uint_64 RegionLength;
    uint_32 RegionType;
    uint_32 ExtendedAttributes;
};

extern uint_8 MemoryRegionCount;
extern uint_8 UsableMemoryRegionsCount;

void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position = CursorPosition);
MemoryMapEntry** GetUsableMemoryRegions();