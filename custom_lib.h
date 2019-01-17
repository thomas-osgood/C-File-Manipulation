/* Custom_Lib.h
 * 
 * Author: Thomas Osgood
 * Email: github.com/thomas-osgood
 * Purpose:
 * 	Centralize useful functions and macro definitions.
 * 	Helps minimize functions inside main.c and streamlines code.
 * 
 * Note:
 * Requres "read_file.c", "read_input.c" and any other included ".c"
 * file be located in the same directory as this header file.
 * 
 * For additional help with functions, please read the function descriptions
 * and documentation in the ".c" files the functions are located in.
 * 
 * To Use Library:
 * 	#include "custom_lib.h" // add to the 'include' block in main.c
 * 
 * GNU GPL Reference
 * --------------------------------------------------------------------
 * Copyright 2015 thomas osgood <github.com/thomas-osgood>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * --------------------------------------------------------------------
 */

#ifndef custom_lib
#define custom_lib

/* Custom Includes */
#include "custom_lib.h"
#include "read_input.c"
#include "read_file.c"
#include "memory_functions.c"
#include <time.h>

/* Macro Definitions */
/* Author Info Macros */
#define CL_AUTHOR "Thomas Osgood\n"
#define CL_AUTHOR_EMAIL "tosgood1@gmail.com\n"
#define CL_VERSION "Osgood Custom Lib V1.0\n"

/* Misc Macros */
#define KILOBYTE 1024
#define SQUARE_NUM(x) x*x
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))
#define TO_NEGATIVE(x) ((-1)*x)

/* Timing Macros */
#define CALCULATE_TIME(start,end) ((double)(end-start))/CLOCKS_PER_SEC
#define SEC_TO_MILSEC(x) x*1000
#define SEC_TO_USEC(x) x*1000*1000
#define MSEC_TO_USEC(x) x*1000

/* Check For OS And Adjust Accordingly
 * 
 * This 'ifdef' block allows for a
 * time delay to be implemented.
 * 
 * For Windows, turns time delay into
 * seconds.
 * 
 * For Linux, keeps delay as seconds.
 */
#ifdef _WIN32
	/* If Windows: Turn Delay Into Seconds */
	#include <windows.h>
	#define DELAY(x) Sleep(1000 * x)
#else
	/* If Linux, Keep Delay Same */
	#include <unistd.h>
	#define DELAY(x) sleep(x)
#endif

/* Function Prototypes */

/* Reading Input 
 * 
 * The following functinos deal with reading input
 * from the user.
 * 
 * The 'Read_Input' function calls 'Clear_Var' function.
 */
extern void Clear_Var(char *buff, int buff_len);
extern void Read_Input(char *buff, int buff_len);
extern void To_Title(char *buff, int buff_len);

/* File Manipulation 
 * 
 * The following functions deal with manipulating files.
 * Allows user to copy, append, write, etc.
 */
extern void Append_File(char *filename, char *fileinfo);
extern int Compare_File(char *file1, char *file2);
extern void Copy_File(char *filename, char *newname);
extern int Get_Line_Count(char *filename);
extern void Overwrite_Pos(char *filename, long position, char *string, int string_length, int offset);
extern char *Read_File(char *filename);
extern int Read_Size(char *filename);
extern void Write_File(char *filename, char *fileinfo);

/* Memory Functions
 * 
 * The following functions deal with memory.
 */
extern void Print_Addresses(void *var_list[], int length);
extern void Dump_Memory();

#endif
