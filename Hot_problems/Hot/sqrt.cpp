//lc_61，求一个数的平方根
#include<iostream>
using namespace std;

//二分迭代法
int mySqrt(int x) {
  if(x==0||x==1) return x;
  int l=0,r=x;
  int mid,ans=0;
  while(l<=r) {
    mid=(r+l)/2;
    if((long long)mid*mid<=x) {
      l=mid+1;
      ans=mid;
    }
    else
      r=mid-1;
  }
  return ans;
}

int main() {
  int x;
  cin>>x;
  int res=mySqrt(x);
  cout<<x<<endl;
  return 0;
}