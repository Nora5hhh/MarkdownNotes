//lc_347，使用自定义sort的比较函数来排序哈希表
#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
	vector<int> res;
	if (nums.size() < k) return res;
	//哈希表统计个数，然后返回个数最多的那几个
	unordered_map<int, int> mmap;
	for (int i = 0; i < nums.size(); ++i) {
		++mmap[nums[i]];
	}
	vector<pair<int, int>> mvec(mmap.begin(), mmap.end());
	//按第二个从大到小排序
	//sort只能对线性容器排序
	sort(mvec.begin(), mvec.end(), cmp);
	auto iter = mvec.begin();
	for (int i = 0; i < k; ++i) {
		res.push_back(iter->first);
		++iter;
	}
	return res;
}

int main() {
	vector<int> nums = { 1,1,1,2,3,2 };
	int k = 2;
	vector<int> res = topKFrequent(nums, k);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	return 0;
}