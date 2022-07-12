/* Multilevel Feedback Queue Scheduler */

#include<stdio.h>

struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT;
}
/* four queues implementation */
Q1[10],Q2[10],Q3[10],Q4[10];

int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(Q1[i].AT>Q1[j].AT)
                    {
                          temp=Q1[i];
                          Q1[i]=Q1[j];
                          Q1[j]=temp;
                    }
            }
    }
}

int main()
{
     int i,j,k,l=0,r=0,time=0;
     
     // Time Quantun : tq
     int tq1=2,tq2=4,tq3=8,flag=0;
     char c;
     printf("Total number of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         Q1[i].name=c;
         printf("\nMention the arrival time (AT) and burst time (BT) of process %c: ",Q1[i].name);
         scanf("%d%d",&Q1[i].AT,&Q1[i].BT);
         Q1[i].RT=Q1[i].BT;

    }
sortByArrival();
time=Q1[0].AT;
printf("Process is in first queue following RR with qt=5");
printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(Q1[i].RT<=tq1)
  {

       time+=Q1[i].RT;
       Q1[i].RT=0;
       Q1[i].WT=time-Q1[i].AT-Q1[i].BT;
       Q1[i].TAT=time-Q1[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q1[i].name,Q1[i].BT,Q1[i].WT,Q1[i].TAT);

  }
  else/*queue 2 with qt=4*/
  {
      Q2[k].WT=time;
      time+=tq1;
      Q1[i].RT-=tq1;
      Q2[k].BT=Q1[i].RT;
      Q2[k].RT=Q2[k].BT;
      Q2[k].name=Q1[i].name;
      k=k+1;
      flag=1;
   }
}
if(flag==1)
 {printf("\nProcess is in second queue following RR with qt=4");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<k;i++)
   {
    if(Q2[i].RT<=tq2)
     {
       time+=Q2[i].RT;
       Q2[i].RT=0;
       Q2[i].WT=time-tq1-Q2[i].BT;
       Q2[i].TAT=time-Q2[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q2[i].name,Q2[i].BT,Q2[i].WT,Q2[i].TAT);

    }
    else/*queue 3 with tq=8*/
    {
      Q3[k].WT=time;
      time+=tq1;
      Q2[i].RT-=tq1;
      Q3[k].BT=Q2[i].RT;
      Q3[k].RT=Q2[k].BT;
      Q3[k].name=Q2[i].name;
      l=l+1;
      flag=2;
    }
  }
if(flag==2)
 {printf("\nProcess id in third queue following RR with qt=8");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<l;i++)
   {
    if(Q3[i].RT<=tq3)
     {
       time+=Q3[i].RT;
       Q3[i].RT=0;
       Q3[i].WT=time-tq2-Q3[i].BT;
       Q3[i].TAT=time-Q3[i].AT;
       printf("\n%c\t\t%d\t\t%d\t\t%d",Q3[i].name,Q3[i].BT,Q3[i].WT,Q3[i].TAT);

    }
    else/*queue 4 with FCFS*/
    {
      Q4[r].AT=time;
      time+=tq2;
      Q4[i].RT-=tq3;
      Q4[r].BT=Q3[i].RT;
      Q4[r].RT=Q4[r].BT;
      Q4[r].name=Q3[i].name;
      r=r+1;
      flag=3;
    }
  }


{if(flag==3)
printf("\nProcess is in forth queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            Q4[i].CT=Q4[i].BT+time-tq1-tq2-tq3;
        else
            Q4[i].CT=Q4[i-1].CT+Q4[i].BT;

}

for(i=0;i<r;i++)
    {
        Q4[i].TAT=Q4[i].CT;
        Q4[i].WT=Q4[i].TAT-Q4[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",Q4[i].name,Q4[i].BT,Q4[i].WT,Q4[i].TAT);

    }

}





