#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;


vector<int> divisors[1000100];
void precompute(int x){ // O(x* log(x))
    for(int i=1;i<=x;i++){
        for(int j=i;j<=x;j+=i){
            divisors[j].push_back(i);
        }
    }
}
int dp[1000100];
int rec(int x){
    if(dp[x]!=-1)return dp[x];
    int ans = 0;
    for(auto v: divisors[x]){
        if(v!=1 && v!=x && rec(x-v)==0){
            ans = 1;
        }
    }
    return dp[x] = ans;
}

int magic(int x){
    if(x%2==0){
        // even
        if((x&(x-1))==0){
            // power of 2
            int cnt = 0;
            while(x!=1){
                cnt++;
                x = x/2;
            }
            if(cnt%2==0){
                return 1;
            }else{
                return 0;
            }
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}

int main()
{   
    precompute(100000);
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=100000;i++){
        // if(i%2==0 && rec(i)==0){
        //     cout<<i<<endl;
        // }
        if(magic(i)!=rec(i)){
            cout<<i<<endl;
        }
        // cout<<i<<" :"<<rec(i)<<endl;
    }
}
