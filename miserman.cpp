#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    int A[N][M],dp[N][M];
    for(int i=0;i<N;i++) {
    	for(int j=0;j<M;j++) 
    		cin>>A[i][j];
    }
    for(int i=0;i<M;i++)
    	dp[0][i]=A[0][i];
    for(int i=1;i<N;i++) {
    	for(int j=0;j<M;j++) {
    		dp[i][j]=INT_MAX;
    		if(j>0&&j<M-1)
    			dp[i][j]=min(dp[i][j],A[i][j]+min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1])));
    		else if(j==0)
    			dp[i][j]=min(dp[i][j],A[i][j]+min(dp[i-1][j],dp[i-1][j+1]));
    		else if(j==M-1)
    			dp[i][j]=min(dp[i][j],A[i][j]+min(dp[i-1][j],dp[i-1][j-1]));
    	}
    }
    int ans=INT_MAX;
    for(int i=0;i<M;i++){
    	if(ans>dp[N-1][i])
    		ans=dp[N-1][i];
    } 
    cout<<ans<<"\n";
    return 0;
}