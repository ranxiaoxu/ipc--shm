#include"comm.h"

int main()
{
	int shm_id = create_shm(4096);
	sleep(5);
	char *buf = (char *)shm_at(shm_id);
	sleep(5);
	while(1){
		printf("%s\n",buf);
		sleep(1);
		if(strcmp(buf,"AAAAAAAAA") == 0)
			break;
	}
	shm_dt(buf);
	sleep(5);
	destroy_shm(shm_id);
	return 0;
}
