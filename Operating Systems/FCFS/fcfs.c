#include<stdlib.h>
#include<stdio.h>
struct process
{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
}p[20],temp;
int n;
void asort()
{
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
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
void fcfs()
{
 float sum1,sum2=0;
 asort();
 p[0].ct=p[0].at+p[0].bt;
 for(int i=0;i<n;i++)
 {
   p[i+1].ct=p[i].ct+p[i+1].bt;
   p[i].tat=p[i].ct-p[i].at;
   sum1=sum1+p[i].tat;
   p[i].wt=p[i].tat-p[i].bt;
   sum2=sum2+p[i].wt;
 }
 printf("-----FCFS-----\n");
 printf("PROCESS ID\tARRIVAL TIME\t\tBURST TIME\t\tCOMPLETION TIME\t\tTURN AROUND TIME\tWAITING TIME\n");
 for(int i=0;i<n;i++)
 {
   printf("%d\t\t\t",p[i].pid);
   printf("%d\t\t\t",p[i].at);
   printf("%d\t\t\t",p[i].bt);
   printf("%d\t\t\t",p[i].ct);
   printf("%d\t\t\t",p[i].tat);
   printf("%d\t\t\t",p[i].wt);
   printf("\n");
 }
 printf("AVERAGE TURN AROUND TIME :%f\n",(sum1/n));
 printf("AVERAGE WAITING TIME     :%f\n",(sum2/n));
}
void main()
{
  printf("ENTER NUMBER OF PROCESS:	");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
   printf("ENTER PROCESS ID      :	");
   scanf("%d",&p[i].pid);
   printf("ENTER ARRIVAL TIME    :	");
   scanf("%d",&p[i].at);
   printf("ENTER BURST TIME      :	");
   scanf("%d",&p[i].bt);
   printf("\n");
   /*printf("ENTER COMPLETION TIME :	");
   scanf("%d",&p[i].ct);
   printf("ENTER TURN AROUND TIME:	");
   scanf("%d",&p[i].tat);
   printf("ENTER WAITING TIME    :	");
   scanf("%d",&p[i].wt);
   */
  }
  fcfs();
}
