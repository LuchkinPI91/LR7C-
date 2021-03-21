#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <tchar.h>
#include <clocale>
#include <malloc.h>
#include <string>
#include <algorithm>
using namespace std;
#define M 20
#define N 30
size_t remove_ch(char* s, char ch)           //������� �������� ������������ ��������
{
	size_t i, j;

	j = 0;

	for (i = 0; s[i]; ++i)
		if (s[i] != ch)
			s[j++] = s[i];

	s[j] = '\0';

	return j;
}




class students {
	
public:
	students() {
		a = 0;
		
	}

	students(int a) {
	
		this->a = a;
	
	}
	

	void input(std::string student_last_name[N], int grn[N], float avg1[N], float avg2[N], int n) {

		for (int i = 0;i < n;i++) {
			last_name[i] = student_last_name[i];
			group[i] = grn[i];
			avg_ball1[i] = avg1[i];
			avg_ball2[i] = avg2[i];


		}

	}

	void output(int n) {
		for (int i = 0;i < n;i++) {
			std::cout << "|" << last_name[i];
			printf("| %d | %0.2f | %0.2f |",group[i], avg_ball1[i], avg_ball2[i]);
			student_book.print(i);

		}
	}

	void inid(int n, int id[M]) {

		student_book.inid(n, id);

	}

	


	void sort(int n) {
		std::string ln;
		int* g = new int();
		float* a1 = new float();
		float* a2 = new float();
		int* ID = new int();
		int* ID1 = new int();
		for (int i = 0;i < n - 1;i++) {
			for (int j = n - 1;j > i;j--)
				if (group[j - 1] < group[j]) {
					ln = last_name[j - 1];
					last_name[j - 1] = '\0';
					last_name[j - 1] = last_name[j];
					last_name[j] = '\0';
					last_name[j] = ln;
					ln[0] = '\0';


					*g = group[j - 1];
					group[j - 1] = group[j];
					group[j] = *g;

					*a1 = avg_ball1[j - 1];
					avg_ball1[j - 1] = avg_ball1[j];
					avg_ball1[j] = *a1;

					*a2 = avg_ball2[j - 1];
					avg_ball2[j - 1] = avg_ball2[j];
					avg_ball2[j] = *a2;

					*ID = student_book.get_id(j - 1);
					*ID1 = student_book.get_id(j);
					student_book.setId(j - 1, *ID1);
					student_book.setId(j, *ID);




				}


		}

		delete g;
		delete a1;
		delete a2;
		delete ID;
		delete ID1;

	}// ���������� �� ����������� ������ ������

	void zadanie(int n) {
		printf("��������, � ������� ������ �� 2 ������� ����, ��� �� ������\n");
		for (int i = 0;i < n;i++) {
			if (avg_ball2[i] < avg_ball1[i]) {

				std::cout<<"�������:" << last_name[i];

			}

		}
	}

	float& sumofballs1(int n) {// ������� �� ������

		float sum1 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];

		
		}

		return sum1;

	}

	float* sumofballs2(int n) {//

		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum2 += avg_ball2[i];


		}

		return &sum2;

	}

	void sumofballs(int n) {

		float sum1 = 0;
		float sum2 = 0;

		for (int i = 0;i < n;i++) {

			sum1 += avg_ball1[i];

			sum2 += avg_ball2[i];
		}

		sum = sum1 + sum2;
		printf("����� ������ �� 2 ��������:%f\n", sum);

	}
	
	students operator+(students c1) {

		return students(c1.a);
	}

	students operator++(void) {
	
		a++;
		return *this;
	}
	students operator++(int a) {

		this->a++;
		return *this;
	}


	
	 void out_a() {
	
		printf("a: %d\n", a);
	}
	
private:
	std::string last_name[N];// ������� ��������
	int group[N];//����� ������ ��������
	float avg_ball1[N];//������� ���� �� 1 �������
	float avg_ball2[N];//������� ���� �� 2 �������
	float sum;
	int a;
	
	class Student_book
	{
	private:
		int id[M];
	public:
		int inid(int n, int id[M]) {

			for (int i = 0;i < n;i++) {

				this->id[i] = id[i];// ������������� this, ����� ������������ ��������� � ���������� ������ 

			}
			return 0;
		}
		int print(int i) {

			printf(" %d\n", id[i]);
			return 0;
		}

		int get_id(int i)
		{

			return id[i];

		}
		void setId(int i, int id) {

			this->id[i] = id;
		}

	};
	Student_book student_book;
	friend void friendf(students& student);
	
};




void friendf(students& student)//friend �������
{ 
	student.sum = 0;
	printf("����� ������ ��������\n");
	
}




int _tmain() {
	std::string Ln[N];
	int n;
	float* avgb1 = new float[N];
	int* id1 = new int[N];
	setlocale(LC_ALL, "russian");
	printf("������� ���-�� ����������:");
	do {
		scanf("%d", &n);

		if (n < 0 || n>30)
		{
			printf("���-�� ���������� ������ ���� ������ 30, �� �������� 1!\n");
		}

	} while (n < 0 || n>30);
	float* avgb2 = (float*)calloc(n, sizeof(float));
	int* groupn = (int*)malloc(n * sizeof(int));
	for (int i = 0;i < n;i++) {
		while (getchar() != '\n');
		printf("������� �������:");
		std::getline(std::cin, Ln[i]);
		printf("������� ����� ������:");
		scanf("%d", &groupn[i]);
		while (getchar() != '\n');
		printf("������� ������� ���� �� 1 �������:");
		scanf("%f", &avgb1[i]);
		while (getchar() != '\n');
		printf("������� ������� ���� �� 2 �������:");
		scanf("%f", &avgb2[i]);
		while (getchar() != '\n');
		printf("������� ����� �������:");
		scanf("%d", &id1[i]);
	}
	students* student = new students();
	students st;
	students student1;
	student->input(Ln, groupn, avgb1, avgb2, n);
	student->inid(n, id1);
	printf("�� ����������:\n");
	student->output(n);
	student->sort(n);
	printf("����� ����������:\n");
	student->output(n);
	student->zadanie(n);
	printf("����� ������ �� 1 �������:%f\n", student->sumofballs1(n));
	printf("����� ������ �� 2 �������:%f\n", *student->sumofballs2(n));
	student->sumofballs(n);
	printf("\n");
	friendf(student1);
	
	students c1(20);
	students c2(10);
	students c3 = c1 + c2;
	c3.out_a();

	students d, d1(5);
	printf("�� ����������(++a):");
	d.out_a();
	printf("�� ����������(a++):");
	d1.out_a();
	++d;
	d1++;
	printf("����� ����������(++a):");
	d.out_a();
	printf("����� ����������(a++):");
	d1.out_a();
	delete[] avgb1;
	delete[] id1;
	free(groupn);
	free(avgb2);
	return 0;
}