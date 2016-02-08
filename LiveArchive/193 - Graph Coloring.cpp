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
#define N 110
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

vi adj[N];
bool color[N];
vi v;
int n,ans;

bool valid(int node){
	int child;
	FOR(i,adj[node].size()){
		child = adj[node][i];
		if (color[child])
			return false;
	}
	return true;
}

void solve(int node){
	if (node == n){
		int c = 0;
		FOR(i,n)
			c += color[i];
		if (c > ans){
			v.clear();
			ans = c;
			FOR(i,n)
				if (color[i])
					v.push_back(i);
		}
		return;
	}
	color[node] = 0;
	solve(node+1);
	color[node] = 1;
	if (valid(node))
		solve(node+1);
	color[node] = 0;
}

int main(){
	// read("in.txt");
	int t,m,x,y;
	take(t);
	while(t--){
		ans = 0;
		take2(n,m);
		FOR(i,n)
			adj[i].clear();
		FOR(i,m){
			take2(x,y);
			x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		solve(0);
		printf("%d\n",ans);
		FOR(i,v.size())
			if (i)
				printf(" %d",v[i]+1);
			else
				printf("%d",v[i]+1);
		puts("");
	}	
}
