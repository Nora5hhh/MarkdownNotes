#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

const int value = 1000000007;

int getNums(vector<int> &nums) {
	if (nums.size() <= 1) return nums.size();
	unordered_map<int, int> mymap;
	uint64_t count = 1;
	for (int i = 0; i < nums.size(); ++i) {
		++mymap[nums[i]];
	}
	auto iter = mymap.begin();
	auto prev = iter;
	++iter;
	while (iter != mymap.end()) {
		long tmp = 1;
		for (int i = 2 * prev->second; i > iter->second; --i) {
			tmp *= i;
		}
		long mod = 1;
		for (int i = 1; i <= 2 * prev->second - iter->second; ++i) {
			mod *= i;
		}
		count = count % value;
		count *= tmp / mod;
		prev = iter;
		++iter;
	}
	return count % value;
}

int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int res = getNums(nums);
	cout << res << endl;
	return 0;
}