#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
struct node {
	long sum,preSum,sufSum,maxSum;
};
vector<node> tree(4*100010);
vector<long> A(100010);

void buildTree(int i,int s,int e) {
	if(s==e) {
		tree[i].sum=A[s];
		tree[i].preSum=A[s];
		tree[i].sufSum=A[s];
		tree[i].maxSum=A[s];
		return;
	}
	int m=(s+e)/2;
	buildTree(2*i,s,m);
	buildTree(2*i+1,m+1,e);

	tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
	tree[i].preSum=max(tree[2*i].preSum,tree[2*i].sum+tree[2*i+1].preSum);
	tree[i].sufSum=max(tree[2*i+1].sufSum,tree[2*i+1].sum+tree[2*i].sufSum);
	tree[i].maxSum=max(tree[2*i].maxSum,
		max(tree[2*i+1].maxSum,
		max(tree[2*i].sum+tree[2*i+1].preSum,
		max(tree[2*i].sufSum+tree[2*i+1].sum,tree[2*i+1].preSum+tree[2*i].sufSum))));
}

void update(int i,int s,int e,int idx,int v) {
	if(s==e) {
		tree[i].sum=v;
		tree[i].preSum=v;
		tree[i].sufSum=v;
		tree[i].maxSum=v;
		return;
	}
	int m=(s+e)/2;
	if(idx>m) 
		update(2*i+1,m+1,e,idx,v);
	else
		update(2*i,s,m,idx,v);

	tree[i].sum=tree[2*i].sum+tree[2*i+1].sum;
	tree[i].preSum=max(tree[2*i].preSum,tree[2*i].sum+tree[2*i+1].preSum);
	tree[i].sufSum=max(tree[2*i+1].sufSum,tree[2*i+1].sum+tree[2*i].sufSum);
	tree[i].maxSum=max(tree[2*i].maxSum,
		max(tree[2*i+1].maxSum,
		max(tree[2*i].sum+tree[2*i+1].preSum,
		max(tree[2*i].sufSum+tree[2*i+1].sum,tree[2*i+1].preSum+tree[2*i].sufSum))));
}

node query(int i,int s,int e,int le,int ri) {
  if(s>ri||e<le) {
    return ((node){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
  }
  if(s>=le&&e<=ri) {
    return tree[i];
  }
  int m=(s+e)/2;
  node l=query(2*i,s,m,le,ri);
  node r=query(2*i+1,m+1,e,le,ri);
  
  node ans;
  ans.sum=l.sum+r.sum;
  ans.preSum=max(l.preSum,l.sum+r.preSum);
  ans.sufSum=max(r.sufSum,r.sum+l.sufSum);
  ans.maxSum=max(max(l.maxSum,r.maxSum),max(max(l.sum+r.preSum,r.sum+l.sufSum),l.sufSum+r.preSum));
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
    	cin>>A[i];
    }
    buildTree(1,1,n);
    int m;
    cin>>m;
    while(m--) {
    	int p;
    	cin>>p;
    	if(p==0) {
    		int x,y;
    		cin>>x>>y;
    		update(1,1,n,x,y);
    	} else {
    		int x,y;
    		cin>>x>>y;
    		node ans=query(1,1,n,x,y);
    		cout<<ans.maxSum<<"\n";
    	}
    }
    return 0;
}