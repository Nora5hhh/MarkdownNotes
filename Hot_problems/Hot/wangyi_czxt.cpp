//网易操作系统的题，2020/9/27晚笔试第二题
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;

vector<string> getfd(vector<string>& s)
{
	vector<string> res;
	bool vis[1000001] = { false };
	unordered_map<string, string> mymap;
	for (int i = 0; i < s.size(); ++i)
	{
		string str = s[i];
		vector<string> cur;                   //将操作函数与文件描述符等分开存储
		while (!str.empty())                  //先按照空格把操作函数与文件名或fd提取出来
		{
			if (str.find(" ") == string::npos)
			{
				cur.push_back(str);
				break;
			}
			string str_tmp = str.substr(0, str.find(" "));
			cur.push_back(str_tmp);
			str.erase(0, str.find(" ") + 1);
		}
		int pos = 0;
		//此时cur[0]即为操作函数
		if (cur.size() == 0) continue;
		if (cur[0] == "open")           //为open函数时
		{
			for (int j = 0; j < 1000001; ++j)
			{
				if (vis[j] == false)
				{
					pos = j;
					break;
				}
			}
			mymap[to_string(pos)] = cur[1];
			vis[pos] = true;
			res.push_back(to_string(pos));
		}
		else if (cur[0] == "dup")
		{
			for (int j = 0; j < 1000001; ++j)
			{
				if (vis[j] == false)
				{
					pos = j;
					break;
				}
			}
			//auto c = find(vis, vis + 1000001, false);       //找到第一个空位放进去
			//int pos = *c;
			mymap[to_string(pos)] = mymap[cur[1]];          //将cur[1]指向的文件用一个新的fd指向
			vis[pos] = true;
			res.push_back(to_string(pos));
		}
		else if (cur[0] == "dup2")
		{
			mymap[cur[2]] = mymap[cur[1]];            //cur[1]和cur[2]都指向一个文件
			vis[atoi(cur[2].c_str())] = true;
		}
		else if (cur[0] == "close")
		{
			vis[atoi(cur[1].c_str())] = false;
			mymap[cur[1]] = "";
		}
		else if (cur[0] == "query")
		{
			string qstr = "";
			//query,查找fd对应的文件名
			if (mymap.count(cur[1]) > 0)
			{
				qstr = mymap[cur[1]];
			}
			if (qstr != "")
			{
				res.push_back(qstr);
			}
		}
		else
			continue;
	}
	return res;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int cnt;
		cin >> cnt;
		//vector<string> s = {"open libc.so","open libm.so" ,"open libdl.so" ,"dup 2","dup2 0 2","close 0","query 0","query 1","query 2","query 3","open log.txt"};
		vector<string> s;
		/*cin.clear();
		cin.ignore();*/
		for (int j = 0; j <= cnt; ++j)
		{
			string tmp;
			getline(cin, tmp);
			s.push_back(tmp);
		}
		vector<string> res = getfd(s);
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << endl;
		}
	}
	return 0;
}