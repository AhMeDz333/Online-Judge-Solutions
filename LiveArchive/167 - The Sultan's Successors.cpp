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

int arr[8][8];
int R[8],ans;

bool place(int col, int row) {
    FOR(pos,col)
        if (R[pos] == row || (abs(R[pos] - row) == abs(pos - col)))
            return false;
    return true;
}
 
void solve(int col) {
    if (col == 8) {
        int sum = 0;
        FOR(i,8)
        	sum += arr[R[i]][i];
        ans = max(ans,sum);
    }
    else
        FOR(i,8)
            if (place(col, i)) {
                R[col] = i;
                solve(col + 1);
            }
    
}

int main(){
	//read("in.txt");
	int t;
	take(t);
	while(t--){
		ans = 0;
		FOR(i,8)
			FOR(j,8)
				take(arr[i][j]);
		solve(0);
		printf("%5d\n",ans);
	}
}
