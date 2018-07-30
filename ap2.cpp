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
    int t;
    cin>>t;
    while(t--) {
    	int a,b,c;
    	cin>>a>>b>>c;
    	n=2*c/(a+b);
    	int p=n-4;
    	int d=(b-a)/p,f;
    	f=a-2*d;
    	cin>>n;
    	for(int i=0;i<n;i++) {
    		cout<<f<<" ";
    		f+=d;
    	}
    }
    return 0;
}