#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
int n;
int w[3003];
int v[3003];
int W;
int dp[1001][1001][1001];
int k;
int m;
int rec(int i,int x,int item_left,bool last_taken){
    //max value you can make[i....N] ,where X is the weight left and item left is the number of item left to be taken at max 
    //pruning
    //basecase
    if(i==n){
        int sum_of_taken = (W-x);
        if(sum_of_taken%M==0){
            //valid solution
            return 0;
        }else{
            //invalid 
            return -INF;
        }
        return 0;
    }
    //cache check
    if(dp[i][x][item_left][last_taken]!=-1) return dp[i][x][item_left][last_taken];
    //transition
    int ans = rec(i+1,x,item_left,0);
    if(w[i]<=x && item_left>0 && !last_taken){
        ans = max(ans,rec(i,x-w[i],item_left-1,1)+v[i]);
    }
    //save and return 
    return dp[i][x][item_left][last_taken]=ans;
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










