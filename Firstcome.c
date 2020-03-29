#include<stdio.h>
#include<stdlib.h>
void FirstCome()                                                              //low Priority process -->First Come First Serve
{
	wait_time1[0] = 0;   
    for(i=1;i<l;i++)
    {
        wait_time1[i] = 0;
        for(p=0;p<l;p++)
        {
            wait_time1[i]=wait_time1[i]+b_time3[p];
        }
    }
    
    for(i=0;i<l;i++)
    {
        turnaround_time3[i]=b_time3[i]+wait_time1[i];                               //As Turnaround time = Burst time + Waiting time
        avg_wait_time3=avg_wait_time3+wait_time1[i];                            
        avg_turn_time3=avg_turn_time3+turnaround_time3[i];
        printf("\nProcess%d\t\t%d\t\t%d\t\t%d\n",i+1,b_time3[i],wait_time1[i],turnaround_time3[i]);
    }
    avg_wait_time3=avg_wait_time3/l;
    avg_turn_time3=avg_turn_time3/l;
    
    for(i=0;i<l;i++)
    {
    	while(b_time3[i]!=0)
    	{
    		if(b_time3[i]>10)
    		{
				printf("\nProcess%d of Queue3 is running for 10 unit of time",i+1);
				b_time3[i]=b_time3[i]-10;
			}
			else if(b_time3[i]<=10)
			{
				printf("\nProcess%d of Queue2 is running for %d unit of time",i+1,b_time3[i]);
				b_time3[i]=0;
			}
		}
	}
int main()
     {
        Firstcome();
     }
