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

int main()
{
	input_and_setup();

	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
	for (i = 0; i < totpro; i++)
	{
		x = i;
		for (j = i + 1; j < totpro; j++)
		{
			if (Queue_1[j].arrival_time_t < Queue_1[x].arrival_time_t)
				x = j;
		}
		temporary = Queue_1[i];
		Queue_1[i] = Queue_1[x];
		Queue_1[x] = temporary;
	}
	time_copy = Queue_1[0].arrival_time_t;
	for (i = 0; totpro != 0; i++)
	{
		while (countn != time_quantum1)
		{
			countn++;
			if (Queue_1[i].arrival_time_t <= time_copy)
			{
				for (j = i + 1; j < totpro; j++)
				{
					if (Queue_1[j].arrival_time_t == time_copy && Queue_1[j].prior < Queue_1[i].prior) //pr<
					{
						Queue_2[b] = Queue_1[i];
						b++;
						for (k = i; k < totpro - 1; k++)
							Queue_1[k] = Queue_1[k + 1];
						totpro--;
						countn = 0;
						i = j - 1;
						j--;
					}
				}
			}
			time_copy++;
			Queue_1[i].burst1--;
			if (Queue_1[i].burst1 == 0)
			{
				Queue_1[i].turnaround_time = time_copy - Queue_1[i].arrival_time_t;
				Queue_1[i].waiting_time = Queue_1[i].turnaround_time - Queue_1[i].burst2;
				printf("%d\t|\t%d\t|\t%d\n", Queue_1[i].process_num, Queue_1[i].turnaround_time, Queue_1[i].waiting_time);
				wait_time += time_copy - Queue_1[i].waiting_time;
				turnt += time_copy - Queue_1[i].turnaround_time;
				for (k = i; k < totpro - 1; k++)
					Queue_1[k] = Queue_1[k + 1];
				i--;
				totpro--;
				countn = time_quantum1;
				break;
			}
		}
		countn = 0;
		if (Queue_1[i].burst1 != 0)
		{
			Queue_2[b] = Queue_1[i];
			b++;
			for (k = i; k < totpro - 1; k++)
				Queue_1[k] = Queue_1[k + 1];
			totpro--;
		}
		if (i == totpro - 1)
			i = -1;
	}

	totpro2 = b;
	for (countn = 0; totpro2 != 0;)
	{
		if (Queue_2[countn].burst1 <= time_quantum2 && Queue_2[countn].burst1 > 0)
		{
			time_copy += Queue_2[countn].burst1;
			Queue_2[countn].burst1 = 0;
			check = 1;
		}
		else if (Queue_2[countn].burst1 > 0)
		{
			Queue_2[countn].burst1 -= time_quantum2;
			time_copy += time_quantum2;
		}
		if (Queue_2[countn].burst1 == 0 && check == 1)
		{
			totpro2--;
			Queue_2[countn].turnaround_time = time_copy - Queue_2[countn].arrival_time_t;
			Queue_2[countn].waiting_time = Queue_2[countn].turnaround_time - Queue_2[countn].burst2;
			printf("%d\t|\t%d\t|\t%d\n", Queue_2[countn].process_num, Queue_2[countn].turnaround_time, Queue_2[countn].waiting_time);
			turnt += time_copy - Queue_2[countn].arrival_time_t;
			wait_time += time_copy - Queue_2[countn].arrival_time_t - Queue_2[countn].burst2;
			for (k = countn; k < totpro2; k++)
				Queue_2[k] = Queue_2[k + 1];
			countn--;
			check = 0;
		}

		if (countn == totpro2 - 1)
			countn = 0;
		else
			countn++;
	}
	printf("\n Average Waiting Time= %f\n", wait_time / n);
	printf("Avg Turnaround Time = %f", turnt / n);
}
