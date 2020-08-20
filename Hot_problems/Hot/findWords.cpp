//lc_212，DFS+Trie树
#include<vector>
#include<iostream>
#include<string>

using namespace std;
vector<string> res;
int row, col;

struct Trie
{
	string word = "";
	vector<Trie *> node;
	Trie() :node(26, 0) {}
};

void DFS(vector<vector<char>>& board, Trie* root, int x, int y) {
	char c = board[x][y];
	if (c == '.' || root->node[c - 'a'] == 0) return;
	root = root->node[c - 'a'];
	if (root->word != "") {
		res.push_back(root->word);
		root->word = "";
	}
	board[x][y] = '.';
	if (x > 0) DFS(board, root, x - 1, y);
	if (y > 0) DFS(board, root, x, y - 1);
	if (x + 1 < row) DFS(board, root, x + 1, y);
	if (y + 1 < col) DFS(board, root, x, y + 1);
	board[x][y] = c;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	if (board.size() <= 0) return res;
	row = board.size();
	col = board[0].size();
	Trie* root = new Trie();
	for (string word : words) {
		Trie * curNode = root;
		for (int i = 0; i < word.size(); ++i) {
			int idx = word[i] - 'a';
			if (curNode->node[idx] == 0) curNode->node[idx] = new Trie();
			curNode = curNode->node[idx];
		}
		curNode->word = word;
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			DFS(board, root, i, j);
		}
	}
	return res;
}

int main() {
	vector<vector<char>> board;
	vector<string> words;
	for (int i = 0; i < 4; ++i) {
		vector<char> elem;
		for (int j = 0; j < 4; ++j) {
			char x;
			cin >> x;
			elem.push_back(x);
		}
		board.push_back(elem);
	}
	cin.clear();
	cin.ignore();
	for (int i = 0; i < 4; ++i) {
		string xx;
		cin >> xx;
		words.push_back(xx);
	}
	res = findWords(board, words);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
