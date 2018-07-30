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
    int l;
    while(cin>>l) {
    	double ans=(double)(l*l)/(2*3.1415926);
    	cout<<fixed<<setprecision(2);
    	cout<<ans<<"\n";
    }
    return 0;
}