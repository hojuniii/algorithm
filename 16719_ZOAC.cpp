#include <iostream>
#include <string>
using namespace std;
#define INF 999

bool c[101];
string s;
void foo(int l, int r) {
	int mini = INF, idx = -1;
	for (int i = l; i < r + 1; i++) {
		if (!c[i] && mini > s[i]) {
			mini = s[i];
			idx = i;
		}
	}
	if (mini == INF) return;
	c[idx] = true;
	for (int i = 0; s[i]; i++) {
		if (c[i]) cout << s[i];
	}
	cout << '\n';
	foo(idx + 1, r);
	foo(l, idx - 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	foo(0, (int)s.size() - 1);
}