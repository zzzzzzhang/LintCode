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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        // write your code here
        if (root == NULL) return;  
        while (root) {  
            if (root->left) {  
                TreeNode *pre = root->left;  
                while (pre->right)  
                    pre = pre->right;  
                pre->right = root->right;  
                root->right = root->left;  
                root->left = NULL;  
            }
            root = root->right;
        }  
    }
};
int main()
{
	Solution solve;
	TreeNode *out = new TreeNode(0);
	TreeNode T0(0);
	TreeNode T1(1);
	TreeNode T2(2);
	T0.left = &T1;
	T0.right = &T2;
	solve.flatten(&T0);
	cout<<T0.right->val<<endl;
	cout<<T0.left<<endl;
	cout<<T0.right->right->val<<endl; 
	return 0;
}
