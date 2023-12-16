#include "../h/main_process.h"

int promp(node* head)
{
    if (head == NULL)
    {
        return 0;
    }
    int len = block_length(head->blocks);
    node* tmp = head;
    while (tmp != NULL)
    {
        if (len != block_length(tmp->blocks))
        {
            return 1;
        }
        else if (sync_check(tmp) == 1)
        {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void print_promp(node* head)
{
    //[s0]>
    int nodes_length = node_length(head);
    printf("[");
    if (promp(head) == 0)
    {
        printf("s");
    }
    else if (promp(head) == 1)
    {
        printf("-");
    }
    printf("%d]", nodes_length);
    fflush(stdout);
}

void command_check(char* input, node** head)
{
    str_array* pars_input = split(input, ' ');
    if (my_strcmp(pars_input->array[0], "ls") == 0)
    {
        command_ls(pars_input, head);
        return;
    }
    else if (my_strcmp(pars_input->array[0], "add") == 0)
    {
        command_add(pars_input, head);
        return;
    }
    else if (my_strcmp(pars_input->array[0], "rm") == 0)
    {
        command_rm(pars_input, head);
        return;
    }

    else if (pars_input->count >= 1)
    {
        error_message(5);
        deallocate_str_array(pars_input);
        return;
    }
    deallocate_str_array(pars_input);
}

void input(node* head)
{
    char* input;
    fflush(stdin);
    while (1)
    {
        print_promp(head);
        input = my_scanf();
        f_delete_space(input);
        if (my_strcmp(input, "stop") == 0)
        {
            write_data(head);

            printf("\nBacking up blockchain...\n");
            break;
        }
        else if (my_strcmp(input, "quit") == 0)
        {
            write_data(head);
            printf("Backing up blockchain...\n");
            break;
        }
        else if (my_strcmp(input, "sync") == 0)
        {
            sync_for_blockchain(head);
            error_message(0);
        }
        else if (my_strcmp(input, "\0") != 0)
        {
            command_check(input, &head);
        }
        free(input);
    }
    free(input);
    if (head != NULL)
    {
        deallocate(head);
    }
}