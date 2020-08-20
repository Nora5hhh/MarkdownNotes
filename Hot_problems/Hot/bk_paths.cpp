//bk_3,dfs
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//bk_3，dfs求能走的路径数
//格子全部初始化为1，表示能走,count为全局变量
void dfs(vector<vector<int>>& num, int cur_i, int cur_j, int &count, int row, int col) {
	if (cur_i == row && cur_j == col) {
		++count;
		return;
	}
	num[cur_i][cur_j] = 0;
	//i+1向下
	if (cur_i < row && num[cur_i + 1][cur_j] != 0) dfs(num, cur_i + 1, cur_j, count, row, col);
	//j-1向左
	if (cur_j > 0 && num[cur_i][cur_j - 1] != 0)  dfs(num, cur_i, cur_j - 1, count, row, col);
	//j+1向右
	if (cur_j < col && num[cur_i][cur_j + 1] != 0) dfs(num, cur_i, cur_j + 1, count, row, col);
	num[cur_i][cur_j] = 1;
}

int dp(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, 0));
	dp[0][0] = 1;
	//边界条件
	for (int i = 1; i < m; ++i) {
		dp[i][0] = dp[i - 1][0];
	}
	for (int i = 1; i < n; ++i) {
		dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	return dp[m - 1][n - 1];
}

int main() {
	int t;                //几组数据
	cin >> t;
	vector<vector<int>> elem;
	for (int i = 0; i < t; ++i) {
		vector<int> el;
		for (int j = 0; j < 2; ++j) {
			int x;
			cin >> x;
			el.push_back(x);
		}
		elem.push_back(el);
	}
	for (int i = 0; i < t; ++i) {
		vector<vector<int>> num(elem[i][0], vector<int>(elem[i][1], 1));
		int count = 0;
		//count = dp(elem[i][0], elem[i][1]);
		dfs(num, 0, 0, count, elem[i][0] - 1, elem[i][1] - 1);
		cout << count << endl;
	}
	return 0;
}
