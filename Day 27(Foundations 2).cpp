#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int w[3003];
int v[3003];
int W;
int dp[3003][3003];
int rec(int i,int x){
    //pruning
    //basecase
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x]!=-1) return dp[i][x];
    //transition
    int ans = rec(i+1,x);
    if(w[i]<=x){
        ans = max(ans,rec(i+1,x-w[i])+v[i]);
    }
    //save and return 
    return dp[i][x]=ans;
}

//for printing the solution

vector<int>solution
void generate(int i,int x){
    if(i==n) return;
    else{
        int donttake = rec(i+1,x);
        if(w[i]<=x){
            //can possibly take 
            int take = rec(i+1,x-w[i])+v[i];
            if(donttake>take){
                generate(i+1,x);
            }else{
                solution.push_back(i);
            }
        }else{
            //can't take
            generate(i+1,x);
        }
    }
}
//Note: Never use dp array.Always use recurrence.(There might be pruning case that might keep the dp array empty)

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,W)<<"\n";
    generate(0,W);
            
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}





