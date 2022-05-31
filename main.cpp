#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#define int long long
using namespace std;
const int INF = 1e9;



bool dfs_kuhn(vector<vector<int>>& g, int now, vector<int> &mt, vector<bool>used){
	if (used[now]) return false;
	used[now] = true;
	for (auto to: g[now]){
		if (mt[to] == -1 || dfs_kuhn(g, mt[to], mt, used)){
			mt[to] = now;
			return true;
		}
	}
	return false;
}



signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	n /= 2;
	vector<vector<int>> g(2*n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		v -= n;
		u--, v--;
		v += n;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> mt(2*n, -1);
	int ans = 0;

	for(int i = 0; i < n; i++) {
		vector<bool>used(n, false);
		if (dfs_kuhn(g, i, mt, used)) ans++;
	}
	// cout << ans << endl;
	for (int i = n; i < n*2; i++){
		if (mt[i] != -1) {
			cout << mt[i]+1 << " " <<  i+1-n + n<< endl;
		}
	}
	

}