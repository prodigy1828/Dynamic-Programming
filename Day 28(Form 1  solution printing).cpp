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

vector<int>ans;
void printset(int level,int taken){
    if(level==n+1) return; //done with the whole flow
    //find the correct transition
    if(rec(level+1,taken)==1){//don't take and won't be printing the solution
        printset(level+1,taken);
    }else if(rec(level+1,left-x[level])){//take and print it
        cout<<x[level]<<" ";
        printset(level+1,taken+x[level]);
    }
    
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cin>>t;
    memset(dp,-1,sizeof(dp));
    if(rec(1,t)){
        printset(1,t);
        cout<<endl;
    }else{
        cout<<"No Solution";
    }
}














 