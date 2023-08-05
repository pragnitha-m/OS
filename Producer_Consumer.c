#include <stdio.h>
#include <stdlib.h>
int bs=1,cs=0;
int wait(int n)
{
		n--;
		return n;
}
int signal(int n)
{
		n++;
		return n;
}
void producer()
{
		bs=wait(bs);
		cs=signal(cs);
		printf("After producing no.of items in buffer: %d\n",cs);
		bs=signal(bs);
}
void consumer()
{
		bs=wait(bs);
		cs=wait(cs);
		printf("After consuming no.of items in buffer: %d\n",cs);
		bs=signal(bs);
}
int main()
{
		int b,choice;
		printf("Enter the size of the buffer: ");
		scanf("%d",&b);
		while(1)
		{
				printf("Enter 1 for Producer, 2 for Consumer and 3 to Exit: ");
				scanf("%d",&choice);
				switch(choice)
				{
						case 1: if(bs==1 && cs!=b)
								{
										producer();
								}
								else
								{
										printf("Unable to Produce\n");
								}
								break;
						case 2: if(bs==1 && cs!=0)
								{
										consumer();
								}
								else
								{
										printf("Unable to Consume\n");
								}
								break;
						case 3: exit(0);

				}
		}
		return 0;
}
