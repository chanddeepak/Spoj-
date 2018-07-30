#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n,m;
    cin>>n>>m;
    vector<int> sum(n+1,0);
    for(int i=1;i<=n;i++) {
    	int a;
    	cin>>a;
    	sum[i]=sum[i-1]+a;
    }
    int j=0;
    long ans=0;
    for(int i=1;i<=n;i++) {
    	if(sum[i]-sum[j]==m) {
    		ans=m;
    		break;
    	} else if(sum[i]-sum[j]<m) {
    		if(ans<sum[i]-sum[j])
    			ans=sum[i]-sum[j];
    	} else {
    		while(sum[i]-sum[j]>m)
    			j++;
    		if(ans<sum[i]-sum[j])
    			ans=sum[i]-sum[j];
    	}
    }
    cout<<ans<<"\n";
    return 0;
}