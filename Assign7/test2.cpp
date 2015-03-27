#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
	vector<int> v(1000000), w;
	Sequence S(v);
	srand(6161622);
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 100000; j++)
		S(i*100000+j, i%2);
	for (int i = 0; i < 10000; i++)
	{
		w.clear();
		for  (int j = 0; j < 20; j++)
		w.push_back(rand() % 2);
		cout << S.is_subsequence(w) << endl;
	}

}



