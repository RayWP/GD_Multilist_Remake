#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ListParent L;
	adrParent P;
	adrChild C;
	int menu,id,idP;
	char idC;
	createEmpty(&L);
	
	do{
		system("cls");
		printf("Multilist");
		printf("\n1. Menu Parent");
		printf("\n2. Menu Child");
		printf("\n3. Print All");
		printf(">> : ");scanf("%d",&menu);
		switch(menu)
		{
			case 1 : 
			printf("\n1.Menu Parent");
			printf("\n\t1. Insert First");
			printf("\n\t2. Insert Last");
			printf("\n\t3. Insert After");
			printf("\n\t4. Delete First");
			printf("\n\t5. Delete Last");
			printf("\n\t6. Delete After");
			printf(">> : ");scanf("%d",&menu);
			switch(menu)
			{
			case 1 : 
				printf("\nMasukkan ID parent : ");scanf("%d",&id);
				insertFirstParent(&L,id);
				break;
			case 2 :
				printf("\nMasukkan ID parent : ");scanf("%d",&id);
				insertLastParent(&L,id);
				break;
			case 3 :
				printf("\nMasukkan ID parent : ");scanf("%d",&idP);
				printf("\nMasukkan ID parent yg akan disisipkan data setelahnya : ");scanf("%d",&id);
				insertAfterParent(&L,id,idP);
				break;
			case 4 : deleteFirstParent(&L);
				break;
			case 5 : deleteLastParent(&L);
				break;
			case 6 :
				printf("\nMasukkan ID parent yg akan dihapus : ");scanf("%d",&id); 	
				deleteAfterParent(&L,id);
				break;				
			}
			break;
			case 2 : 
			printf("\n2.Menu Child");
			printf("\n\t1. Insert First");
			printf("\n\t2. Insert Last");
			printf("\n\t3. Delete First");
			printf("\n\t4. Delete Last");			
			printf("\n\t5. Print Child By Parent");
			printf(">> : ");scanf("%d",&menu);
			switch(menu)
			{
				case 1 : 
					printf("\nMasukkan IDParent : ");scanf("%d",&id);
					printf("\nMasukkan IDChild : ");scanf(" %c",&idC);
					insertFirstChild(&L,id,idC);
					break;
				case 2 :
					printf("\nMasukkan IDParent : ");scanf("%d",&id);
					printf("\nMasukkan IDChild : ");scanf(" %c",&idC);
					insertLastChild(&L,id,idC);
					break;		
				case 3 :
					printf("\nMasukkan IDParent : ");scanf("%d",&id);
					deleteFirstChild(&L,id);
					break;
				case 4 : 
					printf("\nMasukkan IDParent : ");scanf("%d",&id);
					deleteLastChild(&L,id);
					break;	
				case 5 : 
					printf("\nMasukkan IDParent : ");scanf("%d",&id);
					printChildByParent(L,id);
					break;											 					
			}
			break;	
			case 3 : 
				printAll(L);
				break;					
		}getch();
	}while(menu!=0);
	return 0;
}
