#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

class Sequence
{
	public:
	class value
	{
		public:
		int val,first,last;
		bool assign;
		value(int x,bool t)
		{
			val=x;
			assign=t;
		}
	};
	int height;
	vector< vector < value > > S;
	Sequence(double n,int x)
	{
		height = 1 + ceil(log2(n));
		int size[height];
		double elements=n;
		for(int z=height-1;z>=0;z--)
		{
			size[z]=ceil(elements);
			elements/=2;
		}
		for(int i=0;i<height;i++)
		{
			vector<value> level;
			int number=pow(2,(height-i-1));
			for(int j=0;j<size[i];j++)
			{
				value ob(x,true);
				if(i==0)
				{
					ob.first=0;
					ob.last=n-1;
				}
				else
				{
					ob.first=j*number;
					if((j+1)*number>=n)
						ob.last=n-1;
					else
						ob.last=ob.first + number - 1;
				}
				level.push_back(ob);
			}
			S.push_back(level);
		}
	}
	void operator ()(int i,int j,int x)
	{
		int k=0,l=0;
		while(k<height && l<S[k].size())
		{
			if(S[k][l].first >=i && S[k][l].last<=j)
			{
				 S[k][l].val=x;
			}
			else if(S[k][l].first >=i && S[k][l].last >=j)
			{
				S[k][l].assign=false;
			}
			else if(S[k][l].first <=i && S[k][l].last <=j)
			{
				S[k][l].assign=false;	
			}
			else
			{
				S[k][l].assign=false;
			}
			l++;
			if(l==S[k].size())
			{
				k++;
				l=0;
			}
		}
	}
	int operator [](int i)
	{
		//~ int k=0,l=0;
		return S[height-1][i].val;
		//~ while(k<height-1 && l<S[k].size())
		//~ {
			//~ if(S[k][l].assign==true)
			//~ return S[k][l].val;
			//~ else if(i<=S[k+1][l].last)
			//~ l=2*l;
			//~ else if(i>S[k+1][l].last)
			//~ l=2*l+1;
			//~ k++;
		//~ }
	}
};
