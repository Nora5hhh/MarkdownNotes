//lc_51，N皇后问题
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValid(vector<string>& board,int row,int col) {
  //同列比较
  for(int i=row;i>=0;--i) {
    if(board[i][col]=='Q') return false;
  }
  //左上角
  for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j) {
    if(board[i][j]=='Q') return false;
  }
  //右上角
  for(int i=row-1,j=col+1;i>=0&&j<board.size();--i,++j) {
    if(board[i][j]=='Q') return false;
  }
  return true;
}

void placeQueens(vector<string>& board,int cur_row,vector<vector<string>>& res) {
  if(cur_row==board.size()) {
    res.push_back(board);
    return ;
  }
  for(int i=0;i<board.size();++i) {
    if(!isValid(board,cur_row,i)) continue;
    board[cur_row][i]='Q';
    placeQueens(board,cur_row+1,res);
    board[cur_row][i]='.';  
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> res;
  if(n==0) return res;
  vector<string> board(n,string(n,'.'));
  placeQueens(board,0,res);
  return res;
}

int main() {
  int n;
  cin>>n;
  vector<vector<string>> res=solveNQueens(n);
  for(int i=0;i<res.size();++i) {
    for(int j=0;j<res[0].size();++j) {
      cout<<res[i][j]<<endl;
    }
    cout<<endl;
  }
  return 0;
}