#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

struct val {
	int x,y,idx;
};

int block;
bool cmp(val a,val b) {
	if(a.x/block!=b.x/block)
		return a.x<b.x;
	return a.y<b.y;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) 
    	cin>>A[i];
    int m;
    cin>>m;
   	vector<val> v(m);
   	for(int i=0;i<m;i++) {
   		int a,b;
   		cin>>a>>b;
   		v[i].x=a-1;
   		v[i].y=b-1;
   		v[i].idx=i;
   	}
   	block=sqrt(n);
   	sort(v.begin(),v.end(),cmp);
   	vector<int> ans(m),freq(1000001,0);
   	int l=0,r=-1,c=0;	
   	for(int i=0;i<m;i++) {
   		while(r<v[i].y) {
   			r++;
   			freq[A[r]]++;
   			if(freq[A[r]]==1)
   				c++;
   		}
   		while(r>v[i].y) {
   			freq[A[r]]--;
   			if(freq[A[r]]==0)
   				c--;
   			r--;
   		}
   		while(l>v[i].x) {
   			l--;
   			freq[A[l]]++;
   			if(freq[A[l]]==1)
   				c++;
   		}
   		while(l<v[i].x) {
   			freq[A[l]]--;
   			if(freq[A[l]]==0)
   				c--;
   			l++;
   		}
   		ans[v[i].idx]=c;
   	}
   	for(int i=0;i<m;i++) 
   		cout<<ans[i]<<"\n";
    return 0;
}