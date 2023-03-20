#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "assign2_d1128309.h"

int main()
{
	int i=0, j=0, n1, n2, num;
	Link L1, L2, L3, L4;
	initial(&L1);
	initial(&L2);
	srand(time(NULL));
	
	do{
		printf("Enter the size \"n1\" (20<=n1<=200) of lienar list L1): ");
		scanf("%d",&n1);
		printf("Enter the size \"n2\" (20<=n2<=200) of lienar list L2): ");
		scanf("%d",&n2);
	}while(n2>200);	
	printf("\n");
	
	while(i<n1){
		num=rand()%1000;
		if (insertElem(&L1,num)>=0) i++;
	}
	
	i=0;
	while(i<n2){
		num=rand()%1000;
		if (insertElem(&L2,num)>=0) i++;
	}
	
	printf("Linear List L1:\n");
    printList(L1);
	printf("Linear List L2:\n");
    printList(L2);
	
	printf("Linear List L3: \n");
	L3=append(L1,L2);
	sort(&L3);
    printList(L3);
	printf("Linear List L4: \n");
	L4=join(L1,L2);
	sort(&L4);
    printList(L4);
//	printf("%d",getElem(L1,8));
	while(deleteElem(&L1,getElem(L1,0))!=-1);
	while(deleteElem(&L2,getElem(L2,0))!=-1);
	while(deleteElem(&L3,getElem(L3,0))!=-1);
	while(deleteElem(&L4,getElem(L4,0))!=-1);
	return 0;
}
