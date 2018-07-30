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
    int t;
    scanf("%d",&t);
    while(t--) {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	int g=__gcd(a,b);
    	int sq=sqrt(g);
    	int i=1,ans=0;
    	while(i<=sq) {
    		if(g%i==0) {
    			ans+=2;
    			if(i*i==g)
    				ans--;
    		}
    		i++;
    	}
	printf("%d\n",ans);
    }
    return 0;
}