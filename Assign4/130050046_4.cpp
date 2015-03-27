#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class points
{
	public:
	int ai,bi,no;
	bool isredundant;
	points()
	{
		isredundant=false;
	}
};
	
struct compare_points
{
	bool operator ()(points const &p,points const &q)
	{
		if(q.ai>p.ai)
		return true;
		else if(q.ai==p.ai && q.bi>=p.bi)
		return true;
		else
		return false;
	}
};

void assign_redundant(vector<points> &wall,int k)
{
	if(k==1)
	return;
	for(int i=0;i<k;i++)
	{
		for(int j=i+1;j<k-1;j++)
		{
			if(wall[i].isredundant==false)
			{
				if(wall[i].ai<=wall[j].ai && wall[i].bi>=wall[j].bi && wall[j].ai<wall[j].bi)
					wall[j].isredundant=true;
				else if(wall[i].ai==wall[j].ai && wall[i].bi<=wall[j].bi && wall[j].ai<wall[j].bi)
					wall[i].isredundant=true;
				else
					break;
			}
		}
	}
	for(int i=k-1;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(wall[i].isredundant==false)
			{
				if(wall[i].ai>wall[i].bi && wall[j].ai<=wall[i].ai && wall[j].bi<=wall[i].bi) 
					wall[j].isredundant=true;
				else
					break;
			}
		}
	}
}

void findnext(vector<points> wallfinal,vector<points> &next,int n)
{
	int i=0,j=1;
	if(wallfinal.size()==1)
	{
		if(wallfinal[0].ai+1==wallfinal[0].bi)
		{
			printf("%d",1);
			exit(0);
		}
		printf("%s","impossible\n");
		exit(0);
	}
	while(i<wallfinal.size() && j<wallfinal.size())
	{
		if(wallfinal[i].bi==n)
		wallfinal[i].bi=0;
		if(wallfinal[i].bi+1>=wallfinal[j].ai)
		{
			if(wallfinal[i].bi+1==wallfinal[j].ai && i==wallfinal.size()-1)
			{
				next.push_back(wallfinal[j]);
				break;
			}
			j++;
			if(j==wallfinal.size())
			{
				next.push_back(wallfinal[j-1]);
				i++;
				if(i==wallfinal.size()-1)
				{
					j=0;
				}
			}
			continue;
		}
		else if(wallfinal[i].bi+1<wallfinal[j].ai && wallfinal[j].ai>wallfinal[j].bi)
		{
			next.push_back(wallfinal[j]);
			i++;
			j=i+1;
			if(i==wallfinal.size()-1)
				j=0;
			continue;
		}
		if(wallfinal[i].bi+1<wallfinal[j].ai)
		{
			if(j==1)
			{
				printf("%s","impossible\n");
				exit(0);
			}
			next.push_back(wallfinal[j-1]);
			i++;
			j=i+1;
			if(i==wallfinal.size()-1)
				j=0;
		}
	}
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	points p;
	vector<points>wall;
	vector<points>wallfinal;
	vector<points>next;
	for(int i=0;i<k;i++)
	{
		scanf("%d %d",&p.ai,&p.bi);
		p.no=i;
		wall.push_back(p);
	}
	
	sort(wall.begin(),wall.end(),compare_points());
	
	assign_redundant(wall,k);
	
	for(int i=0;i<k;i++)
	{
		if(wall[i].isredundant==false)
			wallfinal.push_back(wall[i]);
	}
	
	printf("%s","\n");
	for(int i=0;i<wallfinal.size();i++)
	printf("%d %d %d \n",wallfinal[i].ai,wallfinal[i].bi,wallfinal[i].no);
	printf("%s","\n");
	findnext(wallfinal,next,n);

	printf("%s","\n");
	for(int i=0;i<next.size();i++)
	{
		printf("%d %d %d \n",next[i].ai,next[i].bi,next[i].no);
	}
	
	int min=wallfinal[0].no-next[0].no,pos;
	for(int i=1;i<next.size();i++)
		if(min>wallfinal[i].no-next[i].no)
		{
			min=wallfinal[i].no-next[i].no;
			pos=i;
		}
	int count=0,min1=0;
	for(int j=min;j<next[min].no;j++)
	{
		count=0;
		while(next[j].bi<n)
		{
			j=next[j].no;
			count++;
		}
		if(min1>count)
		min1=count;
	}
	cout<<min1;
	return 0;
}
