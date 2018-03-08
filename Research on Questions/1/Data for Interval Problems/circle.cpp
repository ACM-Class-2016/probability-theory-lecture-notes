#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n = 3, link[111], vis[111], total, valid;

struct Interval {
	int a, b;
} a[111], b[111];

inline bool inter(const Interval &p, const Interval &q) {
	if (p.a > p.b && q.a > q.b) {
		return 1;
	}
	if (p.a > p.b) {
		return inter(q, p);
	}
	if (q.a > q.b) {
		return p.b > q.a || p.a < q.b;
	}
	return !(p.b < q.a || p.a > q.b);
}

inline void check() {
	int now = 0;
	for (int i = 1; i <= n; ++i) {
		bool flag = true;
		for (int j = 1; j <= n; ++j) {
			if (!inter(a[i], a[j])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			now = 1;
			break;
		}
	}
	++total;
	valid += now;
//	cout << a[1].a << " " << a[1].b << " " << a[2].a << " " << a[2].b << " " << now << endl;
}

inline void dfs2(int dep) {
	if (dep > n) {
		check();
	} else {
		dfs2(dep + 1);
		swap(a[dep].a, a[dep].b);
		dfs2(dep + 1);
		swap(a[dep].a, a[dep].b);
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
	for (n = 2; n <= 10; ++n) {
		valid = total = 0;
		dfs1(1);
		int g = __gcd(valid, total);
		cout << n << " " << valid << " " << total << " " << valid / g << " " << total / g << " " << 1.0 * valid / total << endl;
	}
} 
