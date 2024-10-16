#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int w[3003];
int v[3003];
int W;
int dp[1001][1001][1001];
int k;
int rec(int i,int x,int item_left){
    //max value you can make[i....N] ,where X is the weight left and item left is the number of item left to be taken at max 
    //pruning
    //basecase
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x][item_left]!=-1) return dp[i][x][item_left];
    //transition
    int ans = rec(i+1,x,item_left);
    if(w[i]<=x && item_left>0){
        ans = max(ans,rec(i,x-w[i],item_left-1)+v[i]);
    }
    //save and return 
    return dp[i][x][item_left]=ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    cin>>k;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W,k)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}









