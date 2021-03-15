#pragma once
#define _CRT_SECURE_NO_WARNINGS
//��������� ������������ ������ ��� ����� ��� �������� 
struct students {
    char �Surname[40];
    char cName[40];
    char cDate[10];
    int nMarks[3];
    struct students* next;
} ;

//���������� ����� ��� n ��������
//��� ������� ���������� ������ ��� ��������� ����� ��� ������� ��������
//�������� ������ ��� ������� �������� ���������� � �������
void ReadStudents( int n, struct students** pStart);

//��������� ����� ��� ��� �������� � ������ �������
//��� ������� ���������� �������� �� ������� ��������
void PrintStudents(struct students* pstart);

//��������� ����� ��� �������� � ������� 2
//��� ������� ���������� �������� �� ������� ��������
void PrintBadStudents(struct students* pstart);

//��������� ������� ������ ������� ��������
//��� ������� ���������� �������� �� ������� ��������
void PrintAverMarks(struct students* pstart);

//�������� ������� ��������
//��� ������� ���������� �������� �� ������� ��������
//������� �� ������� 
int NumOfStudents(struct students* pstart);

//���������� �������� �� ��������
//��� ������� ���������� �������� �� ������� ��������
//������� ���� ������
struct students* SortStudents(struct students* proot);

//����� �������� � ��������� ������� ����� �� ���� ���������
//��� ������� ���������� �������� �� ������� ��������
//������� ����� �������� �� ������� ��������
struct students* RemoveTheWorst(struct students* pstart);