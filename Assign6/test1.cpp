#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	Sequence S(5,3);
	for (int i = 0; i < 5; i++)
	S(i,i,i);
	for (int i = 0; i < 5; i++)
	cout << S[i] << " ";
	cout << endl;
}
