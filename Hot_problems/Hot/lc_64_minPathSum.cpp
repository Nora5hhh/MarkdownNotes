//lc_64,找左上角到右下角的最小路径和，动态规划
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
	if (grid.size() < 1) return 0;
	int len = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(len, vector<int>(n, 0));
	//边界条件初始化
	dp[0][0] = grid[0][0];
	for (int i = 1; i < len; ++i) {
		dp[i][0] = dp[i - 1][0] + grid[i][0];
	}
	for (int i = 1; i < n; ++i) {
		dp[0][i] = dp[0][i - 1] + grid[0][i];
	}
	for (int i = 1; i < len; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
		}
	}
	return dp[len - 1][n - 1];
}

int main() {
	vector<vector<int>> grid;
	for (int i = 0; i < 3; ++i) {
		vector<int> tmp;
		for (int j = 0; j < 3; ++j) {
			int x;
			cin >> x;
			tmp.push_back(x);
		}
		grid.push_back(tmp);
	}
	int res = minPathSum(grid);
	cout << res << endl;
	return 0;
}