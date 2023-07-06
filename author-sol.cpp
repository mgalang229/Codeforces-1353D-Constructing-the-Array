#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		int len_a = a.second - a.first + 1;
		int len_b = b.second - b.first + 1;
		if(len_a == len_b) {
			return a.first < b.first;
		}
		return len_a > len_b;
	}
};

void test_case(int& tc) {
	int n;
	cin >> n;
	set<pair<int, int>, cmp> segs;
	segs.insert(make_pair(0, n - 1));
	int ans[n];
	for(int i = 1; i <= n; i++) {
		pair<int, int> cur = *segs.begin();
		segs.erase(segs.begin());
		int mid = (cur.first + cur.second) / 2;
		ans[mid] = i;
		if(cur.first < mid) {
			segs.insert(make_pair(cur.first, mid - 1));
		}
		if(mid < cur.second) {
			segs.insert(make_pair(mid + 1, cur.second));
		}
	}
	for(int& x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for(int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
