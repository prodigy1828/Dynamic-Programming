#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n,m;
int dp[1001][1001];

int rec(int x,int y){
    if(x==0 && y==0) {
        return 0;
    }
    if(dp[x][y]!=-1) return dp[x][y];
    int win = 0;
    for(int i=1;i<=x;i++){
        if(rec(x-i,y)==0) win=1;
    }
    for(int i=1;i<=y;i++){
        if(rec(x,y-i)==0) win=1;
    }
    for(int i=1;i<=min(x,y);i++){
        if(rec(x-i,y-i)==0) win=1;
    }
    return dp[x][y] = win;
}

void solve(){
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    cout<<rec(n,m)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
