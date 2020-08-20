//lc_547,DFS或者并查集求朋友圈个数
#include<iostream>
#include<vector>
using namespace std;

//仔细看这块的i和j
void DFS(vector<int> &visit, vector<vector<int>>& M, int i) {
	for (int j = 0; j < M.size(); ++j) {
		if (M[i][j] == 1 && visit[j] == 0) {
			visit[j] = 1;
			DFS(visit, M, j);
		}
	}
}

int findCircleNum(vector<vector<int>>& M) {
	if (M.size() < 1) return 0;
	int len = M.size();
	int res = 0;
	vector<int> visit(len, 0);
	for (int i = 0; i < len; ++i) {
		if (visit[i] == 0) {
			DFS(visit, M, i);
			++res;
		}
	}
	return res;
}

int main() {
	vector<vector<int>> M;
	for (int i = 0; i < 3; ++i) {
		vector<int> el;
		for (int j = 0; j < 3; ++j) {
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