/*
 * given a binary tree, return the inorder traversal of its nodes' values.

for example:
given binary tree [1,null,2,3],

   1
    \
     2
    /
   3

return [1,3,2].

note: recursive solution is trivial, could you do it iteratively?
*/


#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;
 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

// Algorithm1
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> re;
        if (root->left) {
            re = inorderTraversal(root->left); 
        }
        if (root->val) {
            re.push_back(root->val);
        }
        if (root->right) {
            vector<int> tmp;
            tmp = inorderTraversal(root->right);
            for (vector<int>::iterator it = tmp.begin();
                    it != tmp.end(); it++)
                re.push_back(*it);
        }
        return re;
    }
};


// Algorithm2

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        stack<TreeNode *> s;
        if (!root) return r;
        s.push(root);
        TreeNode *tn = NULL;
        while (!s.empty()) {
            tn = s.top();
            while (tn) {
                s.push(tn->left);
                tn = tn->left;
            }
            s.pop();
            if (!s.empty()) {
                tn = s.top();
                s.pop();
                r.push_back(tn->val);
                s.push(tn->right);
            }
        }
        return r;
    }
};

int main(){
    TreeNode * root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    Solution s;
    s.inorderTraversal(root);
    return 0;
}
