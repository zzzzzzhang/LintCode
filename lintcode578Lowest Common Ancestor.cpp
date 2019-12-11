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
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode *res = NULL;
    
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        help(root, A, B);
        return res; 
        
    }
    int help(TreeNode * root, TreeNode * A, TreeNode * B)
	{
		if(root == NULL) return 0;
		
		int total = 0;
		
		if(root == A) total++;
		if(root == B) total++;
		
		int l = help(root->left, A, B);
		int r = help(root->right, A, B);
		
		if(l == 2 || r == 2) return 2;
		
		total += l + r;
		
		if(total == 2) res = root;
		
		return 2;
	}
};

int main()
{
	Solution solve;
	TreeNode *out = NULL;
	TreeNode T0(4), T1(3), T2(2), T3(1), T4(0);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	out = solve.lowestCommonAncestor3(&T0, &T1, &T2);
	cout<<out->val<<endl;
	return 0;
}
