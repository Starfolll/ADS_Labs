#include "pch.h"
#include <list>
#include <vector>
#include <iostream>

using namespace std;

void quest_1() {
	int matrixSize = 7;
	int matrix[7][7];
	
	vector <int> list1_Z;
	vector <int> list1_R;
	vector <int> list2_R;
	vector <int> list1_S;

	int countTotalElems = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		int countElems = 0;
		for (int ii = 0; ii < matrixSize; ii++)
		{
			matrix[i][ii] = rand() % 2 == 0 ? rand() % 10 : 0;

			if (matrix[i][ii] != 0) {
				list1_Z.push_back(matrix[i][ii]);
				list1_R.push_back(i);
				list1_S.push_back(ii);

				countTotalElems++;
				countElems++;
			}
			cout << matrix[i][ii] << " ";
		}

		list2_R.push_back(countTotalElems - countElems + 1);
		cout << "\n";
	}

	cout << "\n" << "List _1_ Z = ";
	for (int i = 0; i < list1_Z.size(); i++)
	{
		cout << list1_Z[i] << " ";
	}

	cout << "\n" << "List _1_ R = ";
	for (int i = 0; i < list1_R.size(); i++)
	{
		cout << list1_R[i] << " ";
	}

	cout << "\n" << "List _1_ S = ";
	for (int i = 0; i < list1_S.size(); i++)
	{
		cout << list1_S[i] << " ";
	}

	cout << "\n\n" << "List _2_ R = ";
	for (int i = 0; i < list2_R.size(); i++)
	{
		cout << list2_R[i] << " ";
	}
	cout << "\n";
}

void quest_2() {
	int matrixSize = 5;

	int matrix1[5][5];
	int matrix2[5][5];

	vector <int> list1_Z;
	vector <int> list1_R;
	vector <int> list1_S;

	vector <int> list2_Z;
	vector <int> list2_R;
	vector <int> list2_S;

	int countTotalElems1 = 0;
	int countTotalElems2 = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		int countElems1 = 0;
		int countElems2 = 0;
		for (int ii = 0; ii < matrixSize; ii++)
		{
			matrix1[i][ii] = rand() % 2 == 0 ? rand() % 10 : 0;
			matrix2[i][ii] = rand() % 2 == 0 ? rand() % 10 : 0;

			if (matrix1[i][ii] != 0) {
				list1_Z.push_back(matrix1[i][ii]);
				list1_S.push_back(ii + 1);
				countTotalElems1++;
				countElems1++;
			}

			if (matrix2[i][ii] != 0) {
				list2_Z.push_back(matrix2[i][ii]);
				list2_S.push_back(ii + 1);
				countTotalElems2++;
				countElems2++;
			}
		}
		list1_R.push_back(countElems1 != 0 ? (countTotalElems1 - countElems1 + 1) : 0);
		list2_R.push_back(countElems2 != 0 ? (countTotalElems2 - countElems2 + 1) : 0);
	}

	for (int i = 0; i < matrixSize; i++)
	{
		for (int ii = 0; ii < matrixSize; ii++)
		{
			cout << matrix1[i][ii] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << "List _1_ Z = ";
	for (int i = 0; i < list1_Z.size(); i++)
	{
		cout << list1_Z[i] << " ";
	}
	cout << "\n" << "List _1_ R = ";
	for (int i = 0; i < list1_R.size(); i++)
	{
		cout << list1_R[i] << " ";
	}
	cout << "\n" << "List _1_ S = ";
	for (int i = 0; i < list1_S.size(); i++)
	{
		cout << list1_S[i] << " ";
	}
	cout << "\n";

	cout << "\n";
	for (int i = 0; i < matrixSize; i++)
	{
		for (int ii = 0; ii < matrixSize; ii++)
		{
			cout << matrix2[i][ii] << " ";
		}
		cout << "\n";
	}
	cout << "\n" << "List _2_ Z = ";
	for (int i = 0; i < list2_Z.size(); i++)
	{
		cout << list2_Z[i] << " ";
	}
	cout << "\n" << "List _2_ R = ";
	for (int i = 0; i < list2_R.size(); i++)
	{
		cout << list2_R[i] << " ";
	}
	cout << "\n" << "List _2_ S = ";
	for (int i = 0; i < list2_S.size(); i++)
	{
		cout << list2_S[i] << " ";
	}
	cout << "\n\n";

	// at irst you need to cinver vectors to matrix by function below
	// it will be ez with function or method, but my Visual studio cant support passing vector to it
	// void function (vector<int> *vec){} doesnt work
	
	// matrix sum
	cout << "Matrix sum" << "\n\n";
	for (int i = 0; i < matrixSize; i++)
	{
		for (int ii = 0; ii < matrixSize; ii++)
		{
			cout << matrix1[i][ii] + matrix2[i][ii] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	// matrix multiplications
	cout << "Matrix multiplications" << "\n\n";
	for (int i = 0; i < matrixSize; i++)
	{
		for (int ii = 0; ii < matrixSize; ii++)
		{
			int sum = 0;
			for (int k = 0; k < matrixSize; k++)
			{
				sum += matrix1[i][k] * matrix2[k][ii];
			}

			cout << sum << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	// construction that convert 3 vectors to matrix
	int countUsedNums = 0;
	for (int i = 0; i < list1_R.size(); i++)
	{
		if (list1_R[i] == 0) {
			for (int j = 0; j < list1_R.size(); j++)
			{
				// to display matrix
				// cout << "0 ";
			}
		}
		else
		{
			int elemsCount = 0;
			vector<int> elemsPosition;

			int last = 0;
			bool isLast = false;
			for (int j = i + 1; j < list1_R.size(); j++)
			{
				if (!isLast && list1_R[j] != 0) {
					isLast = true;
					last = j;
				}
			}

			if (isLast) 
			{
				elemsCount = list1_R[last] - list1_R[i];
			}
			else 
			{
				elemsCount = list1_S.size() - list1_R[i] + 1;
			}
			// cout << "elems count = " << elemsCount << "\n";

			for (int j = 0; j < list1_R.size(); j++)
			{
				bool isFound = false;
				for (int k = 0; k < elemsCount; k++)
				{
					if (isLast) {
						if (list1_S[list1_R[i] + k] == j + 1) {
							isFound = true;
						}
					}
					else
					{
						if (list1_S[list1_R[i] + k - 1] == j + 1) {
							isFound = true;
						}
					}
				}

				if (isFound) {
					// if you need to add number in matrix 
					// uncoment code below
					// matrix[i][j] = list1_Z[countTotalElems];

					// to display matrix
					// cout << list1_Z[countTotalElems] << " ";

					countUsedNums++;
				}
				else {
					// if you need to add number in matrix
					// uncoment code below
					// matrix[i][j] = 0;

					// to display matrix
					// cout << "0 ";
				}
			}
		}
		//to display matrix
		//cout << "\n";
	}
}

int main()
{
	// first quest display matrix in 3 types
	// 1. in matrix
	// 2. in vectors
	// 3. in cut vectors
	cout << "\n\n___Quest_1_\n\n";
	quest_1();

	// second task makes sum of 2 matrix and its multiplication
	cout << "\n\n___Quest_2_\n\n";
	quest_2();
}