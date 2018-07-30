#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pr pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;

struct node {
	int mf,ms;
}tree[4*100010];

int A[100010]; 

void buildTree(int s,int e,int i) {

	if(s==e) {
		tree[i].mf=arr[s];
		tree[i].ms=0;
		return;
	}

	int m=(s+e)/2;
	buildTree(s,m,2*i);
	buildTree(m+1,e,2*i+1)
	if(tree[2*i].mf<=tree[2*i+1].mf) {
		tree[i].mf=tree[2*i+1].mf;
		tree[i].sf=max(tree[2*i+1].sf,tree[2*i].mf);
	} else {
		tree[i].mf=tree[2*i].mf;
		tree[i].sf=max(tree[2*i].sf,tree[2*i+1].mf);
	}
}

void updateTree(int s,int e,int i,int idx,int value) {

	if(s==e) {
		tree[i].mf=arr[s];
		tree[i].ms=0;
		return;
	}

	int m=(s+e)/2;
	if(idx>m) {
		updateTree(m+1,e,2*i+1,idx,value);
	} else {
		updateTree(s,m,2*i,idx,value);
	}

	if(tree[2*i].mf<=tree[2*i+1].mf) {
		tree[i].mf=tree[2*i+1].mf;
		tree[i].sf=max(tree[2*i+1].sf,tree[2*i].mf);
	} else {
		tree[i].mf=tree[2*i].mf;
		tree[i].sf=max(tree[2*i].sf,tree[2*i+1].mf);
	}
}

node queryTree(int s,int e,int i,int l,int r) {

	if(s>r || e<l)
		return 0;

	if(s>=l && e<=r) {
		return tree[i];
	}

	int m=(s+e)/2;
	node ans1 = queryTree(s,m,2*i,l,r);
	node ans2 = queryTree(m+1,e,2*i+1,l,r);

	node ans;
	if(ans1.mf<=ans2.mf) {
		ans.mf=ans2.mf;
		ans.sf=max(ans2.sf,ans1.mf);
	} else {
		ans.mf=ans1.mf;
		ans.sf=max(ans1.sf,ans2.mf);
	}

	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>A[i];
    int q;
    cin>>q;
    while(q--) {
    	char c;
    	cin>>c;
    	if(c=='U') {
    		int i,x;
    		cin>>i>>x;
    		updateTree(1,n,1,i,x);
    	} else {
    		int x,y;
    		cin>>x>>y;
    		node ans=queryTree(1,n,1,x,y);
    		cout<<ans.mf+ans.ms<<"\n";
    	}
    }
    return 0;
}