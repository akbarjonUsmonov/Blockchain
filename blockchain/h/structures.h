#ifndef MY_BLOCKCHAIN_H_STRUCTURES_H_
#define MY_BLOCKCHAIN_H_STRUCTURES_H_

typedef struct s_block
{
    int block_id;
    struct s_block* next;
} block;

typedef struct s_node
{
    int node_id;
    struct s_block* blocks;
    struct s_node* next;
} node;

typedef struct s_string_array
{
    int count;
    char** array;
} str_array;

#endif