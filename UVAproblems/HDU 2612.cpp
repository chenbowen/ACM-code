// #define               LOCAL   
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
#define FOR(i,x,y)                  for(int i=(x);i<=(y);++i)
#define FD(i,n)                     for(int i=(n-1);i>=0;--i)
#define FORD(i,y,x)                 for(int i=(y);i>=(x);--i)
#define MEM(x,i)                    memset(x,i,sizeof(x))
#define mp                          make_pair
#define db(a)                       cout<<(a)<<endl
#define whatis(a)                   cout<<#a<<" is "<<a<<endl
#define bug                         printf("\nhere!!!\n")
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
const int N = 202;
int r, c, d[2][N][N];
char s[N][N];

struct Node{
	int x, y, d;
};
Node nodey, nodem;

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

void bfs(Node startnode, int dis[N][N]) {
	queue<Node> q;
	q.push(startnode);
	dis[startnode.x][startnode.y] = startnode.d;
	while(!q.empty()) {
		Node u = q.front(); q.pop();
		F(i, 4) {
			int nx = u.x+dx[i], ny = u.y+dy[i];
			if (nx>=0&&ny>=0&&nx<r&&ny<c&&dis[nx][ny]==-1&&s[nx][ny]!='#'){
				dis[nx][ny] = u.d+1;
				q.push((Node){nx, ny, u.d+1});
			}
		}
	}
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
	while (scanf("%d%d", &r, &c) == 2) {
		F(i, r) {
			ss(s[i]);
			F(j, c) {
				if (s[i][j] == 'Y') {
					nodey = (Node) {i, j, 0};
					s[i][j] = '.';
				}
				else if (s[i][j] == 'M') {
					nodem = (Node) {i, j, 0};
					s[i][j] = '.';
				}
			}
		}
		MEM(d, -1);
		bfs(nodey, d[0]);
		bfs(nodem, d[1]);
		int ans = INF;
		F(i, r) F(j, c) {
			if (s[i][j] == '@' && d[0][i][j] != -1 && d[1][i][j] != -1) 
				ans = min(ans, d[0][i][j] + d[1][i][j]);
		}
		printf("%d\n", ans*11);
	}
	return 0;
}
