#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int h = board.size(), w = board[0].size();
    vector<vector<int>> visited(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (check(board, word, visited, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }
  bool check(const vector<vector<char>>& board, const string& word,
             vector<vector<int>>& visited, int i, int j, int word_pos) {
    bool result = false;
    if (board[i][j] != word[word_pos]) return false;
    if (word_pos == word.size() - 1) return true;

    int h = board.size(), w = board[0].size();

    visited[i][j] = 1;
    int director[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    for (int pos = 0; pos < sizeof(director) / sizeof(director[0]); ++pos) {
      int newi = i + director[pos][0], newj = j + director[pos][1];
      if (newi >= 0 && newi < h && newj >= 0 && newj < w) {
        if (!visited[newi][newj]) {
          if (check(board, word, visited, newi, newj, word_pos + 1)) {
            result = true;
            break;
          }
        }
      }
    }
    visited[i][j] = 0;
    return result;
  }
};

void DumpVector(std::vector<std::vector<int>> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << "[";
    for (auto it2 : it1) {
      std::cout << it2 << ",";
    }
    std::cout << "]";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
  Solution s;
  vector<vector<char>> board1{
      {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}};
  std::cout << s.exist(board1, "ABCCED") << std::endl;

  vector<vector<char>> board2{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::cout << s.exist(board2, "SEE") << std::endl;

  vector<vector<char>> board3{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  std::cout << s.exist(board3, "ABCB") << std::endl;
  return 0;
}