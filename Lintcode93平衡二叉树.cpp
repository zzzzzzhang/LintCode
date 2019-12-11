#include<iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}; 

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    int help(TreeNode *root)
    {
    	if (root == NULL) return 0;
    	auto l = help(root->left);
    	auto r = help(root->right);
    	if(l == -1 || r == -1 || abs(l-r)>1) return -1;
    	return max(l,r) + 1;
	}
    bool isBalanced(TreeNode * root) {
        // write your code here
        return help(root) != -1;
    }
};
int main()
{
	Solution solve;
	bool out;
	TreeNode T0(0), T1(1), T2(2), T3(3), T4(4);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	out = solve.isBalanced(&T0);
	cout<<out<<endl;
}
