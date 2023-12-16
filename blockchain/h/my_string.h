#ifndef BLOCKCHAIN_H_MY_STRING_H_
#define BLOCKCHAIN_H_MY_STRING_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "./structures.h"

int my_strlen(char*);
int my_strcmp(char*, char*);
int find_pieces(char*, char);
int pieces_len(int, char*, char);
char* my_scanf();
char* my_strdup(char*);
void f_delete_space(char*);
void fill_null(char*, int);
str_array* split(char*, char);

#endif