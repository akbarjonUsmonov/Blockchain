#include "../h/data_process.h"

int block_length(block* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    block* tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

int node_length(node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 0;
    node* tmp = head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

int is_there_node(node* head, int id)
{
    node* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->node_id == id)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int is_there_block(block* head, int id)
{
    block* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->block_id == id)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int is_contain(node* head, int node_id, int block_id)
{
    node* current = head;
    while (current != NULL)
    {
        if (current->node_id == node_id)
        {
            if (is_there_block(current->blocks, block_id) == 1)
            {
                return 1;
            }
        }

        current = current->next;
    }
    return 0;
}

void write_data(node* node_)
{
    int fd = open("blockchain_data", O_WRONLY | O_TRUNC);
    if (node_ == NULL)
    {
        close(fd);
        return;
    }
    char* buffer_node;
    char* buffer_block;
    node* head = node_;
    block* head_block = head->blocks;
    while (head != NULL)
    {
        buffer_node = calloc(sizeof(char), 11);
        my_itoa(head->node_id, buffer_node);
        write(fd, buffer_node, my_strlen(buffer_node));
        head_block = head->blocks;
        while (head_block != NULL)
        {
            buffer_block = calloc(sizeof(char), 11);
            my_itoa(head_block->block_id, buffer_block);
            write(fd, ",", 1);
            write(fd, buffer_block, my_strlen(buffer_block));
            free(buffer_block);
            head_block = head_block->next;
        }
        if (head->next != NULL)
        {
            write(fd, "\n", 1);
        }
        free(buffer_node);
        head = head->next;
    }
    close(fd);
}

void error_message(int flag)
{
    if (flag == 0)
    {
        printf("OK\n");
        return;
    }
    write(1, "NOK: ", 5);
    switch (flag)
    {
        case 1:
            printf("this node already exists\n");
            break;
        case 2:
            printf("this block already exists\n");
            break;
        case 3:
            printf("node doesn't exist\n");
            break;
        case 4:
            printf("block doesn't exist\n");
            break;
        case 5:
            printf("command not found\n");
            break;
    }
}