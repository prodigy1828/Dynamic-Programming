#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1E9+7;

int n,a,b;
vector<pair<int,int>>ab;
int dp[101][101][101];

int rec(int i,int na,int nb) {
	if(na>a||nb>b) return -INF;
	if(i==n) {
		if(na==a && nb==b) return 0;
		else return -INF; 
	}
	if(dp[i][na][nb]!=-1) return dp[i][na][nb];
	int ans = max({A[i]+rec(i+1,na+1,nb),B[i]+rec(i+1,na,nb+1),rec(i+1,na,nb)});
	return dp[i][a][b] = ans;
}

void solve() {
	cin>>n>>a>>b;
	ab.resize(n);
	for(int i=0; i<n; i++) {
		cin>>ab[i].first>>ab[i].second;
	}
	memset(dp,-1,sizeof(dp));
	cout<<rec(0,0,0)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//int tc;cin>>tc;while(tc--)
	solve();
}





