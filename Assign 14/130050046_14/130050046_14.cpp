#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

struct edge
{
	int u,v;
	double weight;
};

int Vertices,Edges;

struct subset
{
	int parent,rank;
};

int find(subset subsets[],int i)
{
	if(subsets[i].parent!=i)
		subsets[i].parent=find(subsets,subsets[i].parent);
	return subsets[i].parent;
}

void union1(subset subsets[],int x,int y)
{
	int rootx=find(subsets,x);
	int rooty=find(subsets,y);
	if(subsets[rootx].rank<subsets[rooty].rank)
		subsets[rootx].parent=rooty;
	else if(subsets[rootx].rank>subsets[rooty].rank)
		subsets[rooty].parent=rootx;
	else
	{
		subsets[rooty].parent=rootx;
		subsets[rootx].rank++;
	}
}

struct compare_edges
{
	bool operator () (edge const &p,edge const &q)
	{
		if(q.weight>=p.weight)
			return true;
		else
			return false;
	}
};

void kruskal_algo(vector<edge> graph)
{
	edge final[Vertices];
	int edges=0,i=0;
	sort(graph.begin(), graph.end(),compare_edges());
	subset *subsets=new subset[Vertices];
	for(int V=0;V<Vertices;V++)
	{
		subsets[V].parent=V;
		subsets[V].rank=0;
	}
	while(edges<Vertices-1)
	{
		edge nextedge=graph[i++];
		int u=find(subsets,nextedge.u);
		int v=find(subsets,nextedge.v);
		if(u!=v)
		{
			final[edges++]=nextedge;
			union1(subsets,u,v);
		}
	}
	cout<<"Minimum Spanning Tree ->\n";
	for (int x = 0; x < edges; ++x)
	{
		cout<<final[x].u<<"-"<<final[x].v<<":"<<final[x].weight<<endl;
	}
}

int main()
{
	cin>>Vertices>>Edges;
	if(Edges<=0||Vertices<=0)
	{
		cout<<"Not Possible\n";
		exit(0);
	}
	vector<edge> graph;
	graph.resize(Edges);
	for (int i=0;i<Edges;i++)
	{
		cin>>graph[i].u>>graph[i].v>>graph[i].weight;
	}
	kruskal_algo(graph);
	return 0;
}