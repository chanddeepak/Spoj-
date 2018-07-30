#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int dp[2002][2002];

int calEdist(string s1,string s2,int n,int m) {

	if(n==0)
		return m;
	if(m==0)
		return n;
	if(dp[n][m]!=-1)
		return dp[n][m];
	int ans=0;
	if(s1[n-1]==s2[m-1]) {
		ans=calEdist(s1,s2,n-1,m-1);
		return dp[n][m]=ans;
	} 
	int a=calEdist(s1,s2,n,m-1);//Insert
	int b=calEdist(s1,s2,n-1,m);//Remove
	int c=calEdist(s1,s2,n-1,m-1);//Replace

	ans=1+min(min(a,b),c);
	return dp[n][m]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	string s1,s2;
    	cin>>s1>>s2;
    	int n=s1.size(),m=s2.size();
   		for(int i=0;i<=n;i++)
   			for(int j=0;j<=m;j++)
   				dp[i][j]=-1;
    	int ans=calEdist(s1,s2,n,m);
    	cout<<ans<<"\n";
    }
    return 0;
}