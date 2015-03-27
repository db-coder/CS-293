#include <iostream>
#include <cstdlib>

using namespace std;

int const M = 1000000;


int main()
{
	srand(646734);
	Sequence S(M, 0);
	for (int i = 0; i < M; i++)
	{
		int x = rand() % M;
		int y = x + 10000;
		if (y >= M ) y = M-1;
		S(x,y,rand() % 100);
	}
	for (int i = 0; i < M; i++)
	cout << S[i] << " ";
	cout << endl;
}
