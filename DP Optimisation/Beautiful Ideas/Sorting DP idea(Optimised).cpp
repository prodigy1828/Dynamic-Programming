#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9+7;

int n,a,b;
vector<pair<int,int>>ab;
int dp[1001][1001];

int rec(int i,int nb) {
    int na = i - nb;
    if (na > a || nb > b) return -INF;
	if(i==n) {
		if(na==a && nb==b) return 0;
		else return -INF; 
	}
	if(dp[i][nb]!=-1) return dp[i][nb];
	int ans =0;
		if(na<a){
	    ans = max(ans,rec(i+1,nb)+ab[i].first);
	}else{
	    ans = max(ans,rec(i+1,nb));
	}
	if(nb<b){
	    ans = max(ans,rec(i+1,nb+1)+ab[i].second);
	}
	return dp[i][nb] = ans;
}

void solve() {
	cin>>n>>a>>b;
	ab.resize(n);
	for(int i=0; i<n; i++) {
		cin>>ab[i].first>>ab[i].second;
	}
	sort(ab.rbegin(),ab.rend());
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int tc;cin>>tc;while(tc--)
	solve();
}





