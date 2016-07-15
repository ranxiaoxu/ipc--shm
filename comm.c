#include"comm.h"

static int comm(int flag,int size)
{
	key_t _key = ftok(_PATH_NAME_,_PROJ_ID_);
	if(_key < 0){
		printf("comm:%s\n",strerror(errno));
		return -1;
	}
	int shm_id = shmget(_key,size,flag);
	if(shm_id < 0){
	
		printf("shmget:%s\n",strerror(errno));
		return -1;
	}
	return shm_id;
}
int create_shm(int size)
{
	int flag = IPC_CREAT | 0666;
	return comm(flag,size);
}
int get_shm()
{
	int flag = IPC_CREAT;
	return comm(flag,0);
}
int destroy_shm(int shm_id)
{
	if(shmctl(shm_id,IPC_RMID,NULL) < 0){
		printf("%s\n",strerror(errno));
		return -1;
	}
	return 0;
}
void *shm_at(int shm_id)
{
	return shmat(shm_id,NULL,0);
}
void *shm_dt(void *shm_addr)
{
	return shmdt(shm_addr);
}


