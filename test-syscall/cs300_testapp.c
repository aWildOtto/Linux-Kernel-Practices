#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include "array_stats.h"
#include "process_ancestors.h"

#define _CS300_TEST_ 332 // for a 64 bit system
#define _CS300_TEST_ARRAY_STATS_ 333 // array_stats syscall
#define _CS300_PROCESS_ANCESTORS_ 334// process_stats syscall

int main(int argc, char *argv[])
{
printf("\nDiving to kernel level\n\n");
int result = syscall(_CS300_TEST_, 12345);
printf("\nRising to user level w/ result = %d\n\n", result);


struct array_stats *arr_stats = malloc(sizeof(struct array_stats));
long data[2] = {10,30};//change this around to test
long size = 2;
printf("\nDiving to kernel level again\n\n");
int result2 = syscall(_CS300_TEST_ARRAY_STATS_,arr_stats,data,size);
if (result2==0) {
	printf("\nRising to user level w/ result2 = %d\n\n", result2);
	printf("max is %ld\n", arr_stats->max);
	printf("min is %ld\n", arr_stats->min);
	printf("sum is %ld\n", arr_stats->sum);
}

free(arr_stats);

size = 9;
struct process_info *processes = malloc(sizeof(struct process_info)*size);
long num;
printf("\nDiving to kernel level again for process_stats\n\n");
int result3 = syscall(_CS300_PROCESS_ANCESTORS_, processes, size, &num); //call process_stats syscall here to test
printf("\nRising to user level w/ result3 = %d\n\n", result3);
if (result3==0) {
	for(int i = 0; i < num; i++) {
		printf("Process name = %s\n", processes[i].name);
		printf("pid=%li\n", processes[i].pid);
		printf("state=%li\n", processes[i].state);
		printf("uid=%li\n", processes[i].uid);
		printf("voluntary cs=%li\n", processes[i].nvcsw);
		printf("involuntary cs=%li\n", processes[i].nivcsw);
		printf("numC=%li\n", processes[i].num_children);
		printf("numS=%li\n", processes[i].num_siblings);
	}
	printf("%li\n", num);
}

free(processes);
return 0;
}
