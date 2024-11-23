#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9;

int a,b;
int dp[1001][1001];

int rec(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    int ans = 0 ;
    for(int z=1;z<=x;z++){
        if(rec(x-z,y)==0) ans=1; 
    }
    for(int z=1;z<=y;z++){
        if(rec(x,y-z)==0) ans = 1;
    }
    for(int k=1;k<=min(x,y);k++){
        if(rec(x-k,y-k)==0) ans = 1;
    }
    return dp[x][y] = ans;
}

void solve(){
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<rec(a,b)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}





