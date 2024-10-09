#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int w[3003];
int v[3003];
int W;
int dp[3003][3003];
int rec(int i,int x){
    //pruning
    //basecase
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x]!=-1) return dp[i][x];
    //transition
    int ans = 0 ;
    for(int num_of_times=0;num_of_times<=x/w[i];num_of_times++){
        ans = max(ans,rec(i+1,x - num_of_times*w[i])+num_of_times*v[i])
    }
    //save and return 
    return dp[i][x]=ans;
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
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<"\n";
    generate(0,W);
            
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}










