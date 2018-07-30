#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int dp[6200][6200];

int lcs (string &s,string &s1,int n,int m) {
	if(n==0||m==0)
		return 0;
	if(dp[n][m]!=-1)
		return dp[n][m];
	if(s[n-1]==s1[m-1]) {
		return dp[n][m]=1+lcs(s,s1,n-1,m-1);
	}
	
	return dp[n][m]=max(lcs(s,s1,n-1,m),lcs(s,s1,n,m-1));
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	string s;
    	cin>>s;
    	string s1=s;
    	reverse(s1.begin(),s1.end());
    	int n=s.size();
    	for(int i=0;i<=n;i++) 
    		for(int j=0;j<=n;j++)
    			dp[i][j]=-1;
    	int ans=n-lcs(s,s1,n,n);;
    	cout<<ans<<"\n";
    }
    return 0;
}