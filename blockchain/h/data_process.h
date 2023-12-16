#ifndef MY_BLOCKCHAIN_H_DATA_PROCESS_H_
#define MY_BLOCKCHAIN_H_DATA_PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "./convertor.h"
#include "./structures.h"

int node_length(node*);
int block_length(block*);
int is_there_node(node*, int);
int is_there_block(block*, int);
int is_contain(node*, int, int);
void write_data(node* node_);
void error_message(int flag);

#endif