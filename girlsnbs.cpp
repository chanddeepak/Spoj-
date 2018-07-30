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
    int g,b;
    while(1) {
    	cin>>g>>b;
    	if(g==-1&&b==-1)
    		break;
    	if(g==0&&b==0) {
    		cout<<0<<"\n";
    		continue;
    	}
    	if(g==0||b==0) {
    		if(g!=0)
    			cout<<g<<"\n";
    		else
    			cout<<b<<"\n";
    		continue;
    	}
    	int d=max(g,b);
    	int e=min(g,b);
    	if(d%(e+1)==0) {
    		cout<<d/(e+1)<<"\n";
    	} else {
    		cout<<d/(e+1)+1<<"\n";
    	}
    }
    return 0;
}