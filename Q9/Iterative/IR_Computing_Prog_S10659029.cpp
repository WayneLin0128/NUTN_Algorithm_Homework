#include <iostream>
#include<fstream>
#include <Windows.h>

using namespace std;
int n = 200;		//Input�ɤ���ƭӼ�
int Riddle(int* A, int n);
int temp;

int main()
{
	LARGE_INTEGER ThisTime, ThatTime, PinTime;
	ifstream fin("Input2.txt");		//��J�ɮצW��
	int* A;
	A = new int[n];

	for (int i = 0; i < n; i++)		//Ū��
	{
		fin >> A[i];
	}

	cout << "��J�ɮ�: " << endl;
	for (int i = 0; i < n; i++)		//��XŪ�ɵ��G
	{
		cout << "A[" << i + 1 << "]: " << A[i] << endl;
	}

	cout << endl << "���浲�G:" << endl;
	QueryPerformanceFrequency(&PinTime);

	QueryPerformanceCounter(&ThisTime);		//���
	cout << Riddle(A, n) << endl;
	QueryPerformanceCounter(&ThatTime);

	cout << "����ɶ��G " << (double)(ThatTime.QuadPart - ThisTime.QuadPart) * 1000 / PinTime.QuadPart << "�@��" << endl;		//��ܰ���ɶ�

	system("PAUSE");
	return 0;
}

//�ϥ�for�j��
int Riddle(int* A, int n) {
	if (n == 1) {		//�}�C���u���@�ӭ�
		return(A[0]);
	}
	else {
		temp = A[n - 1];	
		for (int i = (n - 2); i >= 0; i--)	//�N�}�C���C�ӭȤ���L�@��
		{
			if (temp > A[i]) {		//���temp�P�}�C���C�ӭ�
				temp = A[i];		//�d�U���p����
			}
		}
	}
	return(temp);		//�^��temp
}