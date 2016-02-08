#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (int)(n); i++)
#define RFOR(i,x,n) for (int i = (x); i <= (int)(n); i++)
#define ii pair <int,int>
#define iii pair <ii,int>
#define is pair <int,string>
#define pdd pair <double,double>
#define ll unsigned long long
#define LSB(x) (x & (-x))
#define N 110
#define INF (1 << 30)
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

int n,m,a,b,cnt;
bool vis[N][N];
ii parent[N][N];
char G[N][N];
queue <ii> q;

bool valid(int x,int y){
	return x < n && y < m && x >= 0 && y >= 0 && G[x][y] != 'X';
}

void BFS(){
	while(!q.empty()){
		ii p = q.front(); q.pop();
		int x = p.first, y = p.second;
		if (x == a && y == b)
			return;
		RFOR(dx,-1,1)
			RFOR(dy,-1,1)
				if (abs(dx) != abs(dy))
					if (valid(x+dx,y+dy) && !vis[x+dx][y+dy]){
						q.push(ii(x+dx,y+dy));
						vis[x+dx][y+dy] = true;
						parent[x+dx][y+dy] = ii(x,y);
					}
	}
}

bool count(int x,int y){
	int c = 0;
	RFOR(dx,-1,1)
		RFOR(dy,-1,1)
			if (abs(dx) != abs(dy) && parent[x][y] != ii(x+dx,y+dy))
				if (valid(x+dx,y+dy))
					c++;
	return c >= 2;
}

void backtrack(int x,int y){
	if (x + y == -2)
		return;
	cnt += count(x,y);
	ii p = parent[x][y];
	backtrack(p.first,p.second);
}

int main(){
	int t,k;
	scanf("%d",&t);
	while(t--){
		while(!q.empty()) q.pop();
		a = b = 0;
		memset(vis,0,sizeof vis);
		FOR(i,N)
			FOR(j,N)
				parent[i][j] = ii(0,0);
		scanf("%d%d",&n,&m);
		FOR(i,n)
			scanf("%s",G[i]);
		scanf("%d",&k);
		FOR(i,n)
			FOR(j,m)
				if (G[i][j] == 'M'){
					q.push(ii(i,j));
					vis[i][j] = 1;
					parent[i][j] = ii(-1,-1);
				}else if (G[i][j] == '*')
					a = i, b = j;
		BFS();
		cnt = 0;
		ii p =parent[a][b];
		backtrack(p.first,p.second);
		printf(k == cnt? "Impressed\n" : "Oops!\n");
	}
}
