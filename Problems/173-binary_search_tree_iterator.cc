
#include <assert.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
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

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) { cur_ = root; }

  int next() {
    while (cur_) {
      node_stack_.push(cur_);
      cur_ = cur_->left;
    }
    cur_ = node_stack_.top();
    node_stack_.pop();
    int val = cur_->val;
    cur_ = cur_->right;
    return val;
  }

  bool hasNext() { return cur_ || !node_stack_.empty(); }

 private:
  std::stack<TreeNode *> node_stack_;
  TreeNode *cur_;
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
  BSTIterator *bSTIterator = new BSTIterator(
      general_test_data_prorder(std::vector<int>{7, 3, 15, -1, -1, 9, 20}));
  assert(bSTIterator->next() == 3);
  assert(bSTIterator->next() == 7);
  assert(bSTIterator->hasNext() == true);
  assert(bSTIterator->next() == 9);
  assert(bSTIterator->hasNext() == true);
  assert(bSTIterator->next() == 15);
  assert(bSTIterator->hasNext() == true);
  assert(bSTIterator->next() == 20);
  assert(bSTIterator->hasNext() == false);

  return 0;
}