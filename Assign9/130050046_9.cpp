#include <string>
#include <iostream>
#include <set>
using namespace std;
set<string> s;
string operator - (string s,string s1)
{
	string result;
	result=s.substr(s1.size(),s.size()-s1.size());
	return result;
}

bool ifprefix(string s1,string s2)
{
	s2=s2.substr(s1.size(),s2.size()-s1.size());
	int x=strcmp(s1,s2);
	if(x)
	return true;
	else
	return false;
}

set <string> & prefix(set<string>::iterator init)
{
	set<string> prefixes;
	for(set<string>::iterator  p=init;p!=s.end();p++)
	{
		if(ifprefix(*init,*p))
			prefixes.insert(*p);
	}
	return &prefixes
}
		
	
int main()
{
	int n;
	
	cin>>n;
	string data;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		s.insert(data);
	}
	for(set<string>::iterator init=s.begin();init!=s.end();init++)
	{
		cout<<*init<<endl;
	}
	string a="hello",b="h",c;
	c=a-b;
	cout<<c<<endl;
}
