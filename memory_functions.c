/*
 * memory_functions.c
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
#include <stdio.h>
#include <stdlib.h>

/* Print Addresses Function
 * 
 * Takes an array of variable addresses and
 * prints the addresses to the screen in 0xNN form
 */
void Print_Addresses(void *var_list[], int length) {
	int i = 0;
	for (i = 0; i < length; i++) {
		printf("Variable: %p\n", var_list[i]);
	}
	printf("\n");
}

/* Dump Memory Function */
void Dump_Memory() {
	char user_input[] = "\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\\r%s\n\r%s\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\
	\r%s\n\r%s\n\r%s\n\r%s\n\r%s\n\n";
	printf(user_input);
	printf("%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\
	\r%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n%08x   %08x   %08x   %08x  %08x\n\n");
}
