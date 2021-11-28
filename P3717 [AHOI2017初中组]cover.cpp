#include <bits/stdc++.h>
using namespace std;
//#define _INPUT
const int N = 110;
int a[N][N];

class probe {
public:
	int m_x, m_y;
	static int m_r;
	void input() {
		cin >> m_x >> m_y;
	}
	bool lock(int x, int y) {
		double dis = sqrt(double((x - m_x) * (x - m_x)) + double((y - m_y) * (y - m_y)));
		return (dis <= m_r ? true : false);
	}
}p[N];
int probe::m_r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	#ifdef _INPUT
	freopen("input.txt", "r", stdin);
	#endif
	int n, m, r, ans = 0;
	cin >> n >> m >> probe::m_r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		p[i].input();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < m; k++) {
				if (p[k].lock(i, j)) {
					a[i][j] = 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!a[i][j]) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}