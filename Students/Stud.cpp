#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include "Functions.h"

//вказівник на першого студента
struct students* pFirst;
struct students* p;
int main()
{
    FILE *fp=freopen("Input.txt", "r",stdin);
    // FILE* fp2 = freopen("Ouput.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    if (fp)
        ReadStudents(n, &pFirst);
    else return 1;
    fclose(fp);
    printf("All students:\n");
    PrintStudents(pFirst);
    pFirst = SortStudents(pFirst);
    printf("Sorted students who have mark 2:\n");
    PrintBadStudents(pFirst);
    printf("Average mark:\n");
    PrintAverMarks(pFirst);
    for (int i = 0; i < 3; i++) {
        pFirst=RemoveTheWorst(pFirst);
    }  
    printf("After removing bad students:\n");
    PrintStudents(pFirst);
    printf("Number of students = %d\n", NumOfStudents(pFirst));
    

}




