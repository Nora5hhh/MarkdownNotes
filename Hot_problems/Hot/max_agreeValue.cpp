//大疆笔试第二题，输出最大满意值
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmpp(const vector<int> &a, const vector<int> &b) {
	return (a[1] / a[0]) < (b[1] / b[0]);
}

void dfs(vector<vector<int>>& arr, int cur, int start, int &agree) {
	if (start < 0||cur<arr[0][0]) return;
	int i = (cur / arr[start][0]) > arr[start][2] ? arr[start][2] : (cur / arr[start][0]);
	agree = agree + i * arr[start][1];
	int ccur = cur - i * arr[start][0];
	dfs(arr, ccur, start - 1, agree);
}

int main() {
	vector<vector<int>> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		vector<int> x;
		for (int j = 0; j < 3; ++j) {
			int el;
			cin >> el;
			x.push_back(el);
		}
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end(), cmpp);
	int agree = 0;
	dfs(arr, 100, 2, agree);
	cout << agree << endl;
	return 0;
}


