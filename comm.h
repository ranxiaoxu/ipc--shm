#pragma once

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>

#define _PATH_NAME_ "/tmp"
#define _PROJ_ID_ 0x666

int create_shm(int size);
int get_shm();
int destroy_shm(int shm_id);

void* shm_at(int shm_id);
void* shm_dt(void * shm_addr);
