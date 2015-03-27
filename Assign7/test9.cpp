#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int length = 1000000;
	int maxval = 90;
	int qlength = 10000;
	int num_string = 1000;
	vector<int> v(length), w(qlength);
	Sequence S(v);
	srand(3105298);
	for (int i = 0; i < length/10; i++) S(i,i);
	for (int i = 0; i < length; i++)
		S(i,rand()%maxval);
	for (int i = 0; i < num_string; i++)
	{
		for  (int j = 0; j < qlength; j++)
		w[j] = rand() % maxval;
		cout << S.is_subsequence(w) << endl;
	}
}
