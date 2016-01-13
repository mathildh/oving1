#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void* thread_increase_i(void* arg){
	int j;
	int* i = (int*)arg;
	for (j = 0; j < 1000000; j++){
		(*i)++;
	}
	
}
void* thread_decrease_i(void* arg){
	int j;
	int* i = (int*)arg;
	for (j = 0; j < 1000000; j++){
		(*i)--;
	}
	int* a = malloc(sizeof(int));
	*a = 5;
	return a;
}

int main(){
	int i = 0;
	printf("Hello from main!\n");
	pthread_t thread_1;
	pthread_t thread_2;
	pthread_create(&thread_1,NULL,thread_increase_i,&i);
	pthread_create(&thread_2,NULL,thread_decrease_i,&i);
	pthread_join(thread_1, NULL);
	int* a;
	pthread_join(thread_2, (void**)&a);
	printf("a = %d\n", *a);
	free(a);
	printf("Done, result: %i\n",i); 

}