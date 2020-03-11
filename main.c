#include <stdio.h>
struct process_details
{
	int process_num;
	int arrival_time_t;
	int waiting_time;
	int turnaround_time;
	int prior;
	int burst2;
	int burst1;
} Queue_1[10], Queue_2[10], temporary;


//Global vars
int    i; 
int    n;
int    x;
int    j;
int    k;
int    b = 0;
int    time_copy = 0;
int    time_quantum1;
int    time_quantum2;
int    totpro;
int    countn = 0;
int    totpro2;
int    check = 0;
float  wait_time = 0;
float  turnt = 0;

void input_and_setup() {
	printf("\n Enter no. Of processes:\t");
	scanf("%d", &totpro);
	n = totpro;

	printf("\nEnter Time Quantum for Fixed priority queue in multiples of 2:-");
	scanf("%d", &time_quantum1);
	printf("\nEnter Time Quantum for Round Robin queue in multiples of 2:-");
	scanf("%d", &time_quantum2);
	
	for (i = 0; i < totpro; i++)
	{
		printf("\nEnter the Process number:-");

		scanf("%d", &Queue_1[i].process_num);

		printf("Enter  the Arrival Time for the process.....time at which the process arrives in the ready queue:-");
		scanf("%d", &Queue_1[i].arrival_time_t);
		printf("Enter the Burst Time for the process.....the amount of time required by a process for executing on CPU.:-");
		scanf("%d", &Queue_1[i].burst1);
		Queue_1[i].burst2 = Queue_1[i].burst1;
		printf("Enter the Priority for the process.....higher priority is carried out first:\t");
		scanf("%d", &Queue_1[i].prior);
	}

}


int main(){
input_and_setup();
printf("this is os project");}
