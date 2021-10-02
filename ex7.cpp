#include <bits/stdc++.h>
using namespace std;
bool visited[1000];
vector<vector<int> > v;
int maxVal=0;
void dfs(int u,int x)
{
	visited[u]=true;
    int i;
	for(i=0;i<v[u].size();i++)
	{
		int w=v[u][i];
		if(true)
		{
			int temp=x+1;
			maxVal=max(maxVal,temp);
			dfs(w,temp);
		}
	}
}

int main()
{
	cout<<"enter the size\n";
	int n;
	cin>>n;
	vector<char> str(n);
	cout<<"enter the symbols\n";
	int k,l;
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	vector<vector<char> >  pre(n,vector<char>(n));
	cout<<"enter precedence table\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>pre[i][j];
		}
	}
	
	v.resize(2*n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(pre[i][j]=='>')
			{
				v[i].push_back(j+n);
			}
			else if(pre[i][j]=='<')
			{
				v[j+n].push_back(i);
			}
		}
	}
	

	int f[n],g[n];
	for(int i=0;i<n;i++)
	{
		
		for(int i=0;i<2*n;i++)
		visited[i]=false;
		dfs(i,0);
	
		f[i]=maxVal;
		maxVal=0;
		for(int i=0;i<2*n;i++)
		visited[i]=false;
		dfs(i+n,0);
		g[i]=maxVal;
		maxVal=0;
	}
    cout<<"f:";
	for(int i=0;i<n;i++)
	cout<<f[i]<<" ";
	cout<<endl;
    cout<<"g:";
	for(int i=0;i<n;i++)
	cout<<g[i]<<" ";
	cout<<endl;
}

//Kavya KAndhway DD cse 18JE0408