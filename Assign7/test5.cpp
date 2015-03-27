#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	int length = 1000000;
	int maxval = 1000000000;
	int qlength = 20;
	int num_string = 100000;
	vector<int> v(length), w(qlength);
	Sequence S(v);
	srand(6747327);
	for (int i = 0; i < length; i++)
		S(i,rand()%maxval);
	for (int i = 0; i < num_string; i++)
	{
		for  (int j = 0; j < qlength; j++)
		w[j] = rand() % maxval;
		cout << S.is_subsequence(w) << endl;
	}
}
