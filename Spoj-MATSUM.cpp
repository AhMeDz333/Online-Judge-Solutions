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
#define N 1030
#define vi vector <int>
#define iv pair <int,vi>
#define vll vector <ll>
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define read(s) freopen(s,"r",stdin)
#define left(x) (2*x)
#define right(x) (2*x+1)

int n;

class BIT{
private:
	int tree[N][N];
public:
	BIT(){
		memset(tree,0,sizeof tree);
	}
	int query(int x1,int y1,int x2,int y2){
		return query(x2,y2) - query(x2,y1-1) - query(x1-1,y2) + query(x1-1,y1-1);
	}
	int query(int x,int y){
		int sum = 0;
		while(x > 0){
			sum += queryy(x,y);
			x -= LSB(x);
		}
		return sum;
	}
	int queryy(int x,int y){
		int sum = 0;
		while(y > 0){
			sum += tree[x][y];
			y -= LSB(y);
		}
		return sum;
	}
	void update(int x,int y,int v){
		while(x <= n){
			updatey(x,y,v);
			x += LSB(x);
		}
	}
	void updatey(int x,int y,int v){
		while(y <= n){
			tree[x][y] += v;
			y += LSB(y);
		}
	}
};

int a[N][N];

int main(){
	//read("in.txt");
	int t,x,y,x1,y1,v;
	char s[10];
	take(t);
	while(t--){
		take(n);
		memset(a,0,sizeof a);
		BIT bit;
		while(takes(s) && s[0] != 'E'){
			if (s[1] == 'E'){
				take3(x,y,v);
				x++, y++;
				bit.update(x,y,v-a[x][y]);
				a[x][y] = v;
			}else{
				take2(x,y);
				take2(x1,y1);
				x++, x1++, y++, y1++;
				printf("%d\n",bit.query(x,y,x1,y1));
			}
		}		
	}	
}
