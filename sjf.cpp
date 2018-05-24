	#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

#define MAX 20

struct process{
	int pro;
	int cpuB;
	int timeXh;
};

struct timee{
    int timeWait;
    int timePro;
};

void nhap(process test[],int &n)
{
	cout << "Nhap so tien trinh: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "\tNhap tien trinh " << i+1 << endl;
		cout << "\t\tNhap ten tien trinh: ";
		fflush(stdin);gets(test[i].pro);
		cout << "\t\tNhap thoi gian xuat hien: ";
		cin >> test[i].timeXh;
		cout << "\t\tNhap thoi gian xu li: ";
		cin >> test[i].cpuB;
	}
}

void xuat(process test[], int n)
{
	cout << "Bang tien trinh la: " << endl;
	cout << setw(10) << "Process" << setw(7) << "Txh" << setw(7) << "CPUb" << endl;
	for(int i=0; i<n;i++)
	{
		cout << setw(10) << test[i].pro << setw(7) << test[i].timeXh << setw(7) << test[i].cpuB << endl;
	}
}


int main()
{
	process prox[MAX];
	timee timeInit[MAX];
	return 0;
}
