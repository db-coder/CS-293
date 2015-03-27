#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int length = 1000000;
	int maxval = 10;
	int qlength = 100000;
	int num_string = 100;
	vector<int> v(length), w(qlength);
	Sequence S(v);
	srand(428726);
	for (int i = 0; i < length; i++)
		S(i,rand()%maxval);
	for (int i = 0; i < num_string; i++)
	{
		for  (int j = 0; j < qlength; j++)
		w[j] = rand() % (maxval/2);
		cout << S.is_subsequence(w) << endl;
	}
}



