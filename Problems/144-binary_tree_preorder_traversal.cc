
#include <algorithm>
#include <iostream>
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> output;

    preorder(root, output);
    return output;
  }

  void preorder(TreeNode *node, vector<int> &output) {
    if (node == nullptr) return;
    output.push_back(node->val);
    preorder(node->left, output);
    preorder(node->right, output);
  }
};

TreeNode *build_tree(std::vector<int> &list, int &index) {
  if (index >= list.size() || list[index] == -1) {
    index++;
    return nullptr;
  }
  TreeNode *node = new TreeNode(list[index++]);
  node->left = build_tree(list, index);
  node->right = build_tree(list, index);
  return node;
}

TreeNode *general_test_data_prorder(std::vector<int> list) {
  int i = 0;
  return build_tree(list, i);
}

void DumpVector(std::vector<int> source) {
  std::cout << "[";
  for (auto it1 : source) {
    std::cout << it1 << ",";
  }
  std::cout << "]" << std::endl;
}
int main(int argc, char *argv[]) {
  Solution s;
  DumpVector(s.preorderTraversal(
      general_test_data_prorder(std::vector<int>{1, -1, 2, 3})));
  DumpVector(
      s.preorderTraversal(general_test_data_prorder(std::vector<int>{})));
  DumpVector(
      s.preorderTraversal(general_test_data_prorder(std::vector<int>{1})));

  return 0;
}