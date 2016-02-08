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
#define N 8
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

int R[N],a[N],ans,e = 1;

bool place(int col, int row) {
    FOR(pos,col)
        if (R[pos] == row || (abs(R[pos] - row) == abs(pos - col)))
            return false;
    return true;
}

int dif(){
	int c = 0;
	FOR(i,N)
		c += (a[i] != R[i]);
	return c;
}

void solve(int col) {
    if (col == N) {
        ans = min(ans,dif());
        return;
    }
    FOR(i,N)
        if (place(col, i)) {
            R[col] = i;
            solve(col + 1);
        }
}

int main(){
	// read("in.txt");
	while(take(a[0]) == 1){
		ans = INF;
		FOR(i,N-1)
			take(a[i+1]);
		FOR(i,N) a[i]--;
		solve(0);
		printf("Case %d: %d\n",e++,ans);
	}
}
