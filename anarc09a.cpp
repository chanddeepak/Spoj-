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
    int j=1;
    while(1) {
    	string s;
    	cin>>s;
    	if(s[0]=='-')
    		break;
    	int c=0,o=0;
    	for(int i=0;i<s.size();i++) {
    		if(s[i]=='{') {
    			c++;
    		} else {
    			c--;
    			if(c<0) {
    				c=1;
    				o++;
    			}
    		}
    	}
    	cout<<j<<". "<<o+c/2<<"\n";
    	j++;
    }
    return 0;
}