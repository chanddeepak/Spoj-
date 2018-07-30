#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;

int dp[102][102],sum[102];

int solve(int i,int j) {
  if(i==j)
    return 0;
  if(dp[i][j])
    return dp[i][j];
  int ans=INT_MAX;
  for(int k=i;k<j;k++) {
    ans=min(ans, solve(i,k)+solve(k+1,j)+((sum[k]-sum[i-1])%100)*((sum[j]-sum[k])%100));
  }
  return dp[i][j]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n) {
    	vector<int> A(n);
    	for(int i=0;i<n;i++) {
    		cin>>A[i];
    		if(i==0)
    			sum[i]=A[i];
    		else
    			sum[i]=sum[i-1]+A[i];
    	}
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++)
    			dp[i][j]=0;
    	int ans=solve(0,n-1);
    	cout<<ans<<"\n";
    }
    return 0;
}