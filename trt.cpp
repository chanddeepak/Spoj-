#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

long dp[2002][2002];

long solve(vector<long> &A,int i,int j,int n) {

	if(i+n-j>n)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	long a=A[i]*(i+n-j)+solve(A,i+1,j,n);
	long b=A[j]*(i+n-j)+solve(A,i,j-1,n);
	return dp[i][j]=max(a,b); 
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long> A(n);
    for(int i=0;i<n;i++) 
    	cin>>A[i];
    for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
		dp[i][j]=-1;
    long ans=solve(A,0,n-1,n);
    cout<<ans<<"\n";
    return 0;
}