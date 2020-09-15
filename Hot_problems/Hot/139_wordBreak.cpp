//lc_139，使用动态规划判断字符串s中是否能被分割成worddcit中的单词
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

//dp[i]=dp[j]&&check(j~i)，其中check(j~i)表示j到i的字符串是否在s中
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> wordSet;
	for (auto word : wordDict) {
		wordSet.insert(word);
	}
	vector<bool> dp(s.size() + 1);
	dp[0] = true;
	for (int i = 1; i <= s.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
				dp[i] = true;
				break;                    //break退出当前循环，即j循环
			}
		}
	}
	return dp[s.size()];
}

int main() {
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
	bool res = wordBreak(s, wordDict);
	cout << res << endl;
	return 0;
}