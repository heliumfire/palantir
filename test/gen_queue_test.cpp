/*
 * gen_queue_test.cpp
 *
 *  Created on: 18 Sep 2015
 *      Author: regnarts
 */

#include <test/gen_queue_test.h>
#include <event_auto.h>
#include <string.h>

THREAD(source);
THREAD(drain);

typedef struct TEST_PL{
	char* 	data;
	int		size;
} test_pl_t, *ptest_pl_t;

gen_queue<test_pl_t> *q;

gen_queue_test::gen_queue_test() {
	// TODO Auto-generated constructor stub
	q = new gen_queue<test_pl_t>;
}

void* source_fn(void* data){
	char* tmp;
	printf("Starting Source");
	while(1){
		tmp = (char*)malloc(sizeof(char)*12);
		memcpy(tmp,"hello,world",12);
		ptest_pl_t pl;
		pl =  new TEST_PL;
		pl->data = tmp;
		pl->size = 12;
		q->push(pl,12);
	}
}


void* drain_fn(void* data){
	printf("Starting Drain");
	ptest_pl_t pl;
	int size;
	while(1){
		q->pull(pl,size);
		printf("%s\n",pl->data);
	}
}
int gen_queue_test::start_test(){
	TH_CREATE(source, &source_fn, NULL);
	TH_CREATE(drain, &drain_fn, NULL);
}

gen_queue_test::~gen_queue_test() {
	// TODO Auto-generated destructor stub
}

int main(){
	printf("Starting test");
	gen_queue_test* test;
	test = new gen_queue_test();
	test->start_test();
	while(1);
}
