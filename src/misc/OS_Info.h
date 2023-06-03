/* OpenOS OS Info
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#include "build.h"

#define VERBOSE false
#define LIGHT false

#define OS_VERSION "OpenOS Alpha [v0.5.9.7]"
#define SHELL_VERSION "Shell [v0.6.2]\n\r"
#define BUILD_VERSION BUILD_NUMBER // Month;Day;Year;BuildNumber

#if VERBOSE == true
#define SVERSION "Dev Edition\n\r"
#endif
#if LIGHT == true
#define SVERSION "Light Edition\n\r"
#endif
#if VERBOSE == false && LIGHT == false
#define SVERSION "\n\r"
#endif

#define DEFAULT_BACKGROUND BACKGROUND_BLUE
#define DEFAULT_FOREGROUND FOREGROUND_WHITE