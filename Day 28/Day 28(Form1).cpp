#include<bits/stdc++.h>
using namespace std;
int n,t;
int x[101];
int dp[105][100100];
void rec(int level,int taken){
    if(taken>t) return 0;
    if(level==n+1){
        if(t==taken){
            return 1;
        }else{
            return 0;
        }
    }
    //cache check
    if(dp[level][taken]!=-1) return dp[level][taken];
    //compute
    int ans=0;
    if(rec(level+1,taken)=1;){
        ans=1;
    }else if(rec(level+1,taken-x[level])){
        ans=1;
    }
    return dp[level][taken]=ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cin>>t;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0)<<endl;
}














 
