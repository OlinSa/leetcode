#include <algorithm>
#include <iostream>
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
  int sumNumbers(TreeNode *root) {
    return dfs(root, 0);
  }
  int dfs(TreeNode *node, int prev_val) {
    if (node == nullptr) return 0;
    int val = prev_val * 10 + node->val;
    if (node->left == nullptr && node->right == nullptr) {
      return val;
    }
    return dfs(node->left, val) + dfs(node->right, val);
  }
};

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
  std::cout << s.sumNumbers(
                   general_test_data_prorder(std::vector<int>{1, 2, 3}))
            << std::endl;
  std::cout << s.sumNumbers(
                   general_test_data_prorder(std::vector<int>{4, 9, 0, 5, 1}))
            << std::endl;
  return 0;
}