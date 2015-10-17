/*
 * main.cpp
 *
 *  Created on: 11 Oct 2015
 *      Author: regnarts
 */

#include <os/os_thread.h>
#include <utils/gen_queue.h>
#include <event_auto.h>

THREAD(source);
THREAD(drain);

typedef struct TEST_PL{
	char* 	data;
	int		size;
} test_pl_t, *ptest_pl_t;

gen_queue<test_pl_t> *q;

void* source_fn(void* data){
	char* tmp;
	int i = 0;
	printf("Starting Source");
	while(1){
		if(i%500 == 0){
			tmp = (char*)malloc(sizeof(char)*12);
			memcpy(tmp,"hello,world",12);
			ptest_pl_t pl;
			pl =  new TEST_PL;
			pl->data = tmp;
			pl->size = 12;
			q->push(pl);
		}
		i++;
	}
}


void* drain_fn(void* data){
	printf("Starting Drain");
	ptest_pl_t pl;
	int size;
	while(1){
		//
					printf("%s\n",q->pull()->data);
	}
}



int main(){
	q = new gen_queue<test_pl_t>;
	TH_CREATE(source, &source_fn, NULL);
	TH_CREATE(drain, &drain_fn, NULL);
	printf("Starting test");
	while(1);
}

