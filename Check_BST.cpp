#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <sstream>

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

TreeNode *generateTree(string &input) {
  if (!input.size())
    return nullptr;

  stringstream ss(input.substr(1, input.size() - 1));
  string s;
  getline(ss, s, ',');
  TreeNode *root = new TreeNode(stoi(s));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);
  while (ss) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();
    if (getline(ss, s, ',') && none_of(s.begin(), s.end(), ::isalpha)) {
      int leftNumber = stoi(s);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }
    if (getline(ss, s, ',') && none_of(s.begin(), s.end(), ::isalpha)) {
      int rightNumber = stoi(s);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

bool checkBST(TreeNode *root) {
  TreeNode *curr = root;
  int prev = INT_MIN;
  while (curr) {
    if (curr->left) {
      TreeNode *rightMost = curr->left;
      while (rightMost->right && rightMost->right != curr)
        rightMost = rightMost->right;
      if (!rightMost->right) {
        rightMost->right = curr;
        curr = curr->left;
      } else {
        rightMost->right = curr;
        if (curr->val < prev)
          return false;
        prev = curr->val;
        curr = curr->right;
      }
    } else {
      if (curr->val < prev)
        return false;
      prev = curr->val;
      curr = curr->right;
    }
  }
  return true;
}
int main() {
  string input = "[2, 1, 3]";
  boolalpha(cout);
  cout << checkBST(generateTree(input));
}
