#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>

using namespace std;

class Sequence
{
	map<int,set<int> > data;
	vector<int> val;
	public:
	Sequence(vector<int> const & v)
	{
		val=v;
		for(int i=0;i<v.size();i++)
		{
			data[v[i]].insert(i);
		}
	}
	
	void operator ()(int i,int x)
	{
		if(data.empty())
		{
			cout<<"null string"<<endl;
			exit(0);
		}
		map<int,set<int> >::iterator point = data.find(val[i]);
		point->second.erase(i);
		if(point->second.empty()) 
			data.erase(point);
		val[i]=x;
		data[x].insert(i);
	}
	bool is_subsequence(vector<int> const & q)
	{
		if(q.empty())
			return true;
		else if(data.empty())
			return false;
		int lowest = -100,i;
		for(i=0;i<q.size();i++)
		{
			map<int,set<int> >::iterator p=data.find(q[i]);
			if(p==data.end())
				return false;
			set<int>::iterator low=p->second.upper_bound(lowest);
			if(low==p->second.end())
				return false;
			else
				lowest=*low;
		}
		if(i==q.size())
			return true;
	}
	
	void display()
	{
		for(map<int,set<int> >::iterator my =data.begin();my!=data.end();++my)
		{
			cout<< my->first;
			for(set<int>::iterator my1 =(my->second).begin();my1!=(my->second).end();++my1)
			cout<<"->"<<*my1;
			cout<<endl;
		}
	}
};
 
int main () {
	vector <int> v ;
	int x ;
	while(true) {
		cin >> x ;
		if(x == 0)
			break ;
		v.push_back(x) ;
	}
	cout << "H" << endl ;
	Sequence s(v) ;
	v.clear() ;
	while(true) {
		cin >> x ;
		if(x == 0)
			break ;
		v.push_back(x) ;
	}
	cout << "j" << endl ;
	cout << s.is_subsequence(v) << endl ;
}
