#include "../h/remove.h"

void deallocate_blocks(block* head)
{
    block* tmp = NULL;
    block* head_1 = head;
    while (head_1 != NULL)
    {
        tmp = head_1;
        head_1 = head_1->next;
        free(tmp);
    }
}

void deallocate(node* head)
{
    node* tmp = NULL;
    node* head_1 = head;
    while (head_1 != NULL)
    {
        if (head_1->blocks != NULL)
        {
            deallocate_blocks(head_1->blocks);
        }
        tmp = head_1;
        head_1 = head_1->next;
        free(tmp);
    }
    head = NULL;
}

void eliminate_node(node** head, int id)
{
    node* previous = NULL;
    node* current = *head;
    node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        if (current->node_id == id)
        {
            deallocate_blocks(current->blocks);
            free(current);
            if (previous == NULL)
            {
                *head = next;
                return;
            }
            previous->next = next;
            return;
        }
        previous = current;
        current = current->next;
    }
}

int eliminate_block(block** head, int id)
{
    block* previous = NULL;
    block* current = *head;
    block* next = NULL;
    int flag = 0;
    while (current != NULL)
    {
        next = current->next;
        if (current->block_id == id)
        {
            flag++;
            free(current);
            if (previous == NULL)
            {
                *head = next;
                return flag;
            }
            previous->next = next;
            return flag;
        }
        previous = current;
        current = current->next;
    }
    return flag;
}

void rm_all_blocks_of_node(node** head, int id)
{
    node* current = *head;
    while (current != NULL)
    {
        if (current->node_id == id)
        {
            if (current->blocks != NULL)
            {
                deallocate_blocks(current->blocks);
                current->blocks = NULL;
                break;
            }
        }
        current = current->next;
    }
}

void deallocate_str_array(str_array* s_array)
{
    for (int i = 0; i < s_array->count; i++)
    {
        free(s_array->array[i]);
    }
    free(s_array->array);
    free(s_array);
}

void sort_eliminate(node** head, int block_id, int node_id)
{
    node* current = *head;
    while (current != NULL)
    {
        if (current->node_id == node_id)
        {
            eliminate_block(&current->blocks, block_id);
        }
        current = current->next;
    }
}

int rm_blocks(node* head, int block_id)
{
    node* current = head;
    int flag = 0;
    while (current != NULL)
    {
        flag += eliminate_block(&current->blocks, block_id);
        current = current->next;
    }
    return flag;
}

void command_rm(str_array* pars_input, node** head)
{
    if (my_strcmp(pars_input->array[1], "node") == 0 && pars_input->count == 3)
    {
        if (my_strcmp(pars_input->array[2], "*") == 0)
        {
            deallocate(*(head));
            *head = NULL;
            deallocate_str_array(pars_input);
            error_message(0);
            return;
        }
        else if (is_there_node(*(head), my_atoi(pars_input->array[2])) == 1)
        {
            eliminate_node((head), my_atoi(pars_input->array[2]));
            deallocate_str_array(pars_input);
            error_message(0);
            return;
        }
        error_message(3);
        deallocate_str_array(pars_input);
        return;
    }
    else if (my_strcmp(pars_input->array[1], "block") == 0)
    {
        if (pars_input->count < 3)
        {
            error_message(3);
            deallocate_str_array(pars_input);
            return;
        }
        if (pars_input->count == 3)
        {
            if (rm_blocks(*(head), my_atoi(pars_input->array[2])) == 0)
            {
                deallocate_str_array(pars_input);
                error_message(4);
                return;
            }
            deallocate_str_array(pars_input);
            error_message(0);
            return;
        }
        else if (my_strcmp(pars_input->array[2], "*") == 0)
        {
            if (is_there_node(*(head), my_atoi(pars_input->array[3])) == 0)
            {
                error_message(3);
                deallocate_str_array(pars_input);
                return;
            }
            rm_all_blocks_of_node(head, my_atoi(pars_input->array[3]));
            error_message(0);
            deallocate_str_array(pars_input);
            return;
        }
        else if (is_there_node(*(head), my_atoi(pars_input->array[3])) == 1)
        {
            if (is_contain(*head, my_atoi(pars_input->array[3]),
                           my_atoi(pars_input->array[2])) == 0)
            {
                error_message(4);
                deallocate_str_array(pars_input);
                return;
            }
            sort_eliminate(head, my_atoi(pars_input->array[2]),
                           my_atoi(pars_input->array[3]));
            error_message(0);
            deallocate_str_array(pars_input);
            return;
        }
        error_message(3);
        deallocate_str_array(pars_input);
        return;
    }
    error_message(5);
    deallocate_str_array(pars_input);
    return;
}