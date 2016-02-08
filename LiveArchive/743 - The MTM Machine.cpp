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
#define N 1030
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

string solve(string s){
	if (s[0] == '2'){
		if (s.length() == 1)
			return "-1";
		s.erase(s.begin());
		return s;
	}
	else if (s[0] == '3'){
		s.erase(s.begin());
		string tmp = solve(s);
		if (tmp == "-1")
			return "-1";
		else
			return tmp + "2" + tmp;
	}else{
		return "-1";
	}
}

int main(){
	//read("in.txt");
	string s;
	while(cin >> s && !(s.length() == 1 && s[0] == '0')){
		if (s.find("0") != string::npos)
			cout << "NOT ACCEPTABLE\n";
		else{
			string tmp = solve(s);
			if (tmp == "-1")
				cout << "NOT ACCEPTABLE\n";
			else
				cout << tmp << '\n';
		}
	}
}
