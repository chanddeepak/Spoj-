#include<bits/stdc++.h>
using namespace std;

void updateTreeLazy(long* tree,long* lazy,int curPos,int low,int high,int startR,int endR,long val) {
  if(low>high)
    return;
  if(lazy[curPos]!=0) {
    tree[curPos]+=(high-low+1)*lazy[curPos];
    if(low!=high) {
      lazy[2*curPos]+=lazy[curPos];
      lazy[2*curPos+1]+=lazy[curPos];
    }
    lazy[curPos]=0;
  }
  if(low>endR||high<startR)
    return;
  if(low>=startR&&high<=endR) {
    tree[curPos]+=(high-low+1)*val;
    if(low!=high) {
		lazy[2*curPos]+=val;
      	lazy[2*curPos+1]+=val;
    }
    return;
  }
  int mid=(low+high)/2;
  updateTreeLazy(tree,lazy,2*curPos,low,mid,startR,endR,val);
  updateTreeLazy(tree,lazy,2*curPos+1,mid+1,high,startR,endR,val);
  tree[curPos]=tree[2*curPos]+tree[2*curPos+1];
}
long queryTree(long* tree,long* lazy,int curPos,int low,int high,int startR,int endR) {
  if(low>high)
    return 0;
  if(lazy[curPos]!=0) {
      // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[low..high] and
        // all these elements must be increased by lazy[curPos]
    tree[curPos]+=(high-low+1)*lazy[curPos];
    if(low!=high) {
      lazy[2*curPos]+=lazy[curPos];
      lazy[2*curPos+1]+=lazy[curPos];
    }
    lazy[curPos]=0;
  }
  if(low>endR||high<startR)
    return 0;
  if(low>=startR&&high<=endR) {
    return tree[curPos];
  }
  int mid=(low+high)/2;
  long ans1=queryTree(tree,lazy,2*curPos,low,mid,startR,endR);
  long ans2=queryTree(tree,lazy,2*curPos+1,mid+1,high,startR,endR);
  return ans1+ans2;
}
int main() {

	// Write your code here
  	int t;
  	cin>>t;
  	while(t--) {
      int n,c;
      cin>>n>>c;
      long* tree=new long[4*n+1]();
      long* lazy=new long[4*n+1]();
      while(c--) {
        int x;
        cin>>x;
        if(x==0) {
          long p,q,v;
          cin>>p>>q>>v;
          updateTreeLazy(tree,lazy,1,0,n-1,p-1,q-1,v);
        } else {
          int p,q;
          cin>>p>>q;
          long ans=queryTree(tree,lazy,1,0,n-1,p-1,q-1);
          cout<<ans<<"\n";
        }
      }
    }
  return 0;
}