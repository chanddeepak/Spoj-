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
    	long n;
    	cin>>n;
    	long a=sqrt(n),b=0,f=0;
    	while(b<=a) {
    		long s=a*a+b*b;
    		if(s==n) {
    			f=1;
    			cout<<"Yes\n";
    			break;
    		}
    		if(s>n) {
    			a--;
    		} else {
    			b++;
    		}
    	}
    	if(f==0) {
    		cout<<"No\n";
    	}
    }
    return 0;
}