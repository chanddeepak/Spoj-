#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int fees[103],fun[103],dp[103][503];

int solve(int n,int maxB) {
	if(n==0||maxB==0)
		return 0;
	if(dp[n][maxB]!=-1)
		return dp[n][maxB];
	int ans=solve(n-1,maxB);
	if(fees[n-1]<=maxB)
		ans=max(ans,solve(n-1,maxB-fees[n-1])+fun[n-1]);
	return dp[n][maxB]=ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxB,n;
    while(cin>>maxB>>n) {
    	if(maxB==0&&n==0)
    		break;
    	memset(fees,0,sizeof(fees));
    	memset(fun,0,sizeof(fun));
    	for(int i=0;i<n;i++) {
    		cin>>fees[i]>>fun[i];
    	}
    	for(int i=0;i<=n;i++) {
    		for(int j=0;j<=maxB;j++)
    			dp[i][j]=-1;
    	}
    	int ans=solve(n,maxB),p=0;
    	for(int i=1;i<=maxB;i++) {
    		if(solve(n,i)==ans) {
    			p=i;
    			break;
    		}
    	}
    	cout<<p<<" "<<ans<<"\n";
    }
    return 0;
}