#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
int in[20003],out[20003],parent[10003];

int find(int i) {
	if(parent[i]==0)
		return i;
	return find(parent[i]);
}

void Union(int a,int b) {
	int aset=find(a);
	int bset=find(b);
	parent[aset]=bset;
} 

bool isCycle(int m) {
	for(int i=0;i<m;i++) {
		int a=find(in[i]);
		int b=find(out[i]);

		if(a==b)
			return true;
		Union(a,b);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
    	cin>>in[i]>>out[i];
    }
    if(isCycle(m)) 
    	cout<<"NO\n";
    else
    	cout<<"YES\n";
    return 0;
}