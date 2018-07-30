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
    	double n;
    	cin>>n;
    	double ans=(n/2*(4+(n-1)*3));
    	long a=(long)ans%1000007;
    	cout<<a<<"\n";
    }
    return 0;
}