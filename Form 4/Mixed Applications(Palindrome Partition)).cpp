#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

int n;
string s;
int dp1[1001][1001];
int dp2[1001];
int rec1(int l,int r){ //check palindrome
    if(l>=r) return 1;
    if(dp1[l][r]!=-1) return dp[l][r];
    int ans=0;
    if(s[l-1]==s[r+1] && rec1(l+1,r-1)) ans=1;
    return dp[l][r]=ans;
}

int rec2(int i){ //min cuts for [1.....i]
    if(i==0) return -1;
    if(dp2[i]!=-1) return dp2[i];
    int ans = 1e9;
    for(int j=i-1;j>0;j--){
        if(dp1(j+1,i)){
            ans=min(ans,rec2(j)+1);
        }
    }
    return dp2[i]=ans ;
}

void solve(){
    cin>>n;
    cin>>s;
    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));
    cout<<rec2(n)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
