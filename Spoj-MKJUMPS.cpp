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
#define N 10
#define INF INT_MAX
#define vi vector <int>
#define vs vector<string>
#define iv pair <int,vi>
#define pss pair <string,string>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define left(x) (2*x)
#define right(x) (2*x+1)
#define gc getchar_unlocked

int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1},ans;
bool G[N][N];
bool v[N][N];

bool valid(int x,int y){
	return x < N && y < N && x >= 0 && y >= 0 && !v[x][y] && G[x][y];
}

int sum(){
	int c = 0;
	FOR(i,N)
		FOR(j,N)
			if (G[i][j] && !v[i][j])
				c++;
	return c;
}

void DFS(int x,int y){
	v[x][y] = 1;
	FOR(i,8){
		int px = x+dx[i], py = y+dy[i];
		if (valid(px,py)){
			DFS(px,py);
			ans = min(ans,sum());
			v[px][py] = 0;
		}
	}
}

int main(){
	//read("in.txt");
	int n,x,y,id,e = 1,l;
	while(take(n) && n){
		ans = INF;
		memset(v,0,sizeof v);
		memset(G,0,sizeof G);
		FOR(i,n){
			take2(x,y);
			l = 0;
			FOR(j,x)
				G[i][l++] = 0;
			if (i == 0)
				id = l;
			FOR(j,y)
				G[i][l++] = 1;
		}
		DFS(0,id);
		if (ans == 1)
			printf("Case %d, %d square can not be reached.\n",e++,ans);
		else
			printf("Case %d, %d squares can not be reached.\n",e++,ans);
	}
}
