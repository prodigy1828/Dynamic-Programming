#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
string x,y;
int n,m;
//vector<vector<int>>dp;
int dp[5050][5050];
int back[5005][5005];

int rec(int l1 , int l2){
    //pruning
    //basecase
    if(l1==n && l2==m) return 0;
    //cache check
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    //compute
    int ans  = INF;
    if(l1<n){//-x[l1]
        if(1LL + rec(l1+1,l2)<ans){
            ans = rec(l1+1,l2)+1LL;
            back[l1][l2] = 0 ;
        }
    }
    if(l2<m){//+y[l2]
        if(1 + rec(l1,l2+1)<ans){
            ans =1LL+ rec(l1,l2+1);
            back[l1][l2] = 1;
        }
    }
    if(l1<n && l2<n && x[l1]==y[l2]){//x[l1](0)
        if(1LL+rec(l1+1,l2+1)<ans){
            ans =1LL+rec(l1+1,l2+1);
            back[l1][l2] = 2;
        }
    }
    //save and return
    return dp[l1][l2] = ans;
}

void generate(int l1,int l2){
    if(l1==n && l2==m) return ;
    int ch = back[l1][l2];
    if(ch==0){
        cout<<"-"<<x[l1]<<" ";
        generate(l1+1,l2);
    }else if(ch==1){
        cout<<"+"<<y[l2]<<" ";
        generate(l1,l2+1);
    }else if(ch==2){
        cout<<x[l1]<<" ";
        generate(l1+1,l2+1);
    }
    return;
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
    generate(0,0);//O(answer)->O(n+m) at worst case
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 