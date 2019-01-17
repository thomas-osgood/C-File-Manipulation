/*
 * read_file.c
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

/* Standard Includes */
#include <stdio.h>
#include <stdlib.h>

/* Macro Definitions */
#define LINE_SIZE 1024

/* Function Prototypes */
void Append_File(char *filename, char *fileinfo);
int Compare_File(char *file1, char *file2);
void Copy_File(char *filename, char *newname);
char *Read_File(char *filename);
int Read_Size(char *filename);
void Write_File(char *filename, char *fileinfo);
/* void Get_Line_Count(); */
/* void Read_File_By_line(); */

/*------------ Function Definitions ------------*/

/* Append File Function
 *  Writes information to file
 *  Uses 'a' not 'w'
 *  Append information to file,
 */
void Append_File(char *filename, char *fileinfo) {
	FILE *fp = fopen(filename, "a");
	fprintf(fp,"%s\n",fileinfo);
	fclose(fp);
}

/* Compare File Function
 *  Reads sizes of two files
 *  Compares the sizes
 * Return 0 if equal
 * Return 1 if F1 > F2
 * Return -1 if F1 < F2
 * Return -5 if ERROR
 */
int Compare_File(char *file1, char *file2) {
	int result = 0;
	int f1size = 0;
	int f2size = 0;
	
	f1size = Read_Size(file1);
	f2size = Read_Size(file2);
	
	if (f1size == f2size) {
		result = 0;
	} else if (f1size > f2size) {
		result = 1;
	} else if (f1size < f2size) {
		result = -1;
	} else {
		result = -5;
	}
	
	return result;
}

/* Copy File Function
 * Copys all data from 'filename'
 * Creates new file with 'newname'
 */
void Copy_File(char *filename, char *newname) {
	int fsize = Read_Size(filename);
	char *data = (char *) malloc (fsize * sizeof(char));
	
	data = Read_File(filename);
	Write_File(newname,data);
	free(data);
}

/* Get Line Count Function
 * Function to count the number of lines in a file.
 * Input: filename
 * Returns: Line Count
 */
int Get_Line_Count(char *filename) {
	int count = 0;
	int i = 0;
	char ch;
	char *line = (char *) malloc (LINE_SIZE * sizeof(char));
	FILE *fp;	
	
	/* Clear LINE Variable */
	for (i = 0; i < LINE_SIZE; i++) {
		line[i] = '\0';
	}
	i = 0;
	
	/* Open File For Reading */
	fp = fopen(filename,"r");
	
	/* Read And Count Each Line & Increment Count Variable */
	while ((ch = fgetc(fp)) != EOF) {
		if ((i != LINE_SIZE)) {
			line[i] = ch;
			i++;
			if (ch == '\n') {
				i = 0;
				count++;
			}
		}
	}
	
	/* Close File */
	fclose(fp);
	
	free(line);
	
	return count;
}

/* Overwrite Position Function
 * Overwrites file at location specified with
 * the string passed to function.
 * 
 * Please use this legally. 
 * This has the potential to be used 
 * malliciously (injecting malicious code into files).
 * 
 * Note:
 * For 'position' use the FSEEK options:
 * 	[
 * 	SEEK_SET, -> 0
 * 	SEEK_CUR, -> 1
 * 	SEEK_END, -> 2
 * 	SEEK_DATA, -> 3
 * 	SEEK_HOLE, -> 4
 * 	]
 * 	- SEEK_DATA and SEEK_HOLE do not work on certain systems
 */
 void Overwrite_Pos(char *filename, long position, char *string, int string_length, int offset) {
	 FILE *fp;
	 fp = fopen(filename,"r+");
	 fseek(fp, offset, position);
	 fwrite(string, sizeof(string[0]), string_length, fp);
	 fclose(fp);
 }

/* Read File Function
 * Reads file information into buffer
 * Reads size of file and allocates
 * enough memory.
 */
char *Read_File(char *filename) {
	int BUFFERSIZE = Read_Size(filename);
	char *BUFFER = (char *) malloc (BUFFERSIZE * sizeof(char));
	char c;
	FILE *fp;
	int i = 0;
	
	fp = fopen(filename, "r");
	
	while(((c = fgetc(fp)) != '\0') && (i < BUFFERSIZE)) {
		BUFFER[i]  = c;
		i++;
	}
	
	fclose(fp);
	return BUFFER;
}

/* Read Size Function
 *  Reads file size (bytes) 
 *  Returns size as int
 */
int Read_Size(char *filename) {
	int filesize = 0;
	FILE *fp;
	
	fp = fopen(filename,"r");
	fseek(fp, 0, SEEK_END);
	filesize = ftell(fp);
	fclose(fp);
	
	return filesize;
}

/* Write File Function
 *  Writes information to file
 *  Uses 'w' not 'a'
 *  Does not append information to file,
 *  creates a new file.
 */
void Write_File(char *filename, char *fileinfo) {
	FILE *fp = fopen(filename, "w");
	fprintf(fp,"%s",fileinfo);
	fclose(fp);
}



