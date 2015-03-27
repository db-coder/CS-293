#include <iostream>
using namespace std;

int main()

{
	Matrix M(4, 4);
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	M(i,j) = (i+1)*(j+1);
	M =  M + ~(M*M) + (M(0,1,4,2)*M(2,0,2,4));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		cout << M(i,j) << " ";
		cout << endl;
	}
}
	
	
	
