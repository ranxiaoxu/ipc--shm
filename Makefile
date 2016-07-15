.PHONY:all
all:server client
server:server.c comm.c
	gcc -o server server.c comm.c -g
client:client.c comm.c
	gcc -o client client.c comm.c
.PHONY:clean
clean:
	rm -f server client
