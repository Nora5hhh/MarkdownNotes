//lc_208，构建字典树
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Trie {
public:
  Trie() {
    isEnd=true;
    memset(next,0,sizeof(next));
  }

  void insert(string word) {
    Trie* node=this;
    for(char x:word) {
      if(node->next[x-'a']==NULL) {
        node->next[x-'a']=new Trie();
      }
      node=node->next[x-'a'];
    }
    node->isEnd=true;
  }

  bool startwith(string prefix) {
    Trie* node=this;
    for(char c:prefix) {
      node=node->next[c-'a'];
      if(node==NULL) return false;
    }
    return true;
  }

  bool search(string word) {
    Trie* node=this;
    for(char c:word) {
      node=node->next[c-'a'];
      if(node==NULL) return false;
    }
    return node->isEnd;
  }

private:
  bool isEnd;
  Trie* next[26];
};

int main() {
  Trie *trie=new Trie();
  trie->insert("apple");
  cout<<trie->search("apple")<<endl;;
  cout<<trie->search("app")<<endl;
  cout<<trie->startwith("app")<<endl;
  return 0;
}