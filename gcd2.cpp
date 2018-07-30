#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

int gcd(int a,int b) {
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
    	int a;
    	string s;
    	cin>>a>>s;
    	if(a==0) {
    		cout<<s<<"\n";
    		continue;
    	}
    	int c=0;
    	for(int i=0;i<s.size();i++) {
    		int b=s[i]-'0';
    		c=(c*10+b)%a;
    	}
    	int ans=gcd(a,c);
    	cout<<ans<<"\n";
    }
    return 0;
}