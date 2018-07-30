#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAX 1000000000000
typedef long long ll;
int q;
long dp[10002];
long cal(vector<long> &p,vector<long> &w,int W) {
	if(W==0) {
		q=1;
		return 0;
	}
	if(W<0)
		return MAX;
	if(dp[W]!=-1)
		return dp[W];
	long ans=MAX;
	for(int i=0;i<p.size();i++) {
		//if(w[i]<=W) {
			ans=min(ans,cal(p,w,W-w[i])+p[i]);
		//}
	}
	return dp[W]=ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int e,f,n;
    	cin>>e>>f>>n;
    	vector<long> p(n),w(n);
    	for(int i=0;i<n;i++) {
    		cin>>p[i]>>w[i];
    	}
    	for(int i=0;i<=f-e;i++)
    		dp[i]=-1;
    	q=0;
    	long ans=cal(p,w,f-e);
    	if(q==1)
    		cout<<"The minimum amount of money in the piggy-bank is "<<ans<<".\n";
    	else 
    		cout<<"This is impossible.\n";
    }
    return 0;
}