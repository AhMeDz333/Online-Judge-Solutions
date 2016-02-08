#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (int)(n); i++)
#define RFOR(i,x,n) for (int i = (x); i <= (int)(n); i++)
#define take(n) scanf("%d",&n)
#define take2(n,m) scanf("%d%d",&n,&m)
#define take3(n,m,k) scanf("%d%d%d",&n,&m,&k)
#define takell(n) scanf("%lld",&n)
#define takes(n) scanf("%s",n)
#define takef(n) scanf("%lf",&n)
#define ii pair <int,int>
#define is pair <int,string>
#define pdd pair <double,double>
#define ll long long
#define LSB(x) (x & (-x))
#define N 7
#define INF INT_MAX
#define vi vector <int>
#define vs vector<string>
#define iv pair <int,vi>
#define pss pair <string,string>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define write(s) freopen(s,"w",stdout)
#define left(x) (2*x)
#define right(x) (2*x+1)
#define gc getchar_unlocked

const int M = 8;

bool v[N][M];
bool V[N][M];
int G[N][M],ans;

void solve(int x,int y){
	if (y == M){
		solve(x+1,0);
		return;
	}
	if (x == N){
		ans++;
		return;
	}
	if (v[x][y]){
		solve(x,y+1);
		return;
	}
	int l = G[x][y],r;
	if (y < M-1 && !v[x][y+1] && !V[G[x][y]][G[x][y+1]]){
		r = G[x][y+1];
		v[x][y] = v[x][y+1] = 1;
		V[l][r] = V[r][l] = 1;
		solve(x,y+1);
		v[x][y] = v[x][y+1] = 0;
		V[l][r] = V[r][l] = 0;
	}
	if (x < N-1 && !v[x+1][y] && !V[G[x][y]][G[x+1][y]]){
		r = G[x+1][y];
		v[x][y] = v[x+1][y] = 1;
		V[l][r] = V[r][l] = 1;
		solve(x,y+1);
		v[x][y] = v[x+1][y] = 0;
		V[l][r] = V[r][l] = 0;
	}
}

int main(){
	// read("in.txt");
	int t;
	take(t);
	while(t--){
		ans = 0;
		FOR(i,N)
			FOR(j,M)
				take(G[i][j]);
		memset(v,0,sizeof v);
		memset(V,0,sizeof V);
		solve(0,0);
		printf("%d\n",ans);
	}
}
