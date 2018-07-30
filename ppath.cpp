#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pr pair<int,int>
typedef long long ll;
vector<bool> prime(10002,0);

void sieve() {
	for(int i=2;i<=100;i++) {
		if(prime[i]==false) {
			for(int j=i*2;j<=10000;j+=i) {
				prime[j]=true;
			}
		}
	}
}

int bfs(int x,int y) {
	if(x==y)
		return 0;
	vector<bool> visited(10002,false);
	queue<pr> qu;
	qu.push(mp(x,0));
	while(!qu.empty()) {
		pr u=qu.front();
		qu.pop();
		if(u.fi==y)
			return u.se;
		int a=u.fi,p,q,r,s;
		p=a%10;
		q=(a/10)%10;
		r=(a/100)%10;
		s=(a/1000)%10;
		for(int i=0;i<=9;i++) {
			int t=s*1000+r*100+q*10+i;
			if(!prime[t]&&!visited[t]) {
				visited[t]=true;
				qu.push(mp(t,u.se+1));
			}
		}
		for(int i=0;i<=9;i++) {
			int t=s*1000+r*100+i*10+p;
			if(!prime[t]&&!visited[t]) {
				visited[t]=true;
				qu.push(mp(t,u.se+1));
			}
		}
		for(int i=0;i<=9;i++) {
			int t=s*1000+i*100+q*10+p;
			if(!prime[t]&&!visited[t]) {
				visited[t]=true;
				qu.push(mp(t,u.se+1));
			}
		}
		for(int i=1;i<=9;i++) {
			int t=i*1000+r*100+q*10+p;
			if(!prime[t]&&!visited[t]) {
				visited[t]=true;
				qu.push(mp(t,u.se+1));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--) {
    	int x,y;
    	cin>>x>>y;
    	int ans=bfs(x,y);
    	cout<<ans<<"\n";
    }
    return 0;
}