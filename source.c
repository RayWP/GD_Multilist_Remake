#include "header.h"

Person makePerson(string name, int age)
{
	Person person;
	strcpy(person.name, name);
	person.age = age;

	return person;
}

void createEmpty(ListParent *L)
{
	(*L).first=NULL;
}
int isEmpty(ListParent L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;
}
int HaveChild(adrParent P)
{
	if(P->firstChild!=NULL)
		return 1;
	else
		return 0;	
}
adrParent AlokasiP(Person person)
{
	adrParent P;
	P=(adrParent) malloc(sizeof(Parent));
	P->person=person;
	P->nextParent=NULL;
	P->firstChild=NULL;
	return P;
}
adrParent FindParent(ListParent L,string name)
{
	
	adrParent P=L.first;
	while(P!=NULL)
	{
		if(strcmpi(P->person.name,name)!=0) 
		{
			P=P->nextParent;
		} else {
			return P;
		}
	}

	return P;
}
void insertFirstParent(ListParent *L,Person databaru)
{
	adrParent P;
	P=AlokasiP(databaru);
	P->nextParent=(*L).first;
	(*L).first=P;
	printf("INSERTED FIRST PARENT");
}
void insertLastParent(ListParent *L,Person databaru)
{
	adrParent P,last;
	if(isEmpty(*L))
		insertFirstParent(&(*L),databaru);
	else{
		P=AlokasiP(databaru);
		last=(*L).first;
		while(last->nextParent!=NULL)
		{
			last=last->nextParent;
		}
		last->nextParent=P;
		printf("INSERTED LAST PARENT");
	}	
}
void insertAfterParent(ListParent *L,string datasebelum,Person databaru)
{
	adrParent P, cari;
	cari=FindParent((*L),datasebelum);
	if(isEmpty(*L))
		insertFirstParent(&(*L),databaru);
	else if(cari==NULL)
		printf("Data tidak ditemukan");
	else{
		P=AlokasiP(databaru);
		P->nextParent=cari->nextParent;
		cari->nextParent=P;
		printf("INSERTED");	
	}		
}
void deleteFirstParent(ListParent *L)
{
	adrParent del;
	if(isEmpty(*L))
		printf("List kosong");
	else
	{
		del=(*L).first;
		(*L).first=(*L).first->nextParent;
		free(del);
		printf("DELETED FIRST PARENT");	
	}	
}
void deleteLastParent(ListParent *L)
{
	adrParent bantu, del;
	if(isEmpty(*L))
		printf("List kosong");
	else{
		if((*L).first->nextParent==NULL) {
			deleteFirstParent(&(*L));
		}else {
			bantu=(*L).first;
			while(bantu->nextParent->nextParent!=NULL)
			{
				bantu=bantu->nextParent;
			}
			del=bantu->nextParent;
			bantu->nextParent=NULL;
			free(del);
			printf("DELETED LAST Parent");
		}	
	}	
}
void deleteAfterParent(ListParent *L, string datasebelum)
{
	adrParent del,cari;
	cari=FindParent((*L),datasebelum);
	if(cari==NULL)
		printf("Data tidak ditemukan");
	else{
		if(cari->nextParent==NULL)
			printf("Data sebelum terletak di akhir list");
		else{
			del=cari->nextParent;
			cari->nextParent=cari->nextParent->nextParent;
			free(del);
			printf("DELETED");
		}	
	}	
}
void printAll(ListParent L)
{
	adrParent P;
	adrChild C;
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=L.first;
		while(P!=NULL)
		{
			printf("\nParent name : %s",P->person.name);
			printf("\nParent age : %d",P->person.age);
			if(HaveChild(P))
			{
				C=P->firstChild;
				printChild(C);
			}
			else
				printf("\nBelum ada anak");
			P=P->nextParent;
		}
	}		
}
adrChild AlokasiC(char id)
{
	adrChild C;
	C=(adrChild) malloc(sizeof(Child));
	C->id=id;
	C->nextChild=NULL;
	return C;
}
void insertFirstChild(ListParent *L,string name, char idC)
{
	adrChild C;
	adrParent P;
	P=FindParent((*L),name);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=AlokasiC(idC);
		C->nextChild=P->firstChild;
		P->firstChild=C;
	}	
}
void insertLastChild(ListParent *L,string name, char idC)
{
	adrChild C, lastChild;
	adrParent P;
	P=FindParent((*L),name);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChild(P))
		insertFirstChild(&(*L),name,idC);
	else
	{
		C=AlokasiC(idC);
		lastChild=P->firstChild;
		while(lastChild->nextChild!=NULL)
		{
			lastChild=lastChild->nextChild;
		}
		lastChild->nextChild=C;
	}				
}
void deleteFirstChild(ListParent *L,string name)
{
	adrChild del;
	adrParent P;
	P=FindParent((*L),name);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChild(P))			
		printf("\nTidak punya anak");
	else{
		del=P->firstChild;
		P->firstChild=P->firstChild->nextChild;
		free(del);
		printf("DELETED");
	}	
}
void deleteLastChild(ListParent *L,string name)
{
	adrChild del, bantu;
	adrParent P,temp;
	P=FindParent((*L),name);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChild(P))			
		printf("\nTidak punya anak");
	else if(P->firstChild->nextChild==NULL)
		deleteFirstChild(&(*L),name);
	else{
		bantu=P->firstChild;
		while(bantu->nextChild->nextChild!=NULL)
		{
			bantu=bantu->nextChild;
		}
		del=bantu->nextChild;
		bantu->nextChild=NULL;
		free(del);
		printf("DELETED");		
	}				
}
void printChild(adrChild C)
{
	if(C!=NULL)
	{
		printf("\nList ID Anak");
		while(C!=NULL)
		{
			printf("\n%c",C->id);
			C=C->nextChild;
		}
	}
}
void printChildByParent(ListParent L,string name)
{
	adrParent P;
	adrChild C;
	if(isEmpty(L))
		printf("List kosong");
	else
	{
		P=FindParent(L,name);
		if(P==NULL)
			printf("\nParent tdk ada");
		else
		{
			printf("\nNama Parent : %s",P->person.name);
			if(!HaveChild(P))			
				printf("\nTidak punya anak");	
			else
			{
				C=P->firstChild;
				printChild(C);
			}	
		}	
	}		
}
