#define _GNU_SOURCE

#include <limits.h>
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS     1
#define PORT	 7111
#define PACKET_LENGTH 1000
#define NUM_DATA_PACKET 340

void *PrintHello(void *threadid)
{
    char buffer[PACKET_LENGTH];
    int num_bytes;
    int sockfd;
    uint32_t now=0,past=0;
    uint32_t i , diff;
    struct sockaddr_in servaddr, cliaddr;
    int client_struct_length = sizeof(cliaddr);
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 )
	{
		printf("socket creation failed\n");
		exit(EXIT_FAILURE);
	}
    memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr)); 
    servaddr.sin_family	= AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
    while (1)
    {
        /* code */
       // i++;
        //if( i > 10000)
        {
               // if (recvfrom(sockfd, buffer, sizeof(buffer), 4,(struct sockaddr*)&cliaddr, &client_struct_length) < 0)
               num_bytes = recv(sockfd,buffer,PACKET_LENGTH,MSG_WAITALL);
                //{
                    printf("Couldn't receive\n");
               // }//
                //printf("Msg from client: %i\n", sizeof(buffer));
        }
    }
    

}
int main()

{
    int newprio = 5 ;
    int rc,ret;
    long t;
    pthread_t threads;
    pthread_attr_t tattr;
    struct sched_param param;
    ret = pthread_attr_init(&tattr);
    pthread_attr_setinheritsched(&tattr,PTHREAD_EXPLICIT_SCHED);
    ret = pthread_attr_setschedpolicy(&tattr,SCHED_OTHER);
    param.sched_priority  = newprio;
    ret = pthread_attr_setschedparam(&tattr,&param); 
    printf("\nhello raspberry pi %i\n",10);
    rc = pthread_create(&threads, NULL, PrintHello, (void *)t);
    if (rc)
    {
          printf("ERROR; return code from pthread_create() is %d\n", rc);
          exit(-1);
    }
    while (1)
    {
        
    }
    pthread_exit(NULL);
    
    return 0;
}