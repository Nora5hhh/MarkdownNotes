//lc_438，滑动窗口解决连续子串问题
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> findAnagrams(string s, string p) {
  vector<int> res;
  if(s.size()<p.size())
  {
    return res;
  }
  int l=0,r=-1;
  int plen=p.size(),slen=s.size();
  vector<int> window(26,0),need(26,0);
  for(int i=0;i<p.size();++i)
  {
    ++need[p[i]-'a'];
  }
  while(r+1<slen)
  {
    if(r+1<slen) ++window[s[++r]-'a'];
    if(r+1<plen) continue;
    if(window==need)
    {
      res.push_back(l);
    }
    --window[s[l++]-'a'];
  }
  return res;
}

int main()
{
  string s,p;
  cin>>s;
  cin>>p;
  vector<int> res=findAnagrams(s,p);
  for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
  return 0;
}