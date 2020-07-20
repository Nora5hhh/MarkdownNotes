//BFS求最短路径
//lc127
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int minPathLength(string beginWord,string endWord,vector<string>& graph)
{
    int min_path=1;
    vector<int> visit(graph.size(),0);
    queue<string> que;
    que.push(beginWord);
    while(!que.empty())
    {
        ++min_path;
        int n=que.size();
        for(int j=0;j<n;++j)
        {
            string curStr=que.front();
            que.pop();
            for (int i = 0; i < graph.size(); i++)
            {
                if(visit[i]==0)
                {
                    int diff=0;
                    for(int k=0;k<curStr.length();++k)
                    {
                        if(curStr[k]!=graph[i][k]) ++diff;
                    }
                    if(diff==1)
                    {
                        if(graph[i]==endWord) return min_path;
                        visit[i]=1;
                        que.push(graph[i]);
                    }
                }
            }
        } 
    }
    return min_path;
}

int main()
{
    vector<string> graph;
    string beginWord,endWord;
    cout<<"enter beginword and endword: ";
    cin>>beginWord>>endWord;
    cout<<endl<<"enter the array of graph: ";
    string x;
    for(int i=0;i<6;++i)
    {
        cin>>x;
        graph.push_back(x);
    }
    int min_path=minPathLength(beginWord,endWord,graph);
    cout<<endl<<min_path<<endl;
    return 0;
}