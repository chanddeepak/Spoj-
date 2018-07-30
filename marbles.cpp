#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

long solve(long n,long k) {
	if(k>n-k)
		k=n-k;
	long ans=1;
	for(int i=0;i<k;i++) {
		ans=(ans*(n-i))/(i+1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	long n,k;
    	cin>>n>>k;
    	long ans=solve(n-1,k-1);
    	cout<<ans<<"\n";
    }
    return 0;
}