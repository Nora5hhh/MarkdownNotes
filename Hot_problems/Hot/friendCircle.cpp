//lc_547，朋友圈，并查集找有几个圈
#include<iostream>
#include<vector>
using namespace std;

int ffind(int a,vector<int> &parents) {
	if (parents[a] == -1) {
		return a;
	}
	return ffind(parents[a], parents);
}

//union，将两个集合进行合并
void funion(int a, int b,vector<int> &parents) {
	int par_a = ffind(a,parents);
	int par_b = ffind(b,parents);
	if (par_a != par_b) {
		parents[par_a] = par_b;
	}
}

int findCircleNum(vector<vector<int>> &M) {
	if (M.size() < 1) return 0;
	int len = M.size();
	int res = 0;
	vector<int> parents(len, -1);
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (M[i][j] == 1 && i != j) {
				funion(i, j, parents);
			}
		}
	}
	for (int i = 0; i < len; ++i) {
		if (parents[i] == -1) {
			++res;
		}
	}
	return res;
}

int main() {
	vector<vector<int>> M;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> el;
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			el.push_back(x);
		}
		M.push_back(el);
	}
	int res = findCircleNum(M);
	cout << res << endl;
	return 0;
}