#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n = 4, link[111], vis[111], total, valid;

struct Interval {
	int a, b;
} a[111], b[111];

inline bool inter(const Interval &p, const Interval &q) {
	return !(p.b < q.a || p.a > q.b);
}

inline void check() {
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j) {
			if (!inter(a[i], a[j]) || !inter(b[i], b[j])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			++valid;
			break;
		}
	}
	++total;
}

inline void dfs2(int dep) {
	if (dep > n) {
		check();
	} else {
		for (int i = 1; i <= n * 2; ++i) {
			if (vis[i]) {
				continue;
			}
			for (int j = i + 1; j <= n * 2; ++j) {
				if (vis[j]) {
					continue;
				}
				b[dep] = {i, j};
				vis[i] = vis[j] = 1;
				dfs2(dep + 1);
				vis[i] = vis[j] = 0;
			}
		}
	}
}

inline void dfs1(int dep) {
	if (dep > n * 2) {
		int idx = 0;
		for (int i = 1; i <= n * 2; ++i) {
			if (link[i] > i) {
				a[++idx] = {i, link[i]};
			}
		}
		dfs2(1);
	} else {
		if (link[dep]) {
			dfs1(dep + 1);
		} else {
			for (int i = dep + 1; i <= 2 * n; ++i) {
				if (!link[i]) {
					link[i] = dep;
					link[dep] = i;
					dfs1(dep + 1);
					link[i] = link[dep] = 0;
				}
			}
		}
	}
}

int main() {
	n = 5;
	valid = total = 0;
	dfs1(1);
	int g = __gcd(valid, total);
	cout << n << " " << valid << " " << total << " " << valid / g << " " << total / g << endl;
	cout << 1.0 * valid / total << endl;
} 
