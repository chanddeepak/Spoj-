#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
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
    	long A,B;
    	cin>>A>>B;
    	long g=__gcd(A,B);
    	long lcm=(A*B)/g;
    	long x=lcm/A,y=lcm/B;
    	cout<<x<<" "<<y<<"\n";
    }
    return 0;
}