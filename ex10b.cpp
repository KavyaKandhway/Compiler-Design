#include<bits/stdc++.h>
using namespace std;

bool A(string x,int &i);
bool S(string x,int &i)
{
	if(x[i]=='c')
	{
		i++;
		if(A(x,i))
		{
			if(x[i]=='d' && i+1==x.size())
			return true;
		}
	}	
	return false;
}
bool A(string x,int &i)
{
	if(x.substr(i,2)=="ab")
	{
		i=i+2;
		return true;
	}
	else if(x.substr(i,1)=="a")
	{
		i=i+1;
		return true;
	}
	return false;
}
	
int main()
{
	string x;
	int i=0;
	cout<<"enter string\n";

    
        cin>>x;
	if(S(x,i))
	cout<<"string parsed\n";
	else
	cout<<"string not parsed\n";
    
	
	return 0;
}
	
