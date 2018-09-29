#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 1000000
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

long BIT[10010],n;

void update(int i,long v) {
	for(;i<=n;i+=(i&-i)) {
		BIT[i]+=v;
	}
}

long query(int i) {
	long sum=0;
	for(;i>0;i-=(i&-i))
		sum+=BIT[i];
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int u;
    	cin>>n>>u;
    	memset(BIT,0,sizeof(BIT));
    	while(u--) {
    		int l,r;
    		long v;
    		cin>>l>>r>>v;
    		update(l+1,v);
    		update(r+2,-v);
    	}
    	int q;
    	cin>>q;
    	while(q--) {
    		int x;
    		cin>>x;
    		cout<<query(x+1)<<"\n";
    	}
    }
    return 0;
}