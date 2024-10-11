#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n,k;
int arr[1001];
int dp[1001][101];

int rec(int i ,int x){
    //pruning
    if(x<0) return 1e9;
    //base case
    if(i==-1){
        if(x==0) return 0;
        else {
        //invalid 
            return INF;    
        }
    }
    //cache check
    if(dp[i][x]!=-1) return dp[i][x];
    //transition
    int ans=INF;
    int min_seen = arr[i];
    for(int j=i-1;j>=-1;j--){
        ans = min(ans,rec(j,x-1)+min_seen); // Keep a running minimum that changes as the loop runs backwards 
        min_seen=min(min_seen,arr[j]);
    }
    //save and return 
    return dp[i][x]=ans;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
