#include <iostream>
using namespace std;

int main()

{
	Matrix M(4, 6);
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 6; j++)
	M(i,j) = (i+1)*(j+1);
	Matrix N(6,4);
	for (int i = 0; i < 6; i++)
	for (int j = 0; j < 4; j++)
		N(i,j) = i+j+2;
	Matrix P = N*M;
	M = M + (~N);
	for (int i = 0; i < 6; i++)
	{
	for (int j = 0; j < 6; j++)
		cout << P(i,j) << " ";
		cout << endl;
	}
	cout << endl;
	P = M * P;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		cout << M(i,j) << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		cout << P(i,j) << " ";
		cout << endl;
	}
}
	
	
	
