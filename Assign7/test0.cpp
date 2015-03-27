#include <vector>
using namespace std;

int main()
{
	vector<int> v(10), w;
	Sequence S(v);
	for (int i = 0; i < 10; i++)
		S(i,i);
	w.clear();
	w.push_back(5);
	cout << S.is_subsequence(w) << endl;
	w.clear();
	w.push_back(10);
	cout << S.is_subsequence(w) << endl;
	w.clear();
	for (int i = 0; i < 5; i++)
		w.push_back(2*i);
	cout << S.is_subsequence(w) << endl;
	w.push_back(1);
	cout << S.is_subsequence(w) << endl;

}



