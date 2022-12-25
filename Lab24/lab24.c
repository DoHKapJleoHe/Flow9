#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

sem_t detailA, detailB, detailC, module;
int numA, numB, numC, numMod, numWid;

volatile int finishWork = 0;

void* createPartA(void* arg)
{
    while(1)
    {
		    if(finishWork == 1)
		    {
		        printf("A created = %d\n", numA);
		        break;
		    }
		    sleep(3);
		    sem_post(&detailA);
		    printf("Detail A was created!\n");
		    numA++;
    }

    return NULL;
}

void* createPartB(void* arg)
{
    while(1)
    {
		    if(finishWork == 1)
		    {
		        printf("B created = %d\n", numB);
		        break;
		    }
		    sleep(6);
		    sem_post(&detailB);
		    printf("Detail B was created!\n");
		    numB++;
    }

    return NULL;
}

void* createPartC(void* arg)
{
    while(1)
    {
		    if(finishWork == 1)
		    {
		        printf("C created = %d\n", numC);
		        break;
		    }
		    sleep(9);
		    sem_post(&detailC);
		    printf("Detail C was created!\n");
		    numC++;
    }
  
    return NULL;
}

void* createModule(void* arg)
{
    while(1)
    {
		    if(finishWork == 1)
		    {
		        printf("Module created = %d\n", numMod);
		        break;
		    }
		    sem_wait(&detailA);
		    sem_wait(&detailB);
		    sem_post(&module);
		    printf("Module was created!\n");
		    numMod++;
    }

    return NULL;
}

void createWidget()
{
    while(1)
    {
		    if(finishWork == 1)
		    {
		        printf("Widget created = %d\n", numWid);
		        break;
		    }
		    sem_wait(&module);
		    sem_wait(&detailC);
		    printf("There is a new widget, Boss\n");
		    numWid++;
    }
}

void handler(int signum)
{
    finishWork = 1;
}

int main()
{
    pthread_t threadA,
	      threadB,
	      threadC,
	      threadModule;

    struct sigaction sig;
    sig.sa_handler = handler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_RESTART;

    sem_init(&detailA, 0, 0);
    sem_init(&detailB, 0, 0);
    sem_init(&detailC, 0, 0);
    sem_init(&module, 0, 0);

    signal(SIGINT, handler);

    pthread_create(&threadA, NULL, createPartA, NULL);
    pthread_create(&threadB, NULL, createPartB, NULL);
    pthread_create(&threadC, NULL, createPartC, NULL);
    pthread_create(&threadModule, NULL, createModule, NULL);
    createWidget();

    if(finishWork == 1)
    {
		    pthread_join(threadA, NULL);
		    pthread_join(threadB, NULL);
		    pthread_join(threadC, NULL);
		    pthread_join(threadModule, NULL);
    
		    sem_close(&detailA);
		    sem_close(&detailB);
		    sem_close(&detailC);
        sem_close(&module);
    }

    return 0;
}
