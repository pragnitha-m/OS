#include <stdio.h>
void main(){
		int n;
		printf("Enter the no.of Pages: ");
		scanf("%d",&n);
		int pno[n-1];
		printf("\nEnter the page numbers\n");
		for(int i=0;i<n-1;i++){
				scanf("%d ",&pno[i]);
		}
		int m;
		printf("Enter length of physical memory: ");
		scanf("%d ",&m);
		int pm[m];
		for(int i=0;i<m;i++){
				pm[i]=-1;
		}
		int hit=0,miss=0,mini=0;
		for(int i=0;i<n;i++){
				int count=0,c=0;
				for(int j=0;j<m;j++){
						if(pm[j]!=pno[i] && pm[j]==-1){
								miss++;
								count++;
								pm[j]=pno[i];
								break;
						}
						else if(count==m && pm[j]!=pno[i]){
								c++;
								if(c==m){
										pm[mini]=pno[i];
										if(mini==(m-1)){
												mini=0;
										}
										else{
												mini++;
										}
								}
						}
						else if(pm[j]==pno[i]){
								hit++;
								break;
						}
				}
		}
		printf("\nNo.of hits: %d\nNo.of page faults: %d",hit,miss);
}

Output:
Enter the no.of Pages: 6

Enter the page numbers
3 2 1 3 4 5
Enter length of physical memory: 3

No.of hits: 1
No.of page faults: 5
