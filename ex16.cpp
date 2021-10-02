#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pair<int,int> >
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair
#define all(v) v.begin(),v.end()
#define input(a,b,n) for(i=b;i<n;i++){cin>>a[i];}
#define print(a) for(i=0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl;
#define trace1(a); cout<<"a="<<a<<endl;
#define trace2(a,b); cout<<"a="<<a<<" b="<<b<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf=0x3f3f3f3f3f3f3f3f;
int power(int a, int b){
    int res = 1;
    while(b!=0){
        if(b&1){
            res *= a; 
        }
        a = (a * a);
        b = (b / 2);
    }
    return res;
}
int32_t main()
{
	//fast;
    int t;
    t=1;
    //cin>>t;
    while(t--)
    {
    	cout<<"Number of nodes\n";
		int n;
		cin>>n;
		vvi v(n+1);
		vvi v1(n+1);
		cout<<"Number of edges";
		int m;
		cin>>m;
		cout<<"Enter edges\n";
		int i,j,k,l;
		for(i=0;i<m;i++)
		{
			int x,y;
			cin>>x>>y;
			v[y].pb(x);
		}
		vector<set<int> > s(n+1);
		s[1].insert(1);
		for(i=2;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				s[i].insert(j);
			}
		}
		for(i=2;i<=n;i++)
		{
			set <int> temp;
			temp.insert(i);
			int cnt[n+1]={0};
			for(j=0;j<v[i].size();j++)
			{
				int x=v[i][j];
				auto it=s[x].begin();
				while(it!=s[x].end())
				{
					int p=*(it);
					it++;
					cnt[p]++;
				}
			}
			for(int h=1;h<=n;h++)
			{
				if(cnt[h]==v[i].size())
				temp.insert(h);
			}
			s[i]=temp;
		}
		cout<<"Dominators list"<<endl;
		for(j=1;j<=n;j++)
			{
				cout<<j<<" ---- ";
				auto it=s[j].begin();
				while(it!=s[j].end())
				{
					int p=*(it);
					it++;
					cout<<p<<" ";
				}
				cout<<endl;
			}
	}
    return 0;
}
