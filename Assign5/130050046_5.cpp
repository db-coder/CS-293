#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

unsigned long long int fibonacci (int n)
{
	unsigned long long int first =1,second=1,result;
	for(int i=2;i<=n;i++)
	{
		result=first+second;
		first=second;
		second=result;
	}
	return result;
}

long long int calculate(string s,int n)
{
	string result="";
	string result1="";
	if(s.size()==1)
	{
		if(s=="0")
		return fibonacci(n-2);
		else if(s=="1")
		return fibonacci(n-1);
	}
	if(s.find("00")>=0 && s.find("00")<s.length())
		return 0;
		
	if(s.size()==2)
	{
		if(s=="01" && n<=3)
		return 1;
		else if(s=="11" && n<=3)
		return 0;
		else if(s=="01")
		return fibonacci(n-3) + calculate("11",n-1);
		else if(s=="11")
		return calculate("01",n-1);
	}
	
	for(int i=0;i<s.size()-2;i++)
		if(s[i]=='1' && s[i+1]=='1' && s[i+2]=='1')
			return 0;

	if(s.size()>=3)
	{
		if(s[0]=='0')
			result=result+"1";
	}
	int i=0;
	for(i=0;i<s.size()-1;i++)
	{
		if(s[i]=='1' && s[i+1]=='0')
		{
			result=result+"1";
			i++;
		}
		else if(s[i]=='1' && s[i+1]=='1')
		{
			result=result+"0";
		}
	}
	result1=result;
	if(i<s.size()-1)
	{
		if(s[s.length()-1]=='1')
		{
			result=result+"1";
			result1=result1+"0";
		}
	}
	if(result==result1)
	return calculate(result,n-1);
	else
	return calculate(result,n-1) +calculate(result1,n-1);
}
	
int main()
{
	int n;
	string s;
	while(cin>>n)
	{
	cin>>s;
	printf("%lld\n",calculate(s,n));
	}
	return 0;
}
