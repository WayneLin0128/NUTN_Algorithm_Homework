#include <iostream>
#include<fstream>
#include <Windows.h>

using namespace std;
int n = 4500;		//Input�ɤ���ƭӼ�
int Riddle(int* A, int n);
int temp;

int main()
{
	LARGE_INTEGER ThisTime, ThatTime, PinTime;
	ifstream fin("Input3.txt");		//��J�ɮצW��
	int* A;
	A = new int[n];
	
	for (int i = 0; i < n; i++)		//Ū��
	{
		fin >> A[i];
	}

	cout << "��J�ɮ�: "<< endl;
	for (int i = 0; i < n; i++)		//��XŪ�ɵ��G
	{
		cout << "A[" << i + 1 << "]: "<<A[i] << endl;
	}

	cout << endl << "���浲�G:" << endl;
	QueryPerformanceFrequency(&PinTime);

	QueryPerformanceCounter(&ThisTime);		//���
	cout <<"�̤p�Ȭ�: " << Riddle(A, n) << endl;
	QueryPerformanceCounter(&ThatTime);

	cout << "����ɶ��G " << (double)(ThatTime.QuadPart - ThisTime.QuadPart) * 1000 / PinTime.QuadPart <<"�@��"<< endl;		//��ܰ���ɶ�

	system("PAUSE");
	return 0;
}

//���jfunction
int Riddle(int* A, int n) {
	if (n == 1)		//�}�C���u���@�ӭ�
		return A[0];
	else {
		temp = Riddle(A, n - 1);	//���j�I�s
		if (temp <= A[n - 1])		//���temp�P�}�C���̫�@�ӭȨæ^�Ǹ��p��
			return temp;			
		else
			return(A[n - 1]);		
	}		

}