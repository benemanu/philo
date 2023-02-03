#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

/*
use the pthread flag with gcc to compile this code
~$ gcc -pthread dining_philosophers.c -o dining_philosophers
*/


struct phil_args {
	int id;
	int *stop;
    int *res;
    pthread_mutex_t* fork1;
    pthread_mutex_t* fork2;
} phil_args_t;

long long current_timestamp() 
{
    struct timeval te; 
    gettimeofday(&te, NULL);
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000;
    return milliseconds;
}

void* philosopher(void* args){
    struct phil_args *my_args = (struct phil_args *) args;
	int id = 0;

	while(*my_args->stop == 0){

		printf("%d  Philosopher %d \n",current_timestamp(), my_args->id);

        if (my_args->id == 1) {
            pthread_mutex_lock(my_args->fork1);
            usleep(100);
            pthread_mutex_lock(my_args->fork2);
        }
        else {
            pthread_mutex_lock(my_args->fork1);
            usleep(100);
            pthread_mutex_lock(my_args->fork2); 
        }

        (*my_args->res)++;
        printf("%d  Philosopher %d %d\n",current_timestamp(), my_args->id, (*my_args->res));
		//pthread_mutex_unlock(my_args->control);
        usleep(10000);
        (*my_args->res)--;

		pthread_mutex_unlock(my_args->fork1);
		pthread_mutex_unlock(my_args->fork2);


	}
	return NULL;
}

int main(void){
	int i,err;
	//pthread_t *philosophers;
    pthread_t *philosopher1;
    pthread_t *philosopher2;
    pthread_mutex_t * fork1;
    pthread_mutex_t * fork2;

	
    int stop = 0;
    int res = 0;
	
	void **arguments;
//
	int philosophers_count;

	srand(time(NULL));

	//printf("Enter number of philosophers:");
	//scanf("%d",&philosophers_count);
	//philosophers = (pthread_t*) malloc(philosophers_count*sizeof(pthread_t));

	//arguments = (void *mutex) malloc(philosophers_count*sizeof(void *));

    philosopher1 = (pthread_t*) malloc(sizeof(pthread_t));
    philosopher2 = (pthread_t*) malloc(sizeof(pthread_t));
    fork1 = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));
    fork2 = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t));

    if (pthread_mutex_init(fork1, NULL) != 0)
	{
		printf("Failed initializing fork1\n");
		return 1;
	};

    if (pthread_mutex_init(fork2, NULL) != 0)
	{
		printf("Failed initializing fork2\n");
		return 1;
	};

    struct phil_args *arguments1 = (struct phil_args *) malloc(sizeof(phil_args_t));
    arguments1->id = 1;
    arguments1->stop = &stop;
    arguments1->res = &res;
    arguments1->fork1 = fork1;
    arguments1->fork2 = fork2;
    err = pthread_create(philosopher1,NULL,&philosopher,arguments1);

    if(err != 0){
        printf("Error creating philosopher: %s\n",strerror(err));
    }else{
        printf("Successfully created philosopher %d\n",arguments1->id);
    }

    struct phil_args *arguments2 = (struct phil_args *) malloc(sizeof(phil_args_t));
    arguments2->id = 2;
    arguments2->stop = &stop;
    arguments2->res = &res;
    arguments2->fork1 = fork1;
    arguments2->fork2 = fork2;
    err = pthread_create(philosopher2,NULL,&philosopher,arguments2);

    if(err != 0){
        printf("Error creating philosopher: %s\n",strerror(err));
    }else{
        printf("Successfully created philosopher %d\n",arguments2->id);
    }

    sleep(5);
    stop = 1;

    pthread_join(*(philosopher1),NULL);
    pthread_join(*(philosopher2),NULL);
	printf("All threads are terminated.\n");
	
    pthread_mutex_destroy(fork1);
    pthread_mutex_destroy(fork2);

    free(fork1);
    free(fork2);

	free(philosopher1);
	free(philosopher2);
	printf("Memory is freed.\n");

	return 0;
}