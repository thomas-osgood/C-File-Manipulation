/*
 * test.c
 * 
 * Copyright 2016 thomas <github.com/thomas-osgood>
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
 * 
 * 
 */

/* Include Standard Headers */
#include <stdio.h>
#include <stdlib.h>

/* Include String Library */
#include <string.h>

/* Include Timing Library */
#include <time.h>

/* Include Custom Header */
#include "custom_lib.h"

int main(void)
{
	/* Variable Declarations And Initializations */
	char *textInput =  (char *) malloc ((50 * sizeof(char)) + sizeof(char));
	char *fileInfo = (char *) malloc (KILOBYTE * sizeof(char));
	static char *virusText = ".............. THIS FILE HAS BEEN CORRUPTED ..............\n";
	int fsize = 0;
	int txtSize = strlen(virusText);
	
	int txtOffset = 0;
	
	int numDub = 0;
	int num = 0;
	
	long start_pos = SEEK_SET;
	
	/* Clocking Variables */
	clock_t start, end;
	double elapsed = 0;
	
	/* Memory Manipulation Variables */
	void *var_addrs[] = {
		&textInput,
		&fileInfo,
		&fsize,
		&numDub,
		&num,
		&start,
		&end,
		&elapsed
		};
	static int arr_size = ARRAY_SIZE(var_addrs);
	
	/* Display HEX Address Of Each Variable In Array */
	Print_Addresses(var_addrs,arr_size);
	
	/* Begin User Interaction */
	printf("Enter Name: ");
	Read_Input(textInput, 51);
	printf(">>> USER INPUT: %s\n",textInput);
	To_Title(textInput, strlen(textInput));
	printf(">>>TO TILE INPUT: %s\n", textInput);
	printf(">>> &textInput ADDRESS [ HEX ]: %p\n",&textInput);
	
	printf("\nEnter Number: ");
	Read_Input(textInput,5);
	
	/* Convert Input To Integer And Multiply By Two */
	num = atoi(textInput);
	numDub = num * 2;
	
	printf(">>> NUMBER INPUT: %d\n",num);
	printf(">>> NUMBER DOUBLED: %d\n", numDub);
	
	Copy_File("test.c","test_copy.txt");
	
	printf("STARTING DELAY ...\n");
	DELAY(1);
	printf("DELAY OVER ...\n");
	
	/* Reallocate Memory For FileInfo Variable
	 *  Reads size of file and resizes memory allocation.
	 * 
	 *  Printf statement prints file info to screen.
	 * 
	 * Time how long it takes to read size and data from file.
	 */
	 start = clock();
	 
	fsize = Read_Size("custom_lib.h");
	fileInfo = realloc (fileInfo, fsize);
	fileInfo = Read_File("custom_lib.h");
	
	end = clock();
	elapsed = CALCULATE_TIME(start,end);
	
	printf("FILE INFO:\n%s\n",fileInfo);
	
	printf("\n>>> TIME TO READ FILE SIZE AND CONTENTS: %f seconds\n", elapsed);
	printf(">>> TIME IN MILLISECONDS: %f\n", SEC_TO_MILSEC(elapsed));
	
	txtOffset = rand() % (Read_Size("test_copy.txt") - txtSize);
	Overwrite_Pos("test_copy.txt", start_pos, virusText, txtSize, txtOffset);
	printf("\n\n%s\n\n",Read_File("test_copy.txt"));
	
	/* Deallocate Allocated Memory */
	free(textInput);
	free(fileInfo);
	
	printf("\nNumber Of Lines In TEST.C: %d\n", Get_Line_Count("test.c"));
	/* Test Of The DUMP MEMORY Function */
	Dump_Memory();
	
	char test[] = "%08x   %08x   %08x\n\n%s\n";
	printf(test);
	
	/* Return Successfully: Exit With Code 0 */
	return 0;
}

