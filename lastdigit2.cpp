#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int modExp(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) {
			ans=(ans*a)%10;
		}
		b=b/2;
		a=(a*a)%10;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	string a;
    	cin>>a;
    	long b;
    	cin>>b;
    	int c=a[a.size()-1]-'0';
    	cout<<modExp(c,b)<<"\n";
    }
    return 0;
}