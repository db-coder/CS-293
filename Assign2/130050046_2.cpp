#include <iostream>

using namespace std;

class Matrix
{
	int n,m;
	int **matrix;	
	public:
	Matrix()					//default constructor
	{
		matrix=NULL;
		n=m=0;
	}
	Matrix(int n,int m)			//zero matrix
	{
		this->n=n;
		this->m=m;
		matrix=new int *[n];
		for(int i=0;i<n;i++)
		matrix[i]=new int[m];
		
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		matrix[i][j]=0;
	}
	Matrix(Matrix const& mat)	//copy constructor
	{
		this->n=mat.n;
		this->m=mat.m;
		matrix=new int *[m];
		for(int i=0;i<n;i++)
		matrix[i]=new int[m];
		
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		matrix[i][j]=mat.matrix[i][j];
	}
	~Matrix()					//destructor
	{
		if(matrix!=0)
		{
			for(int i=0;i<n;i++)
			delete []matrix[i];
			delete matrix;
		}
	}
	Matrix const operator + (Matrix const & mat) const		//matrix addition
	{
		Matrix sum(n,m);
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		sum.matrix[i][j]=matrix[i][j]+mat.matrix[i][j];
		return sum;
	}
	Matrix const operator * (Matrix const & mat) const		//matrix multiplication
	{
		Matrix multiply(n,mat.m);
		for(int i=0;i<n;i++)
		for(int k=0;k<mat.m;k++)
		for(int j=0;j<m;j++)
		multiply.matrix[i][k]+=matrix[i][j]*mat.matrix[j][k];
		return multiply;
	}
	Matrix const operator ~ () const			//inverse of a matrix
	{
		Matrix transpose(m,n);
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		transpose.matrix[i][j]=matrix[j][i];
		return transpose;
	}
	Matrix const operator = (Matrix const & mat)	 	//matrix addition
	{
		if(this==&mat)
		return *this;
		if(matrix!=0)
		{
			for(int i=0;i<n;i++)
			delete []matrix[i];
			delete matrix;
		}
		n=mat.n;
		m=mat.m;
		matrix=new int *[m];
		for(int i=0;i<n;i++)
		matrix[i]=new int[m];
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		matrix[i][j]=mat.matrix[i][j];
		return *this;
	}
	int & operator ()(int i,int j) const		//(i,j) th element
	{
		return matrix[i][j];
	}
	Matrix operator ()(int i,int j,int k,int l) const		//submatrix of a matrix
	{
		Matrix sub(k,l);
		for(int x=i;x<i+k;x++)
		for(int y=j;y<j+l;y++)
		sub.matrix[x-i][y-j]=matrix[x][y];
		return sub;
	}
	Matrix operator ()(int i,int j,Matrix const& A) const	//changed matrix
	{
		Matrix newmatrix(*this);
		for(int x=0;x<A.n;x++)
		for(int y=0;y<A.m;y++)
		{
			newmatrix.matrix[x+i][y+j]=A.matrix[x][y];
		}
		return newmatrix;
	}
};


