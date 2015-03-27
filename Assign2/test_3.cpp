#include <iostream>
using namespace std;

int main()

{
	Matrix M(4, 6);
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 6; j++)
	M(i,j) = (i+1)*(j+1);
	Matrix N = M(1,2,2,4);
	Matrix P = M(0,3,4,2);
        N = N*P;
        M = M(1,1,N);
	for (int i = 0; i < 2; i++)
	{
	for (int j = 0; j < 2; j++)
		cout << N(i,j) << " ";
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		cout << M(i,j) << " ";
		cout << endl;
	}
}
	
	
	
