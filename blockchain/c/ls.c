#include "../h/ls.h"

void ls_for_blockchain(node** node_, int flag)
{
    if (*node_ == NULL)
    {
        return;
    }
    node* temp = *node_;
    block* b_temp = temp->blocks;
    while (temp != NULL)
    {
        printf("%d", temp->node_id);
        b_temp = temp->blocks;
        if (flag == 1)
        {
            printf(":");
            while (b_temp != NULL)
            {
                printf(" %d", b_temp->block_id);
                if (b_temp->next != NULL)
                {
                    printf(",");
                }
                b_temp = b_temp->next;
            }
        }
        printf("\n");
        temp = temp->next;
    }
}

void command_ls(str_array* pars_input, node** head)
{
    if (pars_input->count > 1)
    {
        if ((my_strcmp(pars_input->array[1], "-l")) == 0)
        {
            ls_for_blockchain((head), 1);
            deallocate_str_array(pars_input);
            return;
        }
        error_message(5);
        deallocate_str_array(pars_input);
        return;
    }
    ls_for_blockchain((head), 0);
    deallocate_str_array(pars_input);
    return;
}