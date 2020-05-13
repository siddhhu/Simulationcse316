#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int b_time1[50], b_time2[50], b_time3[50];         //Burst time for all the three queues
int arr1[50], arr2[50], arr3[50];                 //Arrival time for all the three queues
int prio[50], process[50];
int Total=0, t1=0, t2=0, t3=0;
int n, i, at[50], bt[50], pr[50], j=0, k=0,l=0;
int total, x, temp[50], counter=0;
float avg_wait_time1=0.0, avg_turn_time1=0.0;      
float avg_wait_time2=0.0, avg_turn_time2=0.0;
float avg_wait_time3=0.0, avg_turn_time3=0.0;
int p, wait_time1[50], turnaround_time3[50];
int pos, q, temp1, sum=0, wait_time2[50], turn_time2[50];
		
						//low Priority process -->First Come First Serve
void FirstCome()                                                              
{
	wait_time1[0] = 0;   
    	for(i=1; i<l; i++)
    	{
	        wait_time1[i] = 0;
        	for (p=0; p<l; p++)
        	{
            		wait_time1[i] = wait_time1[i] + b_time3[p];
        	}
    	}
    
    for (i=0; i<l; i++)
    {
												//As Turnaround time = Burst time + Waiting time
        turnaround_time3[i]=b_time3[i]+wait_time1[i];                               
        avg_wait_time3=avg_wait_time3+wait_time1[i];                            
        avg_turn_time3=avg_turn_time3+turnaround_time3[i];
        printf("\nProcess%d\t\t%d\t\t%d\t\t%d\n",i+1,b_time3[i],wait_time1[i],turnaround_time3[i]);
    }
    avg_wait_time3=avg_wait_time3/l;
    avg_turn_time3=avg_turn_time3/l;
    
    for (i=0; i<l; i++)
    {
    	while (b_time3[i]!=0)
    	{
    		if(b_time3[i]>10)
    		{
				printf("\nProcess%d of Queue3 is running for 10 unit of time",i+1);
				b_time3[i]=b_time3[i]-10;
			}
			else if (b_time3[i]<=10)
			{
				printf("\nProcess%d of Queue2 is running for %d unit of time",i+1,b_time3[i]);
				b_time3[i]=0;
			}
		}
	}
}
void Priority()                                                                   //Moderate Priority Process --> Priority Sceduling
{
	for (i=0; i<k; i++)
    {
        pos=i;
        for (q=i+1; q<k; q++)
        {
            if (prio[q]<prio[pos])
            {
                pos=q;
            }
        }
        temp1=prio[i];
        prio[i]=prio[pos];
        prio[pos]=temp1; 
        
        temp1=b_time2[i];
        b_time2[i]=b_time2[pos];
        b_time2[pos]=temp1;
        
        temp1=process[i];
        process[i]=process[pos];
        process[pos]=temp1;
    }
    wait_time2[0]=0;
    for (i=1; i<k; i++)
    {
        wait_time2[i]=0;
        for (q=0; q<i; q++)
        {
            wait_time2[i]=wait_time2[i]+b_time2[j];
        }
        sum=sum+wait_time2[i];
    }
    avg_wait_time2=sum/k;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for (i=0; i<k; i++)
    {
    	turn_time2[i] = b_time2[i]+wait_time2[i];
        sum = sum+turn_time2[i];
        printf("\nProcess%d\t\t%d\t\t %d\t\t %d\n",process[i],b_time2[i],wait_time2[i],turn_time2[i]);
    }
    avg_turn_time2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avg_wait_time2);
    printf("\nAverage Turnaround Time:\t%f\n",avg_turn_time2);
    
    for (i=0; i<k; i++)
    {
    	while (b_time2[i]!=0)
    	{
    		if (b_time2[i]>10)
    		{
				printf("\nProcess%d of Queue2 has been running for 10 units",i+1);
				b_time2[i]=b_time2[i]-10;
			}
			else if (b_time2[i]<=10)
			{
				printf("\nProcess%d of Queue2 has been running for %d units",i+1,b_time2[i]);
				b_time2[i]=0;
			}
		}
	}

}

void roundRobin()                                                                //High Priority processes --> Round Robin Algorithm  (In this time quantum is 4)                                                   
{
	printf("Time Quantum for Queue1 is 4\n");
	
	for (i=0; i<j; i++)
	{
		temp[i] = b_time1[i];
	} 
	
	printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");
	x = j;
	
    	for (i=0, total=0; x;) 
    	{	 
    		if (temp[i] <= 4 && temp[i]>0) 
        	{
			printf("\nProcess%d of Queue1 is running for %d units",i+1,temp[i]); 
            		total = total+temp[i]; 
            		temp[i] = 0; 
            		counter = 1; 
        	}	 
        	else if (temp[i]>0) 
        	{
			printf("\nProcess%d of Queue1 is running for 4 units",i+1); 
            		temp[i] = temp[i]-4; 
            		total = total+4; 
        	}	 
        	if (temp[i]==0 && counter==1) 
        	{ 
            		x--; 
            		printf("\nProcess%d\t    %d\t\t\t%d\t\t\t%d", i+1,b_time1[i], total-arr1[i], total-arr1[i]-b_time1[i]);
            		avg_wait_time1 = avg_wait_time1+total-arr1[i]-b_time1[i]; 
            		avg_turn_time1 = avg_turn_time1+total-arr1[i]; 
            		counter = 0; 
        	} 
        	if (i == j-1) 
        	{
        	    	i=0; 
        	}
        	else if (arr1[i+1] <= total) 
        	{
        		i++;
        	}
        	else 
        	{
            		i=0;
        	}
    	} 
	
    	avg_wait_time1 = avg_wait_time1/j;
    	avg_turn_time1 = avg_turn_time1/j;
    	printf("\n\n\n");
    	printf("\t\t\t\t\---------------------------------");
    	printf("\n\t\t\t\tAverage Waiting Time     :%.3f", avg_wait_time1); 
    	printf("\n\t\t\t\tAverage Turnaround Time  :%.3f\n", avg_turn_time1); 
    	printf("\t\t\t\t\---------------------------------");
}
						 //This round robin function is for time quantum 10 units      

void roundRobin1()                                                                                                   
{
	printf("\n\nTime Quantum between the 3 queues is 10\n");
	
	for (i=1; i<Total; i += 10)
	{
		if (t1>10)
		{
			printf("Queue1 is running for 10 unit time\n");
			t1 = t1 - 10;
		}
		else if (t1 <= 10 && t1 )
		{
			printf("Queue1 is running for %d unit time\n", t1);
			t1 = 0;
		}
		if (t2>10)
		{
			printf("Queue2 is running for 10 unit time\n");
			t2 = t2 - 10;
		}
		else if (t2 <= 10 && t2)
		{
			printf("Queue2 is running for %d unit time\n", t2);
			t2 = 0;
		}
		if (t3 > 10)
		{
			printf("Queue3 is running for 10 unit time\n");
			t3 = t3 - 10;
		}
		else if (t3 <= 10 && t3)
		{
			printf("Queue3 is running for %d unit time\n", t3);
			t3 = 0;
		}
	}
}

int main()
{
	printf("Enter total no. of process you want to enter\n");
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		printf("Enter details of process :%d\n", i+1);
		printf("Arrival Time:");
		scanf("%d", &at[i]);
		printf("Burst Time:");
		scanf("%d", &bt[i]);
		printf("Priority(1 to 15):");
		scanf("%d", &pr[i]);
		Total = Total + bt[i];
	}
	
	for (i=0; i<n; i++)
	{
		if (pr[i] >= 1 && pr[i] <= 5)
		{
			printf("\n\nProcess%d belongs to Queue 1", i+1);
			arr1[j] = at[i];
			b_time1[j] = bt[i];
			j++;
			t1 = t1 + bt[i];
		}
		
		else if (pr[i] >= 6 && pr[i] <= 10)
		{
			printf("Process%d belongs to Queue 2", i+1);
			arr2[k] = at[i];
			b_time2[k] = bt[i];
			prio[k] = pr[i];
			process[k] = k+1;
			k++;
			t2=t2+bt[i];
		}
		
		else if (pr[i] >= 11 && pr[i] <= 15)
		{
			printf("Process%d belongs to Queue 3\n\n\n\n", i+1);
			arr3[l] = at[i];
			b_time3[l] = bt[i];
			l++;
			t3 = t3 + bt[i];
		}
	}
	
	roundRobin1();
	roundRobin();
	FirstCome();
	Priority();	

	return 0;
}
