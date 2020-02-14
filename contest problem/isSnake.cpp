#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;

typedef long long ll;
const int INF = 1e9;

string s[2];
int n;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, set<pii>& visited) {
    int sz = 1;
    visited.insert(mp(x, y));
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 2 && ny >= 0 && ny <= n-1 && s[nx][ny] == '#') {
            if (visited.find(mp(nx, ny)) == visited.end()) {
                sz += dfs(nx, ny, visited);
            }
        }
    }
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; ++i) {
            cin >> s[i];
        }
        int xs, ys;
        int cnt = 0;
        for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < n; ++y) {
                if (s[x][y] == '#') {
                    xs = x;
                    ys = y;
                    ++cnt;
                }
            }
        }
        set<pii> visited;
        int sz = dfs(xs, ys, visited);
        if (sz == cnt) {
            vector<int> single_cell_cols;
            for (int i = 0; i < n; ++i) {
                int cnt_black = 0;
                for (int j = 0; j < 2; ++j) {
                    if (s[j][i] == '#') cnt_black++;
                }
                if (cnt_black == 1) {
                    single_cell_cols.pb(i);
                }
            }
            bool fail = 0;
            for (int i = 0; i < SZ(single_cell_cols)-1; ++i) {
                int cl = single_cell_cols[i];
                int cr = single_cell_cols[i+1];
                if (s[0][cl] == s[0][cr]) {
                    if ((cr - cl-1) % 2 == 1) {
                        fail = 1;
                    }
                } else {
                    if ((cr - cl-1) % 2 == 0) {
                        fail = 1;
                    }
                }
            }
            cout << (!fail ? "yes" : "no") << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
