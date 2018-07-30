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
    int n;
    while(1) {
    	cin>>n;
    	if(n==-1)
    		break;
    	vector<int> v(n);
    	int s=0;
    	for(int i=0;i<n;i++) {
    		cin>>v[i];
    		s+=v[i];
    	}
    	int ans=-1;
    	if(s%n==0) {
    		s/=n;
    		ans=0;
    		for(int i=0;i<n;i++) {
    			if(v[i]<s) {
    				ans+=s-v[i];
    			}
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}