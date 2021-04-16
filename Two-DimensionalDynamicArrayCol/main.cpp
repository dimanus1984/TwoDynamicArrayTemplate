#include<iostream>
using namespace std;

#define tab "\t"

int** CreateArr(int m, int n);
void FillRand(int** arr, int m, int n);
template<typename T>void Print(T** arr, const int m, const int n);
template<typename T>void Clear(T** arr, int m);
template<typename T>void push_col_back(T** arr, const int m, int& n);
template<typename T>void push_col_front(T** arr, const int m, int& n);
template<typename T>void insert_col(T** arr, const int m, int& n, int numPos);
template<typename T>void pop_col_back(T**& arr, const int m, int& n);
template<typename T>void pop_col_front(T** arr, const int m, int& n);
template<typename T>void erase_col(T**& arr, const int m, int& n, int numPos);

void main()
{
	setlocale(LC_ALL, "");
	int row;       // ���������� �����
	int col;       // ���������� ��������
	int numMenu; // ���� ������ �������
	int numPos;  // ����� ������� � �������
	cout << "������� ���������� �����: "; cin >> row;
	cout << "������� ���������� ��������� ������ (��������): "; cin >> col;
	system("cls");
	int** arr = CreateArr(row, col);
	FillRand(arr, row, col);
	Print(arr, row, col);
	do
	{
		cout << endl;
		cout << "�������� ����� �������: ��� �� ������ ������� � ��������:" << endl;
		cout << "1.�������� ������� ����������� '0' � �����  ���������� ������� " << endl;
		cout << "2.�������� ������� ����������� '0' � ������ ���������� �������" << endl;
		cout << "3.�������� ������� ����������� '0' � ��������� ������ �� ���������� �������" << endl;
		cout << "4.�������  ������� � ����� ���������� �������" << endl;
		cout << "5.�������  ������� � ������ ���������� �������" << endl;
		cout << "6.�������  ������� �� ���������� ������� �� ���������� �������" << endl;
		cout << "0.�����" << endl;
		cin >> numMenu;

		switch (numMenu)
		{
		case 0:
			break;
		case 1:
			system("cls");
			push_col_back(arr, row, col);
			Print(arr, row, col);
			break;
		case 2:
			system("cls");
			push_col_front(arr, row, col);
			Print(arr, row, col);
			break;
		case 3:
			cout << "������� ����� ������� ��� �������: "; cin >> numPos;
			if (numPos > col)
			{
				cout << "������ - �� ������ �����!!!";
				continue;
			}
			system("cls");
			insert_col(arr, row, col, numPos);
			Print(arr, row, col);
			break;
		case 4:
			system("cls");
			pop_col_back(arr, row, col);
			Print(arr, row, col);
			break;
		case 5:
			system("cls");
			pop_col_front(arr, row, col);
			Print(arr, row, col);
			break;
		case 6:
			cout << "������� ����� ������� ��� ��������: "; cin >> numPos;
			if (numPos > col)
			{
				cout << "������ - �� ������ �����!!!";
				continue;
			}
			system("cls");
			erase_col(arr, row, col, numPos);
			Print(arr, row, col);
			break;
		default:
			cout << "ERROR - ��� ������ ������ �������!!!" << endl;
			break;
		}
	} while (numMenu != 0);
	Clear(arr, row);
}
//--------------------------------------------------------------------------
// ������� ������ ����������, � ��������� ��� ����� � ��������� �� ���������
int** CreateArr(int m, int n)
{
	int** arr = new int* [m] {};
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}
	return arr;
}
//--------------------------------------------------------------------------
// ��������� ��������� ������������ ������ ���������� �������
void FillRand(int** arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
//--------------------------------------------------------------------------
// ����� ���������� ������������� �������
template<typename T>void Print(T** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
//--------------------------------------------------------------------------
// �������� ��������� ������������� �������
template<typename T>void Clear(T** arr, int m)
{
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
//--------------------------------------------------------------------------
// �������� ������� ����������� '0' � ����� ���������� �������
template<typename T>void push_col_back(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// �������� ������� ����������� '0' � ������ ���������� �������
template<typename T>void push_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// �������� ������� ����������� '0' � ��������� ������ �� ���������� �������"
template<typename T>void insert_col(T** arr, const int m, int& n, int numPos)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			(j < numPos ? buffer[j] : buffer[j + 1]) = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n++;
}
//--------------------------------------------------------------------------
// ������� ������� � ����� ���������� �������
template<typename T>void pop_col_back(T**& arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
//--------------------------------------------------------------------------
// ������� ������� � ������ ���������� �������
template<typename T>void pop_col_front(T** arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}
//--------------------------------------------------------------------------
// ������� ������� �� ���������� ������� �� ���������� �������
template<typename T>void erase_col(T**& arr, const int m, int& n, int numPos)
{
	for (int i = 0; i < m; i++)
	{
		T* buffer = new T[n - 1]{};
		for (int j = 0; j < n; j++)
		{
			buffer[j] = j < numPos ? arr[i][j] : arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	n--;
}