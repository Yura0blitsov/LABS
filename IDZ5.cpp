#include <iostream>
using namespace std;

void print_array(double** arr, const int size1, const int size2);
double put_value(void);
double** array_input(const int size1, const int size2);
int put_size(void);

double** mult_mat(double** arr1, const int m1, const int n1, double** arr2, const int m2, const int n2)
{
	if (arr1 != nullptr || arr2 != nullptr)
	{
		if (m2 != n1)
		{
			cout << "Отсутствует! Матрицы некорректного размера!";
			exit(1);
		}
		else
		{
			const int size_m = m1;
			const int size_n = n2;
			double** arr_temp = new double* [size_m];

			for (int i = 0; i < size_m; i++)
			{
				arr_temp[i] = new double[size_n];
			}

			for (int i = 0; i < size_m; i++)
			{
				for (int j = 0; j < size_n; j++)
				{
					arr_temp[i][j] = 0;
				}
			}

			for (int i = 0; i < m1; i++)
			{
				for (int j = 0; j < n2; j++)
				{
					arr_temp[i][j] = 0;
					for (int k = 0; k < n1; k++)
						arr_temp[i][j] += arr1[i][k] * arr2[k][j];
				}
			}
			
			return arr_temp;
		}
	}
	else
	{
		cout << "Ошибка!" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "//////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "//////////////// Эта программа вычисляет произведение 2-х матриц  ////////////" << endl;
	cout << "/////////////////////////////////////////////////////////////////////////////" << endl << endl;
	system("pause");
	system("cls");
	cout << "Введите количество строк матрицы №1: " << endl;
	const int m1 = put_size();
	cout << "Введите количество столбцов матрицы №1: " << endl;
	const int n1 = put_size();
	double** arr1 = array_input(m1,n1);
	cout << "Матрица №1 :" << endl;
	print_array(arr1, m1, n1);

	cout << "Введите количество строк матрицы №2: " << endl;
	const int m2 = put_size();
	cout << "Введите количество столбцов матрицы №2: " << endl;
	const int n2 = put_size();
	double** arr2 = array_input(m2, n2);
	cout << "Матрица №2 :" << endl;
	print_array(arr2, m2, n2);

	cout << "Матрица результата :" << endl;
	double** arr_rez = mult_mat(arr1, m1, n1, arr2, m2, n2);
	print_array(arr_rez, m1, n2);
}


int put_size(void)
{
	int size = 0;
	do
	{
		if (!cin.good())
		{
			cout << "Некорректный ввод числа! Повторите попытку!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		cin >> size;
		cin.clear();
		cin.ignore(100, '\n');
		if (size <= 0)
		{
			cout << "Размер должен быть положительным числом!" << endl;
		}
	} while (!cin.good() || size <= 0);
	return size;
}

void print_array(double** arr, const int size1, const int size2)
{
	if (arr != nullptr)
	{
		const int size_m = size1;
		const int size_n = size2;
		
		for (int i = 0; i < size_m; i++)
		{
			
			for (int j = 0; j < size_n; j++)
			{
				cout << "\t" << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Ошибка памяти!" << endl;
		exit(1);
	}
}

double put_value(void)
{
	double value = 0;
	do
	{
		if (!cin.good())
		{
			cout << "Некорректный ввод числа! Повторите попытку!" << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
		cin >> value;

	} while (!cin.good());
	return value;

}


double** array_input(const int size1, const int size2)
{
	const int size_m = size1;
	const int size_n = size2;
	double** arr_temp = new double* [size_m];

	for (int i = 0; i < size_m; i++)
	{
		arr_temp[i] = new double[size_n];
	}

	for (int i = 0; i < size_m; i++)
	{
		for (int j = 0; j < size_n; j++)
		{
			arr_temp[i][j] = 0;
		}
	}
	cout << "Введите элементы матрицы поочерёдно:" << endl;

	for (int i = 0; i < size_m; i++)
	{
		for (int j = 0; j < size_n; j++)
		{
			cout << "Введите элемент a[" << i + 1 << "]" << "[" << j + 1 << "] : ";
			arr_temp[i][j] = put_value();
		}
	}

	return arr_temp;
}
