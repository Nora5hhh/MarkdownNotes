//lc_394,利用栈求其中的元素
#include<iostream>
#include<string>
#include<stack>

using namespace std;

string decodeString(string s) {
  string res;
  if(s.size()<3) return s;
  stack<int> nums;
  stack<string> sta;
  int len=s.size();
  int num=0;
  for(int i=0;i<s.size();++i){
    if(s[i]>='0'&&s[i]<='9'){
      num=num*10+s[i]-'0';
    }
    else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
      res+=s[i];
    }
    else if(s[i]=='['){
      nums.push(num);
      num=0;
      sta.push(res);
      res="";
    }
    else {
      int times=nums.top();
      nums.pop();
      for(int j=0;j<times;++j){
        sta.top()+=res;
      }
      res=sta.top();
      sta.pop();
    }
  }
  return res;
}

int main(){
  string s;
  cin>>s;
  string res=decodeString(s);
  cout<<res<<endl;
  return 0;
}