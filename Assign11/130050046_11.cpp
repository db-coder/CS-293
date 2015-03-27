#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void modify(int dist[][400],int N,int x,int y)
{
	if (dist[x][y]>=1000000001) 
		return;
	for (int i=0;i<2*N;i++)
		for (int j=0;j<2*N;j++)
		{
			int minimum=(dist[i][x]>dist[y][j])?dist[y][j]:dist[i][x];
			dist[i][j]=(dist[i][j]>minimum)?dist[i][j]:minimum;
		}
}

int main()
{
	int N,dist[400][400],distance,i,j,k;
	cin>>N;
	if(N<=2)
	{
		while(N)
		{
			cin>>distance;
			N--;
		}
		cout<<"0"<<endl;
		exit(0);
	}
	for(i=0;i<2*N;i++)
	{
		for(j=0;j<2*N;j++)
			dist[i][j]=0;
		dist[i][i]=1000000001;
	}
	vector<pair<int, pair<int,int> > > node;
	for(i=0;i<N;i++)
		for(j=i+1;j<N;j++)
		{
			cin>>distance;
			dist[i][j+N]=distance;
			dist[j][i+N]=distance;
			node.push_back(pair<int, pair<int,int> > (distance,pair<int,int> (i,j)));
		}
	sort(node.begin(),node.end());
	int disparity=node.back().first;
	for(i=node.size()-1;i>=0;i--)
	{
		int A=0;
		for(j=0;j<N;j++)
			A=max(A,min(dist[j][j+N],dist[j+N][j]));
		disparity=min(disparity,A+node[i].first);
		int x=node[i].second.first,y=node[i].second.second;
		modify(dist,N,x+N,y);
		modify(dist,N,x,y+N);
		modify(dist,N,y+N,x);
		modify(dist,N,y,x+N);
	}
	cout<<disparity<<endl;
}