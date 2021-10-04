#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>

typedef char string[100];
typedef struct tChild* adrChild;
typedef struct tParent* adrParent;

typedef struct tChild{
	int id;
	adrChild nextChild;
}Child;

typedef struct tParent{
	char id;
	adrParent nextParent;
	adrChild firstChild;
}Parent;

typedef struct{
	adrParent first;
}ListParent;

void createEmpty(ListParent *L);
int isEmpty(ListParent L);

int HaveChild(adrParent P);
adrParent AlokasiP(int id);
adrParent FindParent(ListParent L,int id);
void insertFirstParent(ListParent *L,int databaru);
void insertLastParent(ListParent *L,int databaru);
void insertAfterParent(ListParent *L,int datasebelum,int databaru);

void deleteFirstParent(ListParent *L);
void deleteLastParent(ListParent *L);
void deleteAfterParent(ListParent *L, int datasebelum);
void printAll(ListParent L);

adrChild AlokasiC(char id);
void printChild(adrChild C);
void insertFirstChild(ListParent *L,int idP, char idC);
void insertLastChild(ListParent *L,int idP, char idC);
void deleteFirstChild(ListParent *L,int idP);
void deleteLastChild(ListParent *L,int idP);
void printChildByParent(ListParent L,int idP);
