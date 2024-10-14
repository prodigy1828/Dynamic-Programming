#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n,m,x;
string a,b,c;
int dp[1001][1001][1001];

int rec(int i ,int j ,int k){//return the LCS of a[i....n] and b[j....m] 
    //pruning 
    //basecase     
    if(i>=n||j>=m||k>=x){
        return 0; 
    }
    //cache check
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    //compute
    int ans = 0 ;
    ans = max(ans,rec(i+1,j,k));
    ans = max(ans,rec(i,j+1,k));
    ans = max(ans,rec(i,j,k+1));
    if(a[i]==b[j] && b[j]==c[k]){
        ans = max(ans,1+rec(i+1,j+1,k+1));
    }
    //save and return
    return dp[i][j][k]=ans;
}

void solve(){
    cin>>n>>m>>x>>a>>b>>c;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
