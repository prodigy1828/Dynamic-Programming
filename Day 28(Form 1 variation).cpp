#include<bits/stdc++.h>
using namespace std;
int n,t;
int x[101];
int dp[105][100100];
void rec(int level,int taken){
    if(left<0) return 0;
    if(level==n+1){
        if(left==0){
            return 1;
        }else{
            return 0;
        }
    }
    //cache check
    if(dp[level][left]!=-1) return dp[level][left];
    //compute
    int ans=0;
    if(rec(level+1,left)=1;){
        ans=1;
    }else if(rec(level+1,left-x[level])){
        ans=1;
    }
    return dp[level][left]=ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cin>>t;
    memset(dp,-1,sizeof(dp));
    int q;cin>>q;
    while(q--){
        cin>>t;
        cout<<rec(1,t)<<endl;
    }
}














 