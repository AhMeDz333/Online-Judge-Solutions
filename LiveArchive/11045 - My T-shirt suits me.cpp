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
#define ll long long
#define LSB(x) (x & (-x))
#define N 100
#define vi vector <int>
#define iv pair <int,vi>
#define pss pair <string,string>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define left(x) (2*x)
#define right(x) (2*x+1)

int v[50],n,m;
pss vol[50];

int get(string s){
	if (s == "XXL") return 0;
	if (s == "XL") return 1;
	if (s == "L") return 2;
	if (s == "M") return 3;
	if (s == "S") return 4;
	if (s == "XS") return 5;
	return -1;
}

bool solve(int i){
	if (i == n) 
		return 1;
	string s = vol[i].first, st = vol[i].second;
	int id = get(s);
	if (v[id]){
		v[id]--;
		if (solve(i+1)) return true;
		v[id]++;
	}
	id = get(st);
	if (v[id]){
		v[id]--;
		if (solve(i+1)) return true;
		v[id]++;
	}
	return false;
}

int main(){
	//read("in.txt");
	int t;
	string s,st;
	cin >> t;
	while(t--){
		memset(v,0,sizeof v);
		cin >> m >> n;
		FOR(i,n){ 
			cin >> s >> st;
			vol[i] = pss(s,st);
		}
		FOR(i,10)
			v[i] = m/6;
		if (solve(0))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
