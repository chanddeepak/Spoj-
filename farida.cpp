#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

long dp[10003];

long solve(vector<long> &A,int n) {

	if(n<0)
		return 0;
		
	if(dp[n]!=-1)
		return dp[n];

	long a=A[n]+solve(A,n-2);
	long b=solve(A,n-1);
	long c=A[n]+solve(A,n-3);

	return dp[n]=max(a,max(b,c));
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int i=1;
    while(t--) {
    	int n;
    	cin>>n;
    	vector<long> A(n);
    	for(int i=0;i<n;i++)
    		cin>>A[i];
    	for(int i=0;i<=n;i++)
    		dp[i]=-1;
    	long ans=solve(A,n-1);
    	cout<<"Case "<<i<<": "<<ans<<"\n";
    	i++;
    }
    return 0;
}