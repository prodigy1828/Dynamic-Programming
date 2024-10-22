#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

string s1,s2;
int n,m;
int dp[1001][1001];

int rec(int i,int j){
    //pruning
    //base case
    if(i==n||j==n){
        return (n-i)+(m-j);
    }
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    int ans  = min({rec(i+1,j+1),rec(i+1,j),rec(i,j+1)})+1;
    if(s1[i]==s2[j]) ans = min(ans,rec(i+1,j+1));
    return dp[i][j]=ans ;
}

void solve(){
    cin>>s1>>s2;
    n=s1.size();
    m=s2.size();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
