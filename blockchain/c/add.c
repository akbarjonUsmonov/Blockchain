#include "../h/add.h"


void add_node(int id, node** head)
{
    node* new = (node*)malloc(sizeof(node));
    new->node_id = id;
    new->blocks = NULL;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        node* tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void add_block(int id, block** head)
{
    block* new = (block*)malloc(sizeof(block));
    new->block_id = id;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
    }
    else
    {
        block* tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new;
    }
}

void add_node_and_block(node** node_, str_array* arr)
{
    int i = 1;
    node* list = *node_;
    while (list->next != NULL)
    {
        list = list->next;
    }
    free(arr->array[0]);
    while (i < arr->count)
    {
        add_block(my_atoi(arr->array[i]), &list->blocks);
        free(arr->array[i]);
        i++;
    }
    free(arr->array);
    free(arr);
}

void add_blocks_to_all(node** head, int block_id, int node_id, int flag)
{
    node* current = *head;
    while (current != NULL)
    {
        if (flag == 1)
        {
            if (is_there_block(current->blocks, block_id) == 0)
            {
                add_block(block_id, &current->blocks);
            }
        }
        else if (current->node_id == node_id)
        {
            if (is_there_block(current->blocks, block_id) == 1)
            {
                error_message(2);
                return;
            }
            add_block(block_id, &current->blocks);
            break;
        }
        current = current->next;
    }
    error_message(0);
}

void command_add(str_array* pars_input, node** head)
{
    if (pars_input->count >= 3)
    {
        if ((my_strcmp(pars_input->array[1], "node") == 0) &&
            (pars_input->count == 3))
        {
            if (is_there_node(*(head), my_atoi(pars_input->array[2])) == 1)
            {
                error_message(1);
                deallocate_str_array(pars_input);
                return;
            }
            else if (number_check(pars_input->array[2]) == 1)
            {
                error_message(5);
                deallocate_str_array(pars_input);
                return;
            }
            add_node(my_atoi(pars_input->array[2]), (head));
            error_message(0);
            deallocate_str_array(pars_input);
            return;
        }
        if ((my_strcmp(pars_input->array[1], "block") == 0) &&
            (pars_input->count == 4) && number_check(pars_input->array[2]) == 0)
        {
            if (my_strcmp(pars_input->array[3], "*") == 0)
            {
                add_blocks_to_all((head), my_atoi(pars_input->array[2]), 0, 1);
                deallocate_str_array(pars_input);
                return;
            }
            else if (number_check(pars_input->array[3]) == 0)
            {
                if (is_there_node(*(head), my_atoi(pars_input->array[3])) == 1)
                {
                    add_blocks_to_all((head), my_atoi(pars_input->array[2]),
                                      my_atoi(pars_input->array[3]), 0);
                    deallocate_str_array(pars_input);
                    return;
                }
                error_message(3);
                deallocate_str_array(pars_input);
                return;
            }
        }
        error_message(5);
        deallocate_str_array(pars_input);
        return;
    }
    error_message(5);
    deallocate_str_array(pars_input);
    return;
}