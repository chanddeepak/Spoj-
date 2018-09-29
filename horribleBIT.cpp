#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 100010
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int n;
long BIT1[MAX],BIT2[MAX];

void update(long* BIT,int i,long v) {
	for(;i<=n;i+=(i&-i)) 
		BIT[i]+=v;
}

long query(long *BIT,int i) {
	long ans=0;
	for(;i>0;i-=(i&-i))
		ans+=BIT[i];
	return ans;
}

long get(int x) {
	return query(BIT1,x)*x-query(BIT2,x);
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int c;
    	cin>>n>>c;
    	memset(BIT1,0,sizeof(BIT1));
    	memset(BIT2,0,sizeof(BIT2));
		while(c--) {
			int x;
			cin>>x;
			if(x==0) {
				int p,q;
				long v;
				cin>>p>>q>>v;
				update(BIT1,p,v);
				update(BIT1,q+1,-v);
				update(BIT2,p,v*(p-1));
				update(BIT2,q+1,-v*q);
			} else {
				int p,q;
				cin>>p>>q;
				cout<<get(q)-get(p-1)<<"\n";
			}
		}	
    }
    return 0;
}