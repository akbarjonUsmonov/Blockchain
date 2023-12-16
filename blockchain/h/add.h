#ifndef BLOCKCHAIN_H_ADD_H_
#define BLOCKCHAIN_H_ADD_H_

#include <stdlib.h>

#include "./structures.h"
#include "./data_process.h"
#include "./remove.h"

void add_node(int id, node** head);
void add_block(int id, block** head);
void command_add(str_array* pars_input, node** head);
void add_node_and_block(node** node_, str_array* arr);
void add_blocks_to_all(node** head, int block_id, int node_id, int flag);

#endif