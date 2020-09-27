//0-1背包问题变种，使用动态规划解决
#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>& nums){
  if(nums.size()<2) return false;
  int sum=0;
  for(int i=0;i<nums.size();++i)
  {
    sum+=nums[i];
  }
  if(sum%2) return false;
  int target=sum/2;
  vector<bool> dp(target+1,false);
  dp[0]=true;
  for(int i=0;i<nums.size();++i)
  {
    for(int j=target;j>=0;--j)
    {
      if(j-nums[i]>=0)
      {
        dp[j]=dp[j]||dp[j-nums[i]];
      }
    }
  }
  return dp[target];
}

int main()
{
  vector<int> nums;
  int n;
  cin>>n;
  for(int i=0;i<n;++i)
  {
    int x;
    cin>>x;
    nums.push_back(x);
  }
  bool res=canPartition(nums);
  cout<<res<<endl;
  return 0;
}