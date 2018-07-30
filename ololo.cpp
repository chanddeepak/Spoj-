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
    cin>>n;
    unordered_map<long,int> m;
    for(int i=0;i<n;i++) {
    	long x;
    	cin>>x;
    	m[x]++;
    }
    long a;
    for(auto it=m.begin();it!=m.end();it++) {
    	if(it->second==1) {
    		a=it->first;
    	}
    }
    cout<<a<<"\n";
    return 0;
}