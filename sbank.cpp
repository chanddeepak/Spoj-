#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
    	int n;
    	scanf("%d\n",&n);
    	map<string,int> m;
    	string s;
    	for(int i=0;i<n;i++) {
    		getline(cin,s);
    		m[s]++;
    	}
    	map<string,int>::iterator it;
    	for(it=m.begin();it!=m.end();it++) {
    		printf("%s %d\n",it->first.c_str(),it->second);
    	}
    	printf("\n");
    	
    }
    return 0;
}