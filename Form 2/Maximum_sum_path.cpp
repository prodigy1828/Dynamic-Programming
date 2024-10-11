#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n,m;
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];

int rec(int r ,int c){
    //pruning 
    if(r<0||c<0){
        return -INF;
    }
    //base case
    if(r==0 && c==0){
        return arr[0][0];
    }
    
    //cache
    if(done[r][c]!=-1) return dp[r][c];
    //compute
    int ans = -INF;
    if(c!=0){
        ans =  max(ans,rec(r,c-1)+arr[r][c]);
    }
    if(r!=0){
    int ans = max(ans,rec(r-1,c)+arr[r][c]);
    }
    //save and return 
    done[r][c]=1;
    return dp[r][c]=ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    memset(done,0,sizeof(dp));
    cout<<rec(n-1,m-1)<<end;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
