#include"comm.h"

int main()
{
	int shm_id = get_shm();
	
	char *buf = (char *)shm_at(shm_id);
	int index = 0;
	int count = 0;
	while(1){
		buf[index++] = 'A';
		buf[index] = '\0';
		sleep(1);
		if(count++ > 9)
			break;
	}
	shm_dt(buf);
	sleep(5);
	return 0;
}
