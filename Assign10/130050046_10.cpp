#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <list>
#include <set>
#include <iostream>
#include <ext/hash_set>
using namespace __gnu_cxx;
using namespace std;

struct hash_pair
{
    size_t operator()(const pair<int,int> t)const
    {
    	short x,y,z;
    	if(t.first<0)
			y=-2*t.first +1;
		else
			y=2*t.first;
		if(t.second<0)
			z=-2*t.second +1;
		else
			z=2*t.second;
		x=max(y,z);
    	return (y+z)*(y+z+1)/2 + x+1;
    }
};

struct eq_pair
{
    bool operator()(const pair<int,int> t1, const pair<int,int> t2) const
    {
    	return (t1==t2) || ((t1.first==t2.second) && (t1.second==t2.first));
    }
};

class Graph
{
    pair<int,int> node;  
    int level;  // level
    list <pair<int,int> > adjlists;    // Pointer to an array containing adjacency lists
public:
    Graph(pair<int,int> node,int level);  // Constructor
    void addEdge(); // function to add an edge to graph
    void BFS(pair<int,int> s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(pair<int,int> node,int level1)
{
	level=level1;
    this->node = node;
    list <pair<int,int> > adjlists(12);
}
 
void Graph::addEdge()
{
	pair<int,int> a (2*node.first,node.second);
	pair<int,int> b (2*node.second,node.second);
	pair<int,int> c ((node.first+node.second),node.second);
	pair<int,int> d ((node.first-node.second),node.second);
	pair<int,int> e ((node.second-node.first),node.second);
	pair<int,int> f (0,node.second);
	
	pair<int,int> g (node.first,2*node.second);
	pair<int,int> h (node.first,2*node.first);
	pair<int,int> i (node.first,(node.first+node.second));
	pair<int,int> j (node.first,(node.first-node.second));
	pair<int,int> k (node.first,(node.second-node.first));
	pair<int,int> l (node.first,0);
	adjlists.push_back(a);
	adjlists.push_back(b);
	adjlists.push_back(c);
	adjlists.push_back(d);
	adjlists.push_back(e);
	adjlists.push_back(f);
	adjlists.push_back(g);
	adjlists.push_back(h);
	adjlists.push_back(i);
	adjlists.push_back(j);
	adjlists.push_back(k);
	adjlists.push_back(l);
}
//~ set<pair<int,int> > top1;
hash_set<pair<int,int>,hash_pair,eq_pair> top1;
void Graph::BFS(pair <int,int> s)
{
    // Create a queue for BFS
    list <pair <pair<int,int>,int> > queue;
    // Mark the current node as visited and enqueue it
    queue.push_back(pair <pair<int,int>,int> (node,0));
	top1.insert(node);
    // 'i' will be used to get all adjacent vertices of a vertex
    list <pair<int,int> >::iterator i;
 
    while(1)
    {
        // Dequeue a vertex from queue and print it
        pair<int,int> top = queue.front().first;
        int level = queue.front().second;
        if(top==s || (top.second==s.first && top.first==s.second))
        {
			printf("%d\n",level);
			exit(0);
		}
		queue.pop_front();
        Graph g1(top,level);
        g1.addEdge();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for(i = g1.adjlists.begin(); i != g1.adjlists.end(); ++i)
        {
            if(top1.find(*i)==top1.end())
            {
                top1.insert(*i);
                queue.push_back(pair <pair<int,int>,int>(*i,level+1));
            }
        }
    }
}
 
// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(pair<int,int> (1,0),0);
	g.addEdge();
	int n,m;
	cin>>n>>m;
    g.BFS(pair<int,int> (n,m));
 
    return 0;
}
