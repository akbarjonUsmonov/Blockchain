#include "../h/sync.h"

void sync_for_blockchain(node* head)
{
    if (head == NULL)
    {
        return;
    }

    node* current = head;
    block* previous = NULL;
    node* tmp = NULL;
    block* t_block = NULL;

    while (current != NULL)
    {
        tmp = head;
        while (tmp != NULL)
        {
            if (previous != NULL)
            {
                while (previous != NULL)
                {
                    if (is_there_block(current->blocks, previous->block_id) ==
                        0)
                    {
                        add_block(previous->block_id, &current->blocks);
                    }
                    previous = previous->next;
                    break;
                }
            }
            t_block = tmp->blocks;
            while (t_block != NULL)
            {
                if (is_there_block(current->blocks, t_block->block_id) == 0)
                {
                    add_block(t_block->block_id, &current->blocks);
                }
                t_block = t_block->next;
            }

            tmp = tmp->next;
        }
        previous = current->blocks;
        current = current->next;
    }
}

int sync_check(node* head)
{
    node* tmp = head;
    while (tmp->next != NULL)
    {
        block* b_tmp = tmp->blocks;
        while (b_tmp != NULL)
        {
            if (is_there_block(head->next->blocks, b_tmp->block_id) == 0)
            {
                return 1;
            }
            b_tmp = b_tmp->next;
        }
        tmp = tmp->next;
    }
    return 0;
}