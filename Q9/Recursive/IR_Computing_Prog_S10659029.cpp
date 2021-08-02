#include <iostream>
#include<fstream>
#include <Windows.h>

using namespace std;
int n = 4500;		//Input檔內整數個數
int Riddle(int* A, int n);
int temp;

int main()
{
	LARGE_INTEGER ThisTime, ThatTime, PinTime;
	ifstream fin("Input3.txt");		//輸入檔案名稱
	int* A;
	A = new int[n];
	
	for (int i = 0; i < n; i++)		//讀檔
	{
		fin >> A[i];
	}

	cout << "輸入檔案: "<< endl;
	for (int i = 0; i < n; i++)		//輸出讀檔結果
	{
		cout << "A[" << i + 1 << "]: "<<A[i] << endl;
	}

	cout << endl << "執行結果:" << endl;
	QueryPerformanceFrequency(&PinTime);

	QueryPerformanceCounter(&ThisTime);		//顯示
	cout <<"最小值為: " << Riddle(A, n) << endl;
	QueryPerformanceCounter(&ThatTime);

	cout << "執行時間： " << (double)(ThatTime.QuadPart - ThisTime.QuadPart) * 1000 / PinTime.QuadPart <<"毫秒"<< endl;		//顯示執行時間

	system("PAUSE");
	return 0;
}

//遞迴function
int Riddle(int* A, int n) {
	if (n == 1)		//陣列內只有一個值
		return A[0];
	else {
		temp = Riddle(A, n - 1);	//遞迴呼叫
		if (temp <= A[n - 1])		//比較temp與陣列內最後一個值並回傳較小的
			return temp;			
		else
			return(A[n - 1]);		
	}		

}