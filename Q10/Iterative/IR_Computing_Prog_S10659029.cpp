#include <iostream>
#include<fstream>
#include <Windows.h>

using namespace std;
int n = 10;		//Input檔內矩陣大小
int GraphComplete(int** A, int n);
int temp;

int main()
{
	LARGE_INTEGER ThisTime, ThatTime, PinTime;
	ifstream fin("Input3.txt");		//輸入檔案名稱
	int** A;
	A = new int *[n];

	for (int i = 0; i < n; i++)		//創建並讀矩陣
	{
		A[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> A[i][j];
		}
	}

	cout << "輸入的矩陣:" << endl;		//顯示讀入的矩陣
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "執行結果:" << endl;
	QueryPerformanceFrequency(&PinTime);

	QueryPerformanceCounter(&ThisTime);		//顯示
	cout << GraphComplete(A, n) << endl;
	QueryPerformanceCounter(&ThatTime);
	if (GraphComplete(A, n) == 1)
		cout << "This graph is complete!" << endl;
	else
		cout << "This graph is not complete!" << endl;

	cout << "執行時間： " << (double)(ThatTime.QuadPart - ThisTime.QuadPart) * 1000 / PinTime.QuadPart << "毫秒" << endl;		//顯示執行時間


	system("PAUSE");
	return 0;
}

int GraphComplete(int** A, int n) {
	if (n == 1) {
		return 1;
	}
	else {
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (A[j][i] == 0)
					return 0;
			}
		}
		return (1);
	}
}