/*just allocating queues to the proceses based up on priority as mentioned in the question*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int b_time1[50],b_time2[50],b_time3[50];   //   array for burst time
int arr1[50],arr2[50],arr3[50];            //   array for arrival time
int main()
{
	int n,i,at[50],bt[50],p[50],j=0,k=0,l=0;
	printf("Enter the total no of processes...\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter details of process %d\n",i+1);
		printf("Arrival Time :-");
		scanf("%d",&at[i]);
		printf("Burst Time :-");
		scanf("%d",&bt[i]);
		printf("Priority of process %d :-",i+1);
		scanf("%d",&p[i]);
	}
	for(i=0;i<n;i++)
	{
		if(p[i]>=1&&p[i]<=5)                      //Round Robin Algorithm when priority is 1-5
		{
			printf("Process %d belongs to Queue 1\n",i+1);
			arr1[j]=at[i];
			b_time1[j]=bt[i];
			j++;
		}
		
		else if(p[i]>=6&&p[i]<=10)              //prority Scheduling when priority is 6-10
		{
			printf("Process %d belongs to Queue 2\n",i+1);
			arr2[k]=at[i];
			b_time2[k]=bt[i];
			k++;
		}
		
		else if(p[i]>=11&&p[i]<=15)           //First come First Serve when priority is 11-15
		{
			printf("Process %d belongs to Queue 3\n",i+1);
			arr3[l]=at[i];
			b_time3[l]=bt[i];
			l++;
		}
	}

}
