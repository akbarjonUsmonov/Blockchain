#ifndef BLOCKCHAIN_H_SYNC_H_
#define BLOCKCHAIN_H_SYNC_H_

#include <stdio.h>

#include "./add.h"
#include "./my_string.h"
#include "./structures.h"
#include "./data_process.h"

int sync_check(node* head);
void sync_for_blockchain(node*);

#endif