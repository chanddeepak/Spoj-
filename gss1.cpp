#include<bits/stdc++.h>
using namespace std;
struct node{
  long maxSum,sum,bps,bss;
};
void buildTree(int* a,node* tree,int index,int start,int end) {
  if(start==end) {
    tree[index].maxSum=a[start];
    tree[index].sum=a[start];
    tree[index].bps=a[start];
    tree[index].bss=a[start];
    return;
  }
  int mid=(start+end)/2;
  buildTree(a,tree,2*index,start,mid);
  buildTree(a,tree,2*index+1,mid+1,end);
  
  node l=tree[2*index];
  node r=tree[2*index+1];
  
  tree[index].sum=l.sum+r.sum;
  tree[index].bps=max(l.bps,l.sum+r.bps);
  tree[index].bss=max(r.bss,r.sum+l.bss);
  tree[index].maxSum=max(max(l.maxSum,r.maxSum),max(max(l.sum+r.bps,r.sum+l.bss),l.bss+r.bps));
}
node queryTree(node* tree,int index,int start,int end,int left,int right) {
  if(start>right||end<left) {
    return ((node){INT_MIN,INT_MIN,INT_MIN,INT_MIN});
  }
  if(start>=left&&end<=right) {
    return tree[index];
  }
  int mid=(start+end)/2;
  node l=queryTree(tree,2*index,start,mid,left,right);
  node r=queryTree(tree,2*index+1,mid+1,end,left,right);
  
  node ans;
  ans.sum=l.sum+r.sum;
  ans.bps=max(l.bps,l.sum+r.bps);
  ans.bss=max(r.bss,r.sum+l.bss);
  ans.maxSum=max(max(l.maxSum,r.maxSum),max(max(l.sum+r.bps,r.sum+l.bss),l.bss+r.bps));
  return ans;
}
int main() {

	// Write your code here
  	int n;
  	scanf("%d",&n);
  	int a[n];
  	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
  	node tree[4*n+1];
  	buildTree(a,tree,1,0,n-1);
  	int m;
  	scanf("%d",&m);
  	while(m--) {
	      int x,y;
	      scanf("%d%d",&x,&y);
	      node ans=queryTree(tree,1,0,n-1,x-1,y-1);
	      cout<<ans.maxSum<<"\n";
    }
}