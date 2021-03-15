#pragma once
#define _CRT_SECURE_NO_WARNINGS
//структура однозвязного списку для даних про студентів 
struct students {
    char сSurname[40];
    char cName[40];
    char cDate[10];
    int nMarks[3];
    struct students* next;
} ;

//зчитування даних про n студентів
//при виклику передається адреса для зберігання даних про першого студента
//динамічна память для кожного студента виділяється в функції
void ReadStudents( int n, struct students** pStart);

//виведення даних про всіх студентів у вигляді таблиці
//при виклику передається вказівник на першого студента
void PrintStudents(struct students* pstart);

//виведення даних про студентів з оцінкою 2
//при виклику передається вказівник на першого студента
void PrintBadStudents(struct students* pstart);

//виведення середніх оцінок кожного студента
//при виклику передається вказівник на першого студента
void PrintAverMarks(struct students* pstart);

//обчислює кількість студентів
//при виклику передається вказівник на першого студента
//повертає їх кількість 
int NumOfStudents(struct students* pstart);

//сортування студентів за прізвищем
//при виклику передається вказівник на першого студента
//повертає нову голову
struct students* SortStudents(struct students* proot);

//пошук студента з найнижчим середнім балом та його видалення
//при виклику передається вказівник на першого студента
//повертає новий вказівник на першого студента
struct students* RemoveTheWorst(struct students* pstart);