#include <iostream>
#include <cmath>

using namespace std;

int n;
long double f[111][111];

int main() {
double last = 1;
for (n = 1; n <= 20; ++n) {
	f[1][1] = (1LL << n) - 1;
	f[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		f[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			f[i][j] = f[i - 1][j - 1] * ((1LL << n) - (1LL << j - 1)) +
						f[i - 1][j] * (1LL << j);
		}
	}
	
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		//cout << i << " " << f[n][i] << endl;
		double tmp = f[n][i];
		for (int t = 0; t < i; ++t, tmp /= 2);
		double t = 1;
		for (int i = 0; i < n * n; ++i) t *= 2;
		t -= 1;
		ans = ans + tmp / t;
	}
	double t = 1;
	ans /= t;
	cout << n << " " << ans << " " << ans / last << endl;
	last = ans;
}
}
