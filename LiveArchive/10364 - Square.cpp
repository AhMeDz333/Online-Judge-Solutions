#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (int)(n); i++)
#define RFOR(i,x,n) for (int i = x; i < (int)(n); i++)
#define take(n) scanf("%d",&n)
#define take2(n,m) scanf("%d%d",&n,&m)
#define take3(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define takell(n) scanf("%lld",&n)
#define takes(n) scanf("%s",n)
#define takef(n) scanf("%lf",&n)
#define ii pair <int,int>
#define is pair <int,string>
#define ll long long
#define N 1010
#define vi vector <int>
#define iv pair <int,vi>
#define vll vector <ll>
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define write(s) freopen(s,"w",stdout)

int arr[20],n,dp[(1 << 20)+10],sum;

bool solve(int l,int mask){
	//printf("%d\n",mask);
	if (4*l > sum)
		return 0;
	if (4*l == sum)
		if (mask == (1 << n)-1)
			return 1;
		else
			l = 0;
	if (dp[mask] != -1) return dp[mask];
	FOR(i,n)
		if (!(mask & (1 << i)) && solve(l+arr[i],mask | (1 << i)))
			return true;
	return dp[mask] = 0;
}

int main(){
	//read("in.txt");
	int t,ans;
	take(t);
	while(t--){
		ans = 0;
		memset(dp,-1,sizeof dp);
		take(n);
		FOR(i,n)
			take(arr[i]);
		sum = accumulate(arr,arr+n,0);
		if (sum % 4)
			printf("no\n");
		else
			printf("%s\n",solve(0,0)? "yes" : "no");
	}
}
