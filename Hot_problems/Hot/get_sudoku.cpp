//lc_35，根据给出的数独题解答
//DFS加回溯
#include<vector>
#include<iostream>
#include<string>

using namespace std;

	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i < 9; ++i) {
			if (board[i][col] != '.'&&board[i][col] == c) return false;
			if (board[row][i] != '.'&&board[row][i] == c) return false;
			if (board[i / 3 + (row / 3) * 3][(col / 3) * 3 + i % 3] != '.'&&board[i / 3 + (row / 3) * 3][(col / 3) * 3 + i % 3] == c) return false;
		}
		return true;
	}

	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; ++c) {
						if (isValid(board, i, j, c)) {
							board[i][j] = c;
							if (solve(board))
							{
								return true;
							}
							else
							{
								board[i][j] = '.';
							}
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		if (board.size()==0) return ;
		solve(board);
	}

	int main() {
		vector<vector<char>> board;
		char x;
		for (int i = 0; i < 9; ++i) {
			vector<char> tmp;
			for (int j = 0; j < 9; ++j) {
				cin >> x;
				tmp.push_back(x);
			}
			board.push_back(tmp);
		}
		solveSudoku(board);
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}