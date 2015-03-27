#include <iostream>
#include <cstdlib>

using namespace std;

int const M = 1000000;

int main()
{
	srand(68215);
	Sequence S(M, 0);
	for (int i = 0; i < M; i++)
	{
		int x = rand() % M;
		int y = rand() % M;
		if (y < x)
		{
			int temp = x;
			x = y;
			y = temp;
		}
		S(x,y,rand() % M);
	}
	for (int i = 0; i < M; i++)
	cout << S[i] << " ";
	cout << endl;
}
