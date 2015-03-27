#include <iostream>
using namespace std;

int main()

{
	Matrix M(4, 6);
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 6; j++)
	M(i,j) = (i+1)*(j+1);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		cout << M(i,j) << " ";
		cout << endl;
	}
}
	
	
	
