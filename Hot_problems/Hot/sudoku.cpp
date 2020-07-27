#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isValidSudoke(vector<vector<char>>& board) {
  int row[10][10]={0};
  int col[10][10]={0};
  int box[10][10]={0};
  for(int i=0;i<board.size();++i) {
    for(int j=0;j<board[0].size();++j) {
      if(board[i][j]=='.') continue;
      int tmp=board[i][j]-'0';
      if(row[i][tmp]) return false;
      if(col[j][tmp]) return false;
      if(box[j/3+(i/3)*3][tmp]) return false;
      row[i][tmp]=1;
      col[j][tmp]=1;
      box[j/3+(i/3)*3][tmp]=1;
    }
  }
  return true;
}

int main() {
  vector<vector<char>> board;
  char x;
  for(int i=0;i<9;++i) {
    vector<char> tmp;
    for(int j=0;j<9;++j) {
      cin>>x;
      tmp.push_back(x);
    }
    board.push_back(tmp);
  }
  bool res=isValidSudoke(board);
  cout<<res<<endl;
  return 0;
}