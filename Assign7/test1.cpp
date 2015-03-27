#include <vector>
using namespace std;

int main()
{
	vector<int> v(1000000), w;
	Sequence S(v);
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 100000; j++)
		S(i*100000+j, i%2);
	w.clear();
	for (int i = 0; i < 10; i++)
		w.push_back(i % 2);
	cout << S.is_subsequence(w) << endl;
	w.push_back(0);
	cout << S.is_subsequence(w) << endl;

}



