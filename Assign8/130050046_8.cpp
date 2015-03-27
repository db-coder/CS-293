#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

class data
{
	public:
	int left,right,winstat;
};

bool win(int node, bool color, data *tree)
{
	if(tree[node].left==-1)
	{
		tree[node].winstat=false;
		return false;
	}
	else if(tree[node].left==-2)
	{
		tree[node].winstat=true;
		return true;
	}
	if(color==false)
	{
		bool l=win(tree[node].left,true,tree), r=win(tree[node].right,true,tree);
		if(l==false || r==false)
		{
			tree[node].winstat=false;
			return false;
		}
		else
		{
			tree[node].winstat=true;
			return true;
		}
	}
	else
	{
		bool l=win(tree[node].left,false,tree), r=win(tree[node].right,false,tree);
		if(l==true || r==true)
		{
			tree[node].winstat=true;
			return true;
		}
		else
		{
			tree[node].winstat=false;
			return false;
		}
	}
}

int minimum(bool final1, data *tree, int node, bool color)
{
	if(final1==false)
	{
		if(tree[node].left==-1)
			return 0;
		if(tree[node].left==-2)
			return INT_MAX;
		if(tree[tree[node].left].winstat==false && tree[tree[node].right].winstat==false && color==false)
			return 1+min(minimum(final1,tree,tree[node].left,!color),minimum(final1,tree,tree[node].right,!color));
		if(tree[tree[node].left].winstat==false && tree[tree[node].right].winstat==false && color==true)
			return 1+max(minimum(final1,tree,tree[node].left,!color),minimum(final1,tree,tree[node].right,!color));
		else 
		{
			if(tree[tree[node].left].winstat==false)
				return 1+minimum(final1,tree,tree[node].left,!color);
			if(tree[tree[node].right].winstat==false)
				return 1+minimum(final1,tree,tree[node].right,!color);
		}
	}
	else
	{
		if(tree[node].left==-1)
			return INT_MAX;
		if(tree[node].left==-2)
			return 0;
		if(tree[tree[node].left].winstat==true && tree[tree[node].right].winstat==true && color==true)
			return 1+min(minimum(final1,tree,tree[node].left,!color),minimum(final1,tree,tree[node].right,!color));
		if(tree[tree[node].left].winstat==true && tree[tree[node].right].winstat==true && color==false)
			return 1+max(minimum(final1,tree,tree[node].left,!color),minimum(final1,tree,tree[node].right,!color));
		else 
		{
			if(tree[tree[node].left].winstat==true)
				return 1+minimum(final1,tree,tree[node].left,!color);
			if(tree[tree[node].right].winstat==true)
				return 1+minimum(final1,tree,tree[node].right,!color);
		}
	}
	
}
int min_color(data *tree,bool color,int node)
{
	if(tree[node].left==-1 || tree[node].left==-2)
		return 1;
	else if(color==false)
		return min(min_color(tree,!color,tree[node].left),min_color(tree,!color,tree[node].right));
	else
		return min_color(tree,!color,tree[node].left) + min_color(tree,!color,tree[node].right);
}
	
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	data tree[n];
	for(int x=0;x<n;x++)
	{
		scanf("%d %d %d",&i,&j,&k);
		tree[i].left=j;
		tree[i].right=k;
	}
	bool final1 = win(0,false,tree); //First 0=starting node. Second false = white
	if(final1==false)
		printf("White ");
	else
		printf("Black ");
	int min=minimum(final1,tree,0,false);
	int mincol=min_color(tree,false,0);
	printf("%d %d",min,mincol);
	printf("\n");
}

