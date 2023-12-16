#ifndef BLOCKCHAIN_H_REMOVE_H_
#define BLOCKCHAIN_H_REMOVE_H_

#include <stdlib.h>

#include "./structures.h"
#include "./data_process.h"

void deallocate(node* head);
void deallocate_blocks(block* head);
void eliminate_node(node** head, int id);
void deallocate_str_array(str_array* s_array);
void rm_all_blocks_of_node(node** head, int id);
void command_rm(str_array* pars_input, node** head);
void sort_eliminate(node** head, int block_id, int node_id);
int rm_blocks(node* head, int block_id);
int eliminate_block(block** head, int id);

#endif