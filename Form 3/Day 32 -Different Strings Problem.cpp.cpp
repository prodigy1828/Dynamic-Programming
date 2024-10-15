#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
string x,y;
int n,m;
//vector<vector<int>>dp;
int dp[5050][5050];

int rec(int l1 , int l2){
    //pruning
    //basecase
    if(l1==n && l2==m) return 0;
    //cache check
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    //compute
    int ans  = INF;
    if(l1<n){//-x[l1]
        ans  = min(ans,1LL + rec(l1+1,l2));
    }
    if(l2<m){//+y[l2]
        ans = min(ans,1LL + rec(l1,l2+1));
    }
    if(l1<n && l2<n && x[l1]==y[l2]){//x[l1](0)
        ans = min(ans,1LL+rec(l1+1,l2+1));
    }
    //save and return
    return dp[l1][l2] = ans;
}

void solve(){
    cin>>x>>y;
    n = x.length();
    m = y.length();
    //dp.resize(n+1);
    // for(int i=0;i<n;i++){
    //     dp[i].assign(m+1,-1);
    // }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 