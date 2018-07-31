#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
const long MAX=1e13;
long A[100010][4],dp[100010][4];

long cal(int i,int j,int n) {
	if(i>n)
		return MAX;
	if(i==n&&j==1)
		return A[i][j];
	if(dp[i][j]!=MAX)
		return dp[i][j];
	if(j==0) 
		dp[i][j]=min(dp[i][j],A[i][j]+min(cal(i+1,j,n),min(cal(i+1,j+1,n),cal(i,j+1,n))));
	if(j==1)
		dp[i][j]=min(dp[i][j],A[i][j]+min(cal(i+1,j,n),
		min(cal(i+1,j+1,n),
		min(cal(i,j+1,n),cal(i+1,j-1,n)))));
	if(j==2)
		dp[i][j]=min(dp[i][j],A[i][j]+min(cal(i+1,j,n),cal(i+1,j-1,n)));

	return dp[i][j];

}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k=1;
    while(cin>>n) { 
	    if(n==0)
	    	break;
	    for(int i=0;i<n;i++)
	    	for(int j=0;j<3;j++)
	    		cin>>A[i][j];
	    for(int i=0;i<100010;i++)
	    	for(int j=0;j<4;j++)
	    		dp[i][j]=MAX;
	    long ans=cal(0,1,n-1);
	    cout<<k<<". "<<ans<<"\n";
	    k++;
	}
    return 0;
}