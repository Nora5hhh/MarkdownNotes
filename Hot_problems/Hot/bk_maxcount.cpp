//bk_4，动态规划，最多几个牛牛工作
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//动态规划，设dp[i][0]和dp[i][1]，即加上当前和不加当前时最多几个
int getMaxCount(vector<vector<int>>& num) {
	sort(num.begin(), num.end());
	int len = num.size();
	vector<vector<int>> dp(num.size(), vector<int>(2, 0));
	dp[0][0] = 0;
	dp[0][1] = 1;
	//for循环判断是否要加上当前状态
	//分两种情况，和前一个有重合和前一个没有重合
	for (int i = 1; i < len; ++i) {
		for (int j = i-1; j > -1; --j) {
			if (num[i][0] - num[i][1] - num[j][0] - num[j][1] > 0) {
				dp[i][1] = max(dp[j][1], dp[j][0]) + 1;
				dp[i][0] = max(dp[j][0], dp[j][1]);
				continue;
			}
			else {
				dp[i][1] = dp[j][0] + 1;
				dp[i][0] = dp[j][0];
			}
		}
		//只管当前范围是否和dp的包括的前一个的范围重合
	}
	return max(dp[len-1][0], dp[len-1][1]);
}

int main() {
	/*char *p[10];
	char(*p1)[10];
	cout << sizeof(p) << endl;
	cout << sizeof(p1) << endl;
	return 0;*/
	int n;
	cin >> n;
	vector<vector<int>> num;
	for (int i = 0; i < n; ++i) {
		vector<int> el;
		for (int j = 0; j < 2; ++j) {
			int x;
			cin >> x;
			el.push_back(x);
		}
		num.push_back(el);
	}
	int res = getMaxCount(num);
	cout << res << endl;
	return 0;
}