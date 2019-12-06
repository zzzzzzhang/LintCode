#include<iostream>
#include<queue>
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

class Solution{
private:
	int sum_tree(TreeNode* root){
		queue<TreeNode* > Q;
		Q.push(root);
		int sum = 0;
		while(!Q.empty())
		{
			root = Q.front();Q.pop();
			sum+=root->val;
			if(root->left != NULL) Q.push(root->left);
			if(root->right != NULL) Q.push(root->right);
		}
		return sum;
	}
public:
	TreeNode * findSubtree(TreeNode* root) {
		int min = 0;
		TreeNode *T = root;
		queue<TreeNode*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			root = Q.front();Q.pop();
			int s = sum_tree(root);
			min = (s<=min)? s:min;
			T = (s<=min)? root:T;
			if(root->left != NULL) Q.push(root->left);
			if(root->right != NULL) Q.push(root->right);
		}
		return T;
	}
	
}; 
int main(){
	TreeNode T0(0);
	TreeNode T1(1);
	TreeNode T2(2);
	TreeNode T3(-3);
	TreeNode T4(4);
	T0.left = &T1;
	T0.right = &T2;
	T1.left = &T3;
	T2.right = &T4;
	Solution solve;
	TreeNode *T = new TreeNode(-1);
	T = solve.findSubtree(&T0);
	cout<<T->val<<endl;
}
