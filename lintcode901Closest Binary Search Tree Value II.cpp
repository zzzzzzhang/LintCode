#include<iostream>
#include<vector>
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
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    void help(TreeNode *root, vector<int> &inorder)
    {
    	if(root == NULL) return;
    	help(root->left, inorder);
    	inorder.push_back(root->val);
    	help(root->right, inorder);
	}
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        // write your code here
        vector<int> inorder;
        help(root, inorder);
		vector<int> out;
		int start = 0, end = inorder.size() - 1;
		while(start < end-1)
		{
			int mid = (start + end)/2;
			(inorder[mid] < target)? start = mid : end = mid;
		}
		while(k>0)
		{
			if(start >= 0 && end < inorder.size())
			 {
			 	if(abs(inorder[start] - target) < abs(inorder[end] - target))
			 	{
			 		out.push_back(inorder[start]);
			 		k--;
					start--;
				}
				else
				{
					out.push_back(inorder[end]);
					k--;
					end++;
				}
			 }
			else if(start < 0)
			{
				out.push_back(inorder[end]);
				k--;
				end++;
			}
			else if(end >= inorder.size())
			{
				out.push_back(inorder[start]);
			 	k--;
				start--;
			}
			else
			return {};
		} 
		        
        return out;
    }
};
int main()
{
	Solution solve;
	vector<int> out;
	TreeNode T0(4), T1(3), T2(2), T3(1), T4(0);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	out = solve.closestKValues(&T0, 0.5, 2);
	for(int v:out)
	cout<<v<<endl;
	return 0;
}
