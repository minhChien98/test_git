	#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<string.h>

using namespace std;

#define MAX 20

struct process{
	int pro;
	int cpuB;
	int timeeXh;
};

struct timeee{
    int timeeWait;
    int timeePro;
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
		cin >> test[i].timeeXh;
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
		cout << setw(10) << test[i].pro << setw(7) << test[i].timeeXh << setw(7) << test[i].cpuB << endl;
	}
}

void xoa(process test[], int &n, int x)
{
	for(int i = x ; i < n ; i++)
		test[i] = test[i+1];
	n--;
}


void KeNgang()
{
	cout << "================";
}



void sapXep(process test[], int n)
{
	for(int i = 0 ; i < n ; i++)
		for(int j = i+1 ; j<n;j++)
			if(test[i].timeeXh > test[j].timeeXh)
            {
                process tam = test[i];
                test[i] = test[j];
                test[j] = tam;
            }
}

void taoGianDoGantt(process test[],timee tinh[], int n)
{
    int timeeBd = 0, dem = 0, x=n;
    while(n)
    {
        if(x==n)
            cout << "\t" << timeeBd;
        if(test[0].timeeXh == 0)
        {
            cout <<"\t" << test[0].pro;
            tinh[dem].timeeWait = timeeBd - test[0].timeeXh;
            tinh[dem].timeePro = tinh[dem].timeeWait + test[0].cpuB;
            dem++;
            timeeBd += test[0].cpuB;
            xoa(test,n,0);
        }
        int minn = test[0].cpuB;
        for(int i = 0; i<n;i++)
            if(test[i].timeeXh < timeeBd && minn > test[i].cpuB)
                minn = test[i].cpuB;
        for(int i = 0; i<n;i++)
            if(test[i].timeeXh < timeeBd && minn == test[i].cpuB)
            {

                cout << "\t" << timeeBd;
                cout <<"\t" << test[i].pro;
                tinh[dem].timeeWait =timeeBd - test[i].timeeXh;
                tinh[dem].timeePro = tinh[dem].timeeWait + test[i].cpuB;
                dem++;
                timeeBd += test[i].cpuB;
                xoa(test,n,i);
            }
        if(n==0)
            cout << "\t" << timeeBd;
    }
}

void tinhThoiGian(timee tinh[], int n)
{
    float timeeeCho, timeeXuLi;
    for(int i=0; i<n;i++)
    {
        timeeCho += tinh[i].timeeWait;
        timeeXuLi += tinh[i].timeePro;
    }
    timeeCho/=n;
    timeeXuLi/=n;
    cout << endl << "Thoi gian cho trung binh la: " << timeeCho;
    cout << endl << "Thoi gian xu li trung binh la: " << timeeXuLi;
}


int main()
{
	process prox[MAX];
	timeee timeeInit[MAX];
	return 0;
}
