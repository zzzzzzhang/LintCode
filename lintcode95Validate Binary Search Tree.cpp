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

//class Solution {
//public:
//    /**
//     * @param root: The root of binary tree.
//     * @return: True if the binary tree is BST, or false
//     */
//    bool help(TreeNode *root){
//    	bool l = 1; 
//    	bool r = 1;
//    	if(root == NULL) return 1;
//    	if(root->left != NULL && root->right != NULL)
//    	{
//    		l = (root->left->val < root->val)? 1:0;
//    		l &= help(root->left);
//    		r = (root->right->val > root->val)? 1:0;
//    		r &= help(root->right);
//		}
//    	else if(root->left == NULL && root->right == NULL)
//    	{
//    		l = 1;
//			r = 1;
//		}
//    	else if(root->left == NULL)
//    	{
//			l = 1;
//			r =  (root->right->val <= root->val)? 0:1;
//			r &= help(root->right);
//		}	
//    	else if(root->right == NULL)
//    	{
//    		l =  (root->left->val >= root->val)? 0:1;
//    		l &= help(root->left);
//			r = 1;	
//		}
//    	return l&r;
//	}
//    bool isValidBST(TreeNode *root) {
//        // write your code here
//        bool res = help(root);
//        return res;
//    }
//};

class Solution {
private:
    TreeNode *lastNode = NULL;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
    	if(root == NULL) 
		return true;
		
		if(!isValidBST(root->left)) 
		return false;
		
		if(lastNode != NULL && lastNode->val >= root->val) 
		return false;
		
		lastNode = root;
        return isValidBST(root->right);
    }
};

int main()
{
	Solution solve;
	TreeNode T0(4), T1(3), T2(2), T3(1), T4(0);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	TreeNode *TN = NULL;
	auto out = solve.isValidBST(TN);
	cout<<out<<endl;
	return 0;
}
