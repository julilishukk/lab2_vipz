#include "Functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>


void ReadStudents (int n, struct students **pStart){
  struct students example;
  struct students* temp = (struct students*)malloc(sizeof(struct students));
  struct students* last_p = (struct students*)malloc(sizeof(struct students));
  for (int i = 1; i <= n; i++) {
    scanf("%s", &example.ÒSurname);
    scanf("%s", &example.cName);
    scanf("%s", &example.cDate);
    scanf("%d %d %d", &example.nMarks[0], &example.nMarks[1], &example.nMarks[2]);
    strcpy(temp->ÒSurname, example.ÒSurname);
    strcpy(temp->cName, example.cName);
    strcpy(temp->cDate, example.cDate);
    temp->nMarks[0] = example.nMarks[0];
    temp->nMarks[1] = example.nMarks[1];
    temp->nMarks[2] = example.nMarks[2];
    if (i==1)*pStart = temp;
    struct students* next_p = (struct students*)malloc(sizeof(struct students));
    temp->next = next_p;
    last_p = temp;
    temp = next_p;
 }
  last_p->next = NULL;
 
 }
//--------------------------------------------------------------------------------
void PrintStudents(struct students* pStart)
{
    int n = 44;
    for (int i = 1; i <= n; i++) 
        printf("-");
    printf("\n");
    while (pStart) {
        printf("|%10s |%8s |%s |%d |%d |%d |\n", pStart->ÒSurname, pStart->cName, pStart->cDate, pStart->nMarks[0], pStart->nMarks[1], pStart->nMarks[2]);
        pStart = pStart->next;
    }
    for (int i = 1; i <= n; i++)
        printf("-");
    printf("\n");
}
//--------------------------------------------------------------------------------
void PrintBadStudents(struct students* pStart)
{
    int n = 44;
    for (int i = 1; i <= n; i++) 
        printf("-");
    printf("\n");
    while (pStart) {
        if (pStart->nMarks[0] == 2 || pStart->nMarks[1] == 2 || pStart->nMarks[2] == 2) 
            printf("|%10s |%8s |%s |%d |%d |%d |\n", pStart->ÒSurname, pStart->cName, pStart->cDate, pStart->nMarks[0], pStart->nMarks[1], pStart->nMarks[2]);
        pStart = pStart->next;
    }
    for (int i = 1; i <= n; i++)
        printf("-");
    printf("\n");
}
//--------------------------------------------------------------------------------
void PrintAverMarks(struct students* pStart)
{
    int n = 33;
    for (int i = 1; i <= n; i++) 
        printf("-");
    printf("\n");
    while (pStart)
    {
        double aver = (pStart->nMarks[0] + pStart->nMarks[1] + pStart->nMarks[2]) / 3.0;
        printf("|%10s |%8s |%lf |\n", pStart->ÒSurname, pStart->cName, aver);
        pStart = pStart->next;
    }
    for (int i = 1; i <= n; i++) 
        printf("-");
    printf("\n");
}
//--------------------------------------------------------------------------------
int NumOfStudents(struct students* pStart)
{
    int k = 0;
    while (pStart) {
        k++;
        pStart = pStart->next;
    }
    return k;
}
//--------------------------------------------------------------------------------
struct students* SortStudents(struct students* pRoot)
{
    struct students* NewRoot = NULL;
    while (pRoot != NULL)
    {
        struct students* Node = pRoot;
        pRoot = pRoot->next;
        if (NewRoot == NULL || strcmp(Node->ÒSurname, NewRoot->ÒSurname) < 0) {
            Node->next = NewRoot;
            NewRoot = Node;
        } else
        {
            struct students* Current = NewRoot;
            while (Current->next != NULL && strcmp(Current->next->ÒSurname, Node->ÒSurname) < 0)
            {
                Current = Current->next;
            }
            Node->next = Current->next;
            Current->next = Node;
        }
    }
    return NewRoot;
}
//--------------------------------------------------------------------------------
struct students* RemoveTheWorst(struct students* pStart)
{
    struct students* newfirst = pStart;
    int nPosition = 0, nCurNumber = 0;
    double minn = 6.0;
    while (pStart) {
        nCurNumber++;
        double dAver = (pStart->nMarks[0] + pStart->nMarks[1] + pStart->nMarks[2]) / 3.0;
        if (dAver < minn) {
            minn = dAver; nPosition = nCurNumber; 
        }
        pStart = pStart->next;
    }
    nCurNumber = 1;
    pStart = newfirst;
    if (nPosition != 1) {
        while (1) {
            nCurNumber++;
            struct students* pp = pStart;
            pStart = pStart->next;
            if (nCurNumber == nPosition) {
                pp->next = pStart->next;
                free(pStart);
                break;
            }
        }
    }  else {
        if (pStart->next)  newfirst = pStart->next;
        else newfirst = NULL;
        free(pStart);
    }
    return newfirst;
}

