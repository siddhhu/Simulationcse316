#include<stdio.h>
#include<stdlib.h>
void Priority()                                                                   //Moderate Priority Process --> Priority Sceduling
{
	for(i=0;i<k;i++)
    {
        pos=i;
        for(q=i+1;q<k;q++)
        {
            if(prio[q]<prio[pos])
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
    for(i=1;i<k;i++)
    {
        wait_time2[i]=0;
        for(q=0;q<i;q++)
        {
            wait_time2[i]=wait_time2[i]+b_time2[j];
        }
        sum=sum+wait_time2[i];
    }
    avg_wait_time2=sum/k;
    sum=0;
    printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
    for(i=0;i<k;i++)
    {
    	turn_time2[i]=b_time2[i]+wait_time2[i];
        sum=sum+turn_time2[i];
        printf("\nProcess%d\t\t%d\t\t %d\t\t %d\n",process[i],b_time2[i],wait_time2[i],turn_time2[i]);
    }
    avg_turn_time2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avg_wait_time2);
    printf("\nAverage Turnaround Time:\t%f\n",avg_turn_time2);
    
    for(i=0;i<k;i++)
    {
    	while(b_time2[i]!=0)
    	{
    		if(b_time2[i]>10)
    		{
				printf("\nProcess%d of Queue2 has been running for 10 units",i+1);
				b_time2[i]=b_time2[i]-10;
			}
			else if(b_time2[i]<=10)
			{
				printf("\nProcess%d of Queue2 has been running for %d units",i+1,b_time2[i]);
				b_time2[i]=0;
			}
		}
	}
int main()
   {
        Priority()
   }
