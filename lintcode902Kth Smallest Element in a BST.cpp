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
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    void help(TreeNode *root, int &k, int &res)
    {
    	if(root == NULL || k == 0) return;
    	help(root->left, k, res);
    	if(k > 0)
    	{
    		res = root->val;
    		k--;
		}
    	help(root->right, k, res);
    	
	}
    int kthSmallest(TreeNode * root, int k) {
        // write your code here
        int res;
        help(root, k, res);
        return res;
    }
};
int main()
{
	Solution solve;
	int out;
	TreeNode T0(4), T1(3), T2(2), T3(1), T4(0);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	out = solve.kthSmallest(&T0, 1);
	cout<<out<<endl;
	return 0;
}
