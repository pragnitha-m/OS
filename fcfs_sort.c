#include <stdio.h>
void main()
{
		int i,j,n,temp1,temp2,AT[10],BT[10],CT[10],TAT[10],WT[10];
		printf("\nEnter the number of processes: ");
		scanf("%d",&n);
		printf("\nEnter the arrival times of all processes:\n");
		for(i=0;i<n;i++)
		{
				scanf("%d",&AT[i]);
		}
		printf("\nEnter burst times of all processes:\n");
		for(i=0;i<n;i++)
		{
				scanf("%d",&BT[i]);
		}
		for (i=0;i<n-1;i++)
		{
        		for (j=0;j<n-i-1;j++)
			{
            		if (AT[j]>AT[j + 1])
				{
                			temp1=AT[j];
					AT[j]=AT[j+1];
					AT[j+1]=temp1;
					temp2=BT[j];
					BT[j]=BT[j+1];
					BT[j+1]=temp2;
            			}
        		}
		}
		printf("\nThe Arrival times after sorting are:\n");
        	for(i=0;i<n;i++)
        	{
				printf("%d ",AT[i]);
		}
		printf("\nThe Burst times after sorting are:\n");
		for(i=0;i<n;i++)
		{
				printf("%d ",BT[i]);
		}
		int sum=0,avc=0,avt=0,avw=0;
		printf("\nThe Completion times are:\n");
		for(i=0;i<n;i++)
		{
			sum=sum+BT[i];
			CT[i] = sum;
			printf("%d ",CT[i]);
			avc=avc+CT[i];
		}
		printf("\nThe Average Completion Time is: %d",avc/n);
		printf("\nThe Turn Around Times are:\n");
		for(i=0;i<n;i++) 
		{
			TAT[i] = CT[i]-AT[i];
			printf("%d ",TAT[i]);
			avt=avt+TAT[i];
		}
		printf("\nThe Average Turn Around Time is: %d",avt/n);
		printf("\nThe Wait Times are:\n");
		for(i=0;i<n;i++) 
		{
			WT[i] = TAT[i]-BT[i]; 
			printf("%d ",WT[i]);
			avw=avw+WT[i];
		}
		printf("\nThe Average Wait Time is: %d",avw/n);
}


OUTPUT:
Enter the number of processes: 6

Enter the arrival times of all processes:
2
1
5
4
0
3

Enter burst times of all processes:
2
3
2
3
9
4

The Arrival times after sorting are:
0 1 2 3 4 5 
The Burst times after sorting are:
9 3 2 4 3 2 
The Completion times are:
9 12 14 18 21 23 
The Average Completion Time is: 16
The Turn Around Times are:
9 11 12 15 17 18 
The Average Turn Around Time is: 13
The Wait Times are:
0 8 10 11 14 16 
The Average Wait Time is: 9
