#include<stdio.h>
#include<stdlib.h>
struct process
{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
}p[20],temp;
int n;
void asort()
{
	int min=p[0].at;
	for(int i=1;i<n;i++)
	{
		if(p[i].at<min)
			min=p[i].at;
	}
	for(int i=0;i<n;i++)
	{
		if(p[i].at==min)
		{
			temp=p[0];
			p[0]=p[i];
			p[i]=temp;
			break;
		}
	}
	p[0].ct=p[0].at+p[0].bt;
	    for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].bt>p[j].bt)
		{
		temp=p[i];
		p[i]=p[j];
		p[j]=temp;
		}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		if(p[i].bt==p[j].bt)
		{
			if(p[i].at>p[j].at)
			{
			temp=p[i];
			p[i]=p[j];
			p[j]=temp;
			}
		}
		}
	}
}
void sjf()
{
	float sum1=0,sum2=0;
	asort();
	for(int i=0;i<n;i++)
	{
	if(p[i+1].at>p[i].ct)
	{
	    int flag=0;
	        for(int j=i+2;j<n;j++)
	        {
	            if(p[j].at<p[i].ct)
	                {
	                    p[j]=temp;
	                    for(int t=j-1;t>i;t--)
	                    {
	                        p[t+1]=p[t];
	                    }
	                    p[i+1]=temp;
	                    flag=1;
	                    p[i+1].ct=p[i].ct+p[i+1].bt;
	                    break;
	                }
	        }
	    if(flag==0)
	    p[i+1].ct=p[i+1].at+p[i+1].bt;
	}
	else
	p[i+1].ct=p[i].ct+p[i+1].bt;
	}
	for(int i=0;i<n;i++)
	{
	    p[i].tat=p[i].ct-p[i].at;
    	sum1+=p[i].tat;
    	p[i].wt=p[i].tat-p[i].bt;
    	sum2+=p[i].wt;
	}
	printf("<-------------------------SJF-------------------------> \n");
	printf("Process ID\tArrival time\tBurst Time\tCompletion time\tTurnaround time\tWaiting time\n");
	for(int i=0;i<n;i++)
	{
	printf("%d\t\t",p[i].pid);
	printf("%d\t\t",p[i].at);
	printf("%d\t\t",p[i].bt);
	printf("%d\t\t",p[i].ct);
	printf("%d\t\t",p[i].tat);
	printf("%d\t\t",p[i].wt);
	printf("\n");
	}
	printf("Average turnaround time: %f\nAverage waiting time: %f",(sum1/n),(sum2/n));
}
void main()
{
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	printf("Enter process id: ");
	scanf("%d",&p[i].pid);
	printf("Enter arrival time: ");
	scanf("%d",&p[i].at);
	printf("Enter burst time: ");
	scanf("%d",&p[i].bt);
	printf("\n");
	}
	sjf();
}

