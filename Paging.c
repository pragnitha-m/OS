#include <stdio.h>
#define MAX 50
int main(){
         int page[MAX],i,n,f,ps,off,pno;
         int choice=0;
         printf("\nEnter the no.of pages in memory: ");
         scanf("%d",&n);
         printf("\nEnter page size: ");
         scanf("%d",&ps);
         printf("\nEnter the no.of frames: ");
         scanf("%d",&f);
         for(i=0;i<n;i++)
                 page[i]=-1;
         printf("\nEnter the page table\n");
         printf("(Enter frame number as -1 if that page is not present in any frame)\n");
         printf("\npage no\tframe no\n");
         for(i=0;i<n;i++){
                 printf("\n%d\t\t",i);
                 scanf("%d",&page[i]);
         }
         do{
                 printf("\nEnter the logical address(i.e,page no & offset): ");
                 scanf("%d %d",&pno,&off);
                 if(page[pno]==-1)
                         printf("\nThe required page is not available in any of the frames");
                 else
                         printf("\nPhysical address (i.e, frame no & offset): %d,%d",page[pno],off);
                 printf("\nTo continue press '1' & To exit press '0': ");
                 scanf("%d",&choice);
         }while(choice==1);
         return 1;
}
