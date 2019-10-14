#include <iostream>
using namespace std;


void MatrixMultiply(int matrix1[] , int matrix1Height, int matrix1Width, int matrix2[], int matrix2Height, int matrix2Width)
{
	int matrix3Height = 1, matrix3Width = 1;

	if (matrix1Width != matrix2Height)
	{
		cout << '\n';
		cout << "Resultant Matrix: Matrices not compatible\n";
		return ;
	}

	matrix3Height = matrix1Height;
	matrix3Width = matrix2Width;

	int* matrix3 = new int[matrix3Height * matrix3Width];

	int product = 0;

	for (int i = 0; i < matrix3Height; i++)
		for (int j = 0; j < matrix3Width; j++)
		{
			for(int x = 0; x < matrix1Width; x++)
				{
					product += matrix1[(i * matrix1Width) + (x)] * matrix2[(x * matrix2Width) + (j)];
				}
			matrix3[i * matrix3Width + j] = product;
			product = 0;
		}

	cout << '\n';
	cout << "Resultant Matrix: " << matrix3Height << ' ' << 'X' << ' ' << matrix3Width << '\n';

	for (int i = 0; i < matrix3Height; i++)
	{
		for (int j = 0; j < matrix3Width; j++)
		{
			cout << matrix3[i * matrix3Width + j] << ' ';
		}
		cout << '\n';
	}
	return;
}

int main()
{
	int matrix1Height = 1, matrix1Width = 1;

	cout << "Input Matrix 1:\n";
	cout << "Number of rows: ";
	cin >> matrix1Height;
	cout << "Number of columns: ";
	cin >> matrix1Width;

	int* matrix1 = new int[matrix1Height * matrix1Width];

	for (int i = 0; i < matrix1Height; i++)
		for (int j = 0; j < matrix1Width; j++)
		{
			cout << "Enter Element [" << i << ", " << j << "]: ";
			cin >> matrix1[i * matrix1Width + j];
		}

	int matrix2Height = 1, matrix2Width = 1;

	cout << "Input Matrix 2:\n";
	cout << "Number of rows: ";
	cin >> matrix2Height;
	cout << "Number of columns: ";
	cin >> matrix2Width;

	int* matrix2 = new int[matrix2Height * matrix2Width];

	for (int i = 0; i < matrix2Height; i++)
		for (int j = 0; j < matrix2Width; j++)
		{
			cout << "Enter Element [" << i << ", " << j << "]: ";
			cin >> matrix2[i * matrix2Width + j];
		}

	MatrixMultiply(matrix1, matrix1Height, matrix1Width, matrix2, matrix2Height, matrix2Width);

	return 0;
}
