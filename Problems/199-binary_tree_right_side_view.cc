
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> output;
    if (!root) return output;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int count = q.size();
      TreeNode *node = nullptr;
      while (count--) {
        node = q.front();
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        if (count == 0) {
          output.push_back(node->val);
        }
      }
    }

    return output;
  }
};

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << "]" << std::endl;
}

TreeNode *general_test_data_prorder(std::vector<int> list) {
  if (list.empty() || list[0] == -1)  // Edge case: empty list or root is null
    return nullptr;

  TreeNode *root = new TreeNode(list[0]);
  std::queue<TreeNode *> q;
  q.push(root);
  size_t index = 1;  // Start from the second element in the list

  while (!q.empty() && index < list.size()) {
    TreeNode *current = q.front();
    q.pop();

    // Create left child
    if (list[index] != -1) {
      current->left = new TreeNode(list[index]);
      q.push(current->left);
    }
    index++;

    // Create right child
    if (index < list.size() && list[index] != -1) {
      current->right = new TreeNode(list[index]);
      q.push(current->right);
    }
    index++;
  }

  return root;
}

int main(int argc, char *argv[]) {
  Solution s;
  DumpVector(s.rightSideView(
      general_test_data_prorder(std::vector<int>{1, 2, 3, -1, 5, -1, 4})));
  DumpVector(
      s.rightSideView(general_test_data_prorder(std::vector<int>{1, -1, 3})));
  DumpVector(s.rightSideView(general_test_data_prorder(std::vector<int>{})));
  DumpVector(
      s.rightSideView(general_test_data_prorder(std::vector<int>{1, 2, 3, 4})));
  return 0;
}