// problem name: Connect
// problem link: https://codeforces.com/contest/1130/problem/C
// contest link: https://codeforces.com/contest/1130
// author: avijeet
// time: (?)
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define fl freopen("in","r",stdin); freopen("out","w",stdout)
int n,r[2],c[2];
vector<string>s;
void input()
{
	scanf("%d",&n);
	for(int i=0;i<2;i++)
	{
		scanf("%d %d",&r[i],&c[i]);
		--r[i];
		--c[i];
	}
		s.resize(n+1);

	for(int i=0;i<n;i++)
		cin>>s[i];
		
}
void dfs(int x,int y,vector<vector<bool> > &vis)
{
	if(x<0 || x>=n || y<0 || y>=n)
		return ;
	if(s[x][y]=='1' || vis[x][y]==1)
		return;
	vis[x][y]=1;
	dfs(x+1,  y,vis);
	dfs(x-1,  y,vis);
	dfs(x  ,y+1,vis);
	dfs(x  ,y-1,vis);

}
int main()
{


	input();

	std::vector<std::vector<bool>> visfromA(n,std::vector<bool> (n));
	std::vector<std::vector<bool>> visfromB(n,vector<bool> (n));
	dfs(r[0],c[0],visfromA);
	//
	dfs(r[1],c[1],visfromB);

	if(visfromA[r[1]][c[1]])
		cout<<0;
	else{
		#define sq(x) (x)*(x)
		int ans=1e9;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(visfromA[i][j]==1)
				{
					for(int k=0;k<n;k++)
						for( int l=0;l<n;l++)
							if(visfromB[k][l]==1)
								ans=min(ans,sq(k-i)+sq(j-l));	
				}
					cout<<ans;
	}

}