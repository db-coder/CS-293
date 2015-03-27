#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <cmath>

using namespace std;

struct node
{
	node():l(-10000),eucliddist_t(0),pathdist_s(0) {}
	double x,y;
	double l,eucliddist_t,pathdist_s;
	int pos;
};

struct sort_nodes
{
	bool operator() (node const &p,node const &q)
	{
		if(p.x<q.x)
			return true;
		else
			return false;
	}
};

struct sort_address
{
	bool operator() (node const &p,node const &q)
	{
		if(q.l<0)
			return true;
		else if(p.l<q.l)
			return true;
		else
			return false;
	}
};

int main()
{
	int n,pos;
	vector<node> array;
	vector<node> address;
	double D,s,t,x,y;
	scanf("%d %lf %lf %lf",&n , &D , &s , &t);
	array.resize(n);
	address.resize(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf",&x , &y);
		array[i].x=x;
		array[i].y=y;
	}
	node start,dest;
	start=array[s];
	dest=array[t];
	sort(array.begin(), array.end(),sort_nodes());
	for(int i=0;i<n;i++)
	{
		array[i].pos=i;
		address[i]=array[i];
	}

	for(int i=0;i<n;i++)
	{
		if(array[i].x==start.x && array[i].y==start.y)
		{
			start.pos=i;
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(array[i].x==dest.x && array[i].y==dest.y)
		{
			dest.pos=i;
			break;
		}
	}
	bool visit[n];
	for(int i=0;i<n;i++)
	{
		visit[i]=false;
	}
	while(true)
	{
		int j=start.pos,minpos,minpos2,minpos1;
		double minl=2000000,minl2=2000000,min1=2000000;
		visit[j]=true;
		while(array[j].x<=(array[start.pos].x + D) && j<n)
		{
			//cout<<visit[j]<<endl;
			if ((pow((array[j].y-array[start.pos].y),2) + pow((array[j].x-array[start.pos].x),2)<= D*D) && visit[j]==false)
			{
				//cout<<"he";
				array[j].pathdist_s=array[start.pos].pathdist_s + sqrt(pow((array[j].y-array[start.pos].y),2) + pow((array[j].x-array[start.pos].x),2));
				array[j].eucliddist_t=sqrt(pow((array[j].y-array[dest.pos].y),2) + pow((array[j].x-array[dest.pos].x),2));
				array[j].l=array[j].pathdist_s+array[j].eucliddist_t;
				if (array[j].l<=minl)
				{
					minl=array[j].l;
					minpos=j;
					//cout<<"hi";
				}
			}
			j++;
		}
		j=start.pos-1;
		//cout<<"hi";
		while(array[j].x>=(array[start.pos].x - D) && j>=0)
		{
			cout<<(pow((array[j].y-array[start.pos].y),2) + pow((array[j].x-array[start.pos].x),2))<<endl;
			if ((pow((array[j].y-array[start.pos].y),2) + pow((array[j].x-array[start.pos].x),2)<= D*D) && visit[j]==0)
			{
				array[j].pathdist_s=array[start.pos].pathdist_s + sqrt(pow((array[j].y-array[start.pos].y),2) + pow((array[j].x-array[start.pos].x),2));
				array[j].eucliddist_t=sqrt(pow((array[j].y-array[dest.pos].y),2) + pow((array[j].x-array[dest.pos].x),2));
				array[j].l=array[j].pathdist_s+array[j].eucliddist_t;
				if (array[j].l<=minl2)
				{
					minl2=array[j].l;
					minpos2=j;
				}
			}
			j--;
		}
		sort(address.begin()+start.pos,address.end(),sort_address());
		for(int i=0;i<address.size();i++)
		{
			if(address[i].l<min1)
			{
				min1=address[i].l;
				minpos1=address[i].pos;
			}
		}
		if(min1<minl2)
		{
			minl2=min1;
			minpos2=minpos1;
		}
		if(minl<minl2)
			start=array[minpos];
		else
			start=array[minpos2];
		if(start.pos==dest.pos)
			break;
	}
	

	for(int i=0;i<n;i++)
	{
		cout<<array[i].x<<" "<<array[i].y<<endl;
	}
	cout<<dest.l<<endl;
	return 0;
}