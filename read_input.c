/*
 * read_input.c
 * 
 * Copyright 2015 thomas <github.com/thomas-osgood>
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

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function Prototypes */
void Read_Input(char *buff, int buff_len);
void Clear_Var(char *buff, int buff_len);
void To_Title(char *buff, int buff_len);

/* Clear Variable Function
 *  Clears the variable for Read Input function
 *  Pass char* variable by reference
 */
void Clear_Var(char *buff, int buff_len) {
	int i = 0;
	
	for (i=0; i < buff_len; i++) {
		buff[i] = '\0';
	}
}

/* Read Input Function
 * Pass char* variable by reference
 * Fills buffer with user input.
 * Protects Against Buffer Overflows.
 */
void Read_Input(char *buff, int buff_len) {
	int i = 0;
	char ch;
	
	Clear_Var(buff, buff_len);
	
	while( ((ch = getchar()) != '\n' ) && (i < buff_len)) {
		buff[i] = ch;
		i++;
		if (i == buff_len) {
			buff[i] = '\n';
		}
	}
}

/* To Title Function
 * Converts string to title case
 * Pass char* variable by reference.
 */
void To_Title(char *buff, int buff_len) {
	int i = 0;
	
	buff[0] = toupper(buff[0]);
	
	for (i = 0; i < buff_len; i++) {
		if (buff[i] == ' ' && buff[i+1] != ' ') {
			buff[i+1] = toupper(buff[i+1]);
		}
	}
}

