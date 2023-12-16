#ifndef BLOCKCHAIN_H_BACKUP_RESORTING_H_
#define BLOCKCHAIN_H_BACKUP_RESORTING_H_

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "./add.h"
#include "./my_string.h"
#include "./convertor.h"
#include "./structures.h"
#include "main_process.h"

void backup_check();
void resorting(int, int);
node* read_data(int);

#endif