#include <iostream>
#include<fstream>
#include <Windows.h>

using namespace std;
int n = 10;		//Input�ɤ��x�}�j�p
int GraphComplete(int** A, int n);
int temp;

int main()
{
	LARGE_INTEGER ThisTime, ThatTime, PinTime;
	ifstream fin("Input3.txt");		//��J�ɮצW��
	int** A;
	A = new int *[n];

	for (int i = 0; i < n; i++)		//�Ыب�Ū�x�}
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

	cout << "��J���x�}:" << endl;		//���Ū�J���x�}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "���浲�G:" << endl;
	QueryPerformanceFrequency(&PinTime);

	QueryPerformanceCounter(&ThisTime);		//���
	cout << GraphComplete(A, n) << endl;
	QueryPerformanceCounter(&ThatTime);
	if (GraphComplete(A, n) == 1)
		cout << "This graph is complete!" << endl;
	else
		cout << "This graph is not complete!" << endl;

	cout << "����ɶ��G " << (double)(ThatTime.QuadPart - ThisTime.QuadPart) * 1000 / PinTime.QuadPart << "�@��" << endl;		//��ܰ���ɶ�


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