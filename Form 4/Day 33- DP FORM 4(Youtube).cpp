#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
int x[1001];
int dp[1001][1001];

int rec(int l , int r){
    //pruning
    //basecase
    if(l+1==r) {//when it is a single piece we cannot break it further
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1) return dp[l][r];
    //compute
    int ans = 1e9;
    for(int p=l+1;p<=r-1;p++){
        ans = min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }
    //save and return
    return dp[l][r] = ans;
}

void solve(){
   cin>>n;
   for(int i=1;i<=n;i++){
       cin>>x[i];
   }
   x[0]=0;//to make the problem easier
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
