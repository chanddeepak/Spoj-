#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

struct time1 {
	int s,f;
};

bool cmp (time1 x,time1 y) {
	if(x.f==y.f)
		return x.s<y.s;
	return x.f<y.f;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int n;
    	cin>>n;
    	vector<time1> A(n);
    	for(int i=0;i<n;i++) {
    		cin>>A[i].s>>A[i].f;
    	}
    	sort(A.begin(),A.end(),cmp);
    	int ans=1,j=0;
    	for(int i=1;i<n;i++) {
    		if(A[j].f<=A[i].s) {
    			ans++;
    			j=i;
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}