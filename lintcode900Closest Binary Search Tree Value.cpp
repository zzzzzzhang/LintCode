#include<iostream>
#include<cmath>
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
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        int closest = root->val;
        while(root)
		{
			closest = (abs(root->val - target) < abs(closest - target))? root->val : closest;
			root = (root->val >= target)? root->left : root->right;
		} 
		return closest;
    }
};

int main()
{
	Solution solve;
	int out;
	TreeNode T0(3), T1(2), T2(4), T3(1);
	T0.left = &T1;
	T0.right = &T2;
	T2.left = &T3;
	double target= 4.14;
	out = solve.closestValue(&T0, target);
	cout<<out<<endl;
	return 0;
}
