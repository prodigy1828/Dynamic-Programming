#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int insertedat[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>lis;
    for(int i=0;i<n;i++){
        if(lis.empty() || lis.back()<arr[i]){
            lis.push_back(arr[i]);
            insertedat[i] = lis.size();
        }
        else{
            auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
            *it = arr[i];
            insertedat[i] = it-lis.begin()+1;
        }
        cout<<i<<":[";
        for(auto v : lis){
            cout<<v<<",";
        }cout<<"]"<<endl;
    }
    for(int i=0;i<n;i++) {
        cout<<insertedat[i]<<",";
    }
    cout<<endl;
    vector<int>final_lis;
    int curlen = lis.size();
    for(int i=n-1;i>=0;i--){
        if(insertedat[i]==curlen){
            final_lis.push_back(arr[i]);
            curlen--;
        }
    }
    reverse(final_lis.begin(),final_lis.end());
    cout<<lis.size()<<endl;
    for(auto v : final_lis){cout<<v<<",";}
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //int tc;cin>>tc;while(tc--)
    solve();
}














 
