//lc_49,写一个函数判断两个单词是否是异位词，然后for循环比较
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

//返回每个字串的排序后元素
string getSort(string a) {
	sort(a.begin(), a.end());
	return a;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> res;
	unordered_map<string, vector<string>> mymap;
	if (strs.size() < 1) return res;
	//将每个元素按相同异位词插入
	for (int i = 0; i < strs.size(); ++i) {
		string s = getSort(strs[i]);
		mymap[s].push_back(strs[i]);
	}
	auto iter = mymap.begin();
	while (iter != mymap.end()) {
		res.push_back(iter->second);
		++iter;
	}
	return res;
}

int main() {
	vector<string> strs;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		cin.ignore(1024, '\n');
		strs.push_back(s);
	}
	vector<vector<string>> res = groupAnagrams(strs);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}