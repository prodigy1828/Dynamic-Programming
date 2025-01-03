#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
int arr[10010];
int dp[10010];

int rec(int i,int d,int seenk){
    //LIS ending at a level
    //pruning
    if(level<0) return 0;
    //base case
    //->here we do not need a base case as the transitions would automatically return when the loop ends
    //cache check
    if(dp[level]!=-1) return dp[level];
     //compute
    int ans=1;
    for(int prev_taken=0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
        ans = max(ans,1+rec(prev_taken));
        }
    }
    //save and return
    return dp[level]=ans;
 
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    int best = 0 ;
    for(int i=0;i<n;i++){
        best = max(best,rec(i));//to find the  best LIS
    }
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
