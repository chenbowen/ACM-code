#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <cmath>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef pair<int, int> PII;
typedef set<int> SI;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define bitcount                    __builtin_popcount
#define gcd                         __gcd
#define F(i,n)                      for(int i=0;i<(n);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define db(a)                       cout<<(a)<<endl
#define whatis(a)                   cout<<#a<<" is "<<a<<endl
#define bug                         printf("here!!!\n")
#define fi                          first
#define se                          second
#define pb                          push_back
#define sz(a)                       ((int)(a.size()))
#define s(n)                        scanf("%d",&(n))
#define sc(n)                       scanf("%c",&(n))
#define sf(n)                       scanf("%lf",&(n))
#define ss(n)                       scanf("%s",(n))
#ifdef LOCAL
#define LLD                         "%lld"
#else
#define LLD                         "%I64d"
#endif
#define sl(n)                       scanf(LLD,&(n))
const int N = 16;
int m, n, minn;
bool f[N][N], t[N][N];
string s, ans, ts;
int dx[] = {0, 0, -1, 0, 1}, dy[] = {0, 1, 0, -1, 0};
void flip(int a, int b) {
	F(i, 5) {
		int x = dx[i]+a, y = dy[i]+b;
		if (x >= 0 && x < m && y >= 0 && y < n) f[x][y] = !f[x][y];
	}
	s[a*n+b] = (s[a*n+b] == '1') ? '0' : '1';
}
void dfs(int d) {
	if (d == n) {
		ts = s;
		F(i, m) F(j, n) t[i][j] = f[i][j];
		bool succ = true;
		for(int i = 1; i < m; i++) F(j, n)
			if (f[i-1][j])
				flip(i, j);
		F(i, n) if (f[m-1][i]) succ = false;
		if (succ) {
			int cnt = 0;
			F(i, m*n) if (s[i] == '1') cnt++;
			if (cnt < minn) {
				ans = s;
				minn = cnt;
			}
			else if (cnt == minn) ans = min(ans, s);
		}
		F(i, m) F(j, n) f[i][j] = t[i][j];
		s = ts;
		return;
	}
	dfs(d+1);
	flip(0, d);
	dfs(d+1);
	flip(0, d);
}

int main() { _
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    s(m), s(n);
    minn = INF;
    F(i, m) F(j, n) s(f[i][j]), s.pb('0'), ans.pb('1');
    dfs(0);
    if (minn == INF) printf("IMPOSSIBLE");
    else {
    	F(i, m) {
    		printf("%c", ans[i*n]);
    		for(int j = 1; j < n; j++) printf(" %c", ans[i*n+j]);
    		printf("\n");
    	}
    }
    return 0;
}
