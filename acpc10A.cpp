#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    while(1) {
	    cin>>a>>b>>c;
	    if(a==0&&b==0&&c==0)
	    	return 0;
	    if(2*b==a+c) {
	    	cout<<"AP "<<c+c-b<<"\n";
	    } else {
	    	cout<<"GP "<<a*c/b<<"\n";
	    }
	}
    return 0;
}