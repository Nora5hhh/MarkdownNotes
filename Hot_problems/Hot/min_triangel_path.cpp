//lc_120，三角形最小路径和
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
  if(!triangle.size()) return 0;
  if(triangle.size() == 1) return triangle[0][0];
  int row = triangle.size();
  int col = triangle[row-1].size();
  vector<vector<int>> dp(row,vector<int>(col,0));
  //初始化,从下到上更简单
  for(int i = 0; i < col; ++i) {
    dp[row-1][i] = triangle[row-1][i];
  }
  for(int i = row-2; i > -1; --i) {
    for(int j = 0; j < triangle[i].size(); ++j) {
      dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
    }
  }
  return dp[0][0];
}

int main() {
  vector<vector<int>> triangle;
  int n;
  cin>>n;
  int tmp = 0;
  for(int i = 0; i < n; ++i) {
    int j = ++tmp;
    vector<int> temp;
    for(int k = 0; k < j; ++k) {
      int x;
      cin>>x;
      temp.push_back(x);
    }
    triangle.push_back(temp);
  }
  int res = minimumTotal(triangle);
  cout<<"the result is: "<<res<<endl;
  return 0;
}