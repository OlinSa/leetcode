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
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<vector<int>> output;
    preOrder(root, targetSum, vector<int>{}, output);
    return output;
  }

  void preOrder(TreeNode *node, int sum, vector<int> path,
                vector<vector<int>> &output) {
    if (node == nullptr) return;
    path.push_back(node->val);
    if (node->val == sum && node->left == nullptr && node->right == nullptr) {
      output.push_back(path);
      return;
    }
    preOrder(node->left, sum - node->val, path, output);
    preOrder(node->right, sum - node->val, path, output);
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

int main(int argc, char *argv[]) {
  Solution s;
  DumpVector(s.pathSum(general_test_data_prorder(std::vector<int>{
                           5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1}),
                       22));
  DumpVector(
      s.pathSum(general_test_data_prorder(std::vector<int>{1, 2, 3}), 5));
  DumpVector(s.pathSum(general_test_data_prorder(std::vector<int>{1, 2}), 0));
  DumpVector(
      s.pathSum(general_test_data_prorder(std::vector<int>{-2, -1, -3}), -5));
  return 0;
}
