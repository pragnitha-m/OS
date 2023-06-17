#include <stdio.h>
void main()
{
		int i,j,k,n,time1,temp,smallest,total=0,bt[10],at[10],ct[10],tat[10],wt[10],extra[10];
		printf("\nEnter the number of processes: ");
		scanf("%d",&n);
		printf("\nEnter the arrival times of all processes:\n");
		for(k=0;k<n;k++)
		{
				scanf("%d",&at[k]);
		}
		printf("\nEnter burst times of all processes:\n");
		for(j=0;j<n;j++)
		{
				scanf("%d",&bt[j]);
				total+=bt[j];
		}
		for(k=0;k<n;k++)
		{
		        extra[k]=bt[k];
		}
		bt[9]=9999;
		for(time1=0;time1<=total;time1+=temp)
		{
		        smallest=9;
				for(i=0;i<n;i++)
				{
						if(bt[i]<bt[smallest] && at[i]<=time1 && bt[i]>0)
								smallest=i;
				}
				ct[smallest]=time1+bt[smallest];
				wt[smallest]=time1-at[smallest];
				tat[smallest]=ct[smallest]-at[smallest];
				temp=bt[smallest];
				bt[smallest]=0;
		}
		printf("The Arrival Time, Burst Time, Completion Time, Turn Around Time of processes are:\n");
		printf("\n\tAT\tBT\tCT\tTAT\tWT");
		for(i=0;i<n;i++)
		{
				printf("\nP%d\t%d\t%d\t%d\t%d\t%d",i+1,at[i],extra[i],ct[i],tat[i],wt[i]);
		}
}


OUTPUT:
Enter the number of processes: 4

Enter the arrival times of all processes:
2
1
0
4

Enter burst times of all processes:
6
8
3
4
The Arrival Time, Burst Time, Completion Time, Turn Around Time of processes are:

        AT      BT      CT      TAT     WT
P1      2       6       9       7       1
P2      1       8       21      20      12
P3      0       3       3       3       0
P4      4       4       13      9       5
