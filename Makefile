transmission :
	sudo scp out root@192.168.1.125:/home/root

compile : 
	@${CC} -o out main.c
#	@file out
clean :
	@rm -rf out

