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
TreeNode *generateTree(std::string &input) {
  if (!input.size())
    return nullptr;

  std::stringstream ss(input.substr(1, input.size() - 1));
  std::string s;
  getline(ss, s, ',');
  TreeNode *root = new TreeNode(stoi(s));
  std::queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);
  while (ss) {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();
    if (getline(ss, s, ',') && s != " null") {
      int leftNumber = stoi(s);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }
    if (getline(ss, s, ',') && s != " null") {
      int rightNumber = stoi(s);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

TreeNode *lowestCommonAncestor(TreeNode *root, int p, int q) {
  if (!root || root->val == p || root->val == q)
    return root;
  TreeNode *left = lowestCommonAncestor(root->left, p, q);
  TreeNode *right = lowestCommonAncestor(root->right, p, q);
  if (left && right)
    return root;
  if (left || right)
    return (left ? left : right);
  return nullptr;
}
int main() {
  string input = "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]";
  int p = 1, q = 2;
  cout << lowestCommonAncestor(generateTree(input), p, q)->val;
}
