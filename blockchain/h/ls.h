#ifndef BLOCKCHAIN_H_LS_H_
#define BLOCKCHAIN_H_LS_H_

#include <stdio.h>

#include "./structures.h"
#include "./my_string.h"
#include "./remove.h"

void ls_for_blockchain(node** node_, int flag);
void command_ls(str_array* pars_input, node** head);

#endif