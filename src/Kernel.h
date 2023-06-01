/* OpenOS Kernel
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

void shutdown();

/* Misc */
#include "misc/OS_Info.h"
#include "misc/KBScanCodeSet1.cpp"
#include "misc/TextModeColorCodes.cpp"
#include "misc/Typedefs.cpp"

/* System */
#include "system/IO.cpp"
#include "system/IDT.cpp"

/* Driver */
#include "driver/VGA_Screen.cpp"
#include "driver/Keyboard.cpp"

/* Librarys */
#include "lib/string.cpp"
#include "lib/stdio.cpp"

/* Shell */
#include "shell/shell.cpp"