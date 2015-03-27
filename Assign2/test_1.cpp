#include <iostream>
using namespace std;

int main()

{
	Matrix M(4, 6);
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 6; j++)
	M(i,j) = (i+1)*(j+1);
	Matrix N(M);
	N = ~N;
	for (int i = 0; i < 6; i++)
	{
	for (int j = 0; j < 4; j++)
		cout << N(i,j) << " ";
		cout << endl;
	}
}
	
	
	
