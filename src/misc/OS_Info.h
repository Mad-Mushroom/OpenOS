/* OpenOS OS Info
 *
 * Made by MadMushroom
 * 
 * Copyright (c) 2023 MadMushroom
 */

#pragma once

#define VERBOSE true

#define VERSION "OpenOS Alpha [v0.5.9.6]"

#if VERBOSE == true
#define SVERSION "Dev Edition\n\r"
#endif
#if VERBOSE == false
#define SVERSION ""
#endif

#define DEFAULT_BACKGROUND BACKGROUND_BLUE
#define DEFAULT_FOREGROUND FOREGROUND_WHITE