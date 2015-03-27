#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;

class triplet1
{
	public:
	int order;
	float x,y;
	double angle;
};
struct compare_points
{
	bool operator ()(triplet1 const &p,triplet1 const &q)
	{
		if(q.x>p.x)
		return true;
		else if(q.x==p.x && q.y>=p.y)
		return true;
		else
		return false;
	}
};
struct compare_angle
{
	bool operator ()(triplet1 const &p,triplet1 const &q)
	{
		if(q.angle>p.angle)
		return true;
		else if(q.x==p.x && q.y>=p.y)
		return true;
		else
		return false;
	}
};
int main()
{
	int n,n1,x,j=2;
	triplet1 a;
	vector <triplet1> asc,above,below,result,asc2;
	scanf("%d",&n);
	x=n-1;
	n1=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%f",&a.x);
		scanf("%f",&a.y);
		a.order=i;
		asc.push_back(a);
	}
	asc2=asc;
	while(j<n)
	{
		if((asc2[1].x-asc2[0].x)*(asc2[j].y-asc2[0].y)!=(asc2[1].y-asc2[0].y)*(asc2[j].x-asc2[0].x))
		break;
		j++;
	}
	pair <float,float> centroid;
	centroid.first=(asc2[0].x+asc2[1].x+asc2[j].x)/3;
	centroid.second=(asc2[0].y+asc2[1].y+asc2[j].y)/3;
	for(int i=0;i<asc2.size();i++)
	{
		asc2[i].angle=atan((asc2[i].y-centroid.second)/(asc2[i].x-centroid.first));
	}
	sort(asc2.begin(),asc2.end(),compare_angle());
	for(int i=0;i<asc2.size();i++)
	{
		printf("%d",asc2[i].order);
		printf("%s"," ");
	}
	printf("%s","\n");
	sort(asc.begin(),asc.end(),compare_points());
	pair <float,float> start,end;
	start.first=asc[0].x;
	start.second=asc[0].y;
	while(asc[n1].x==asc[n1-1].x)
	{
		if(asc[n1-1].y<asc[n1].y)
			x=n1-1;
		n1--;
	}
	end.first=asc[x].x;
	end.second=asc[x].y;
	float slope=(end.second-start.second)/(end.first-start.first),slope2;
	for(int i=0;i<asc.size();i++)
	{
		if((asc[i].x==start.first && asc[i].y==start.second) || (asc[i].x==end.first && asc[i].y==end.second))
		{
			below.push_back(asc[i]);
			continue;
		}
		if(asc[i].x==0 && start.first==0)
		{
			below.push_back(asc[i]);
			continue;
		}
		slope2=(asc[i].y-start.second)/(asc[i].x-start.first);
		if(slope2<=slope)
		below.push_back(asc[i]);
	}
	for(int i=0;i<asc.size();i++)
	{
		if((asc[i].x==start.first && asc[i].y==start.second) || (asc[i].x==end.first && asc[i].y==end.second))
		continue;
		if(asc[i].x==0 && start.first==0)
		{
			above.push_back(asc[i]);
			continue;
		}
		slope2=(asc[i].y-start.second)/(asc[i].x-start.first);
		if(slope2>slope)
		above.push_back(asc[i]);
	}
	for(int i=0;i<below.size();i++)
	{
		result.push_back(below[i]);
	}
	reverse(above.begin(),above.end());

	for(int i=0;i<above.size();i++)
	{
		result.push_back(above[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",result[i].order);
		printf("%s"," ");
	}
	printf("%s","\n");
	return 0;
}
