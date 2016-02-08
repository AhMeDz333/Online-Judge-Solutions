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
#define N 100010
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

int T,n,a[N];

int Try(int mask){
	int sum = 0;
	FOR(i,n)
		if (mask & (1 << i)){
			sum += a[i];
			if (sum > T)
				return -1;
		}
	return sum;
}

int main(){
	// read("in.txt");
	while(take(T) == 1){
		take(n);
		FOR(i,n)
			take(a[i]);
		int ans = 0,d = INF,tmp,sum;
		FOR(i,(1 << n)){
			tmp = Try(i);
			if (tmp != -1 && T-tmp < d){
				ans = i;
				d = T-tmp;
				sum = tmp;
			}
		}
		FOR(i,n)
			if (ans & (1 << i))
				printf("%d ",a[i]);
		printf("sum:%d\n",sum);
	}
}
