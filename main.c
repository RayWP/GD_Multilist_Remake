#include "source.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	ListParent L;
	adrParent P;
	adrChild C;
	int menu,id,idP,age;
	string name, targetName;
	Person person;
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
				printf("\tMasukkan nama: "); fflush(stdin); gets(name);
				printf("\tMasukkan umur: "); scanf("%d", &age);
				person = makePerson(name, age);
				insertFirstParent(&L, person);
				break;
			case 2 :
				printf("\tMasukkan nama: "); fflush(stdin); gets(name);
				printf("\tMasukkan umur: "); scanf("%d", &age);
				person = makePerson(name, age);
				insertLastParent(&L, person);
				break;
			case 3 :
				printf("\tMasukkan nama: "); fflush(stdin); gets(name);
				printf("\tMasukkan umur: "); scanf("%d", &age);
				person = makePerson(name, age);
				printf("\nMasukkan nama parent yg akan disisipkan data setelahnya : "); fflush(stdin); gets(targetName);
				insertAfterParent(&L,targetName,person);
				break;
			case 4 : deleteFirstParent(&L);
				break;
			case 5 : deleteLastParent(&L);
				break;
			case 6 :
				printf("\tMasukkan nama parent yg akan dihapus data setelahnya : : "); fflush(stdin); gets(targetName);
				deleteAfterParent(&L,targetName);
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
					printf("\tMasukkan nama parent: "); fflush(stdin); gets(targetName);
					printf("\nMasukkan IDChild : ");scanf(" %c",&idC);
					insertFirstChild(&L,targetName,idC);
					break;
				case 2 :
					printf("\tMasukkan nama parent: "); fflush(stdin); gets(targetName);
					printf("\nMasukkan IDChild : ");scanf(" %c",&idC);
					insertLastChild(&L,targetName,idC);
					break;		
				case 3 :
					printf("\tMasukkan nama parent: "); fflush(stdin); gets(targetName);
					deleteFirstChild(&L,targetName);
					break;
				case 4 : 
					printf("\tMasukkan nama parent: "); fflush(stdin); gets(targetName);
					deleteLastChild(&L,targetName);
					break;	
				case 5 : 
					printf("\tMasukkan nama parent: "); fflush(stdin); gets(targetName);
					printChildByParent(L,targetName);
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
