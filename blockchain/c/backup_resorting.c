#include "../h/backup_resorting.h"

void backup_check()
{
    int fd = 0;
    int flag = 0;
    struct stat temp;
    if ((fd = open("/home/docode/project/blockchain_data", O_RDONLY)) < 0)
    {
        creat("/home/docode/project/blockchain_data", 00644);
    }
    stat("/home/docode/project/blockchain_data", &temp);
    if (temp.st_size > 0)
    {
        flag = 1;
        printf("Restoring From Backup\n");
    }
    else if (temp.st_size <= 0)
    {
        flag = 0;
        printf("No Backup Found: Starting New Blockchain\n");
    }
    resorting(flag, fd);
}

void resorting(int flag, int fd)
{
    node* head = NULL;
    if (flag == 1)
    {
        head = read_data(fd);
    }
    input(head);
}

node* read_data(int fd)
{
    int i = 0;
    struct stat fs;
    char* b_data;
    node* node_ = NULL;
    str_array* arr;
    str_array* arr_tmp;
    fstat(fd, &fs);
    b_data = malloc(sizeof(char) * (fs.st_size + 1));
    fill_null(b_data, fs.st_size + 1);
    read(fd, b_data, fs.st_size);
    arr = split(b_data, '\n');
    while (i < arr->count)
    {
        arr_tmp = split(arr->array[i], ',');
        add_node(my_atoi(arr_tmp->array[0]), &node_);
        add_node_and_block(&node_, arr_tmp);
        free(arr->array[i]);
        i++;
    }
    free(b_data);
    free(arr->array);
    free(arr);
    close(fd);
    if (!(node_->node_id))
    {
        free(node_);
        node_ = NULL;
    }
    return node_;
}