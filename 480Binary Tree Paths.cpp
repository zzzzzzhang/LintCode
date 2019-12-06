#include<iostream>
#include<vector>
#include<string>
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
private:
		void dfs(TreeNode *root, string path, vector<string> &paths){
		if (root->left == NULL && root->right == NULL)
		{
			paths.push_back(path);
			return;
		}
		if(root->left != NULL)
		{
			string _path = path;
			_path += "->";
			_path += to_string(root->left->val);
			dfs(root->left, _path, paths);
		}
		if(root->right != NULL)
		{
			string _path = path;
			_path += "->";
			_path += to_string(root->right->val);
			dfs(root->right, _path, paths);
		}
		
	}
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        if(root == NULL) return {};
        vector<string> paths;
        string path;
        path += to_string(root->val);
        dfs(root, path, paths);
        return paths;
    }
};

int main(){
	TreeNode T0(0), T1(1), T2(2), T3(3);
	T0.left = &T1;
	T0.right = &T2; 
	T2.left = &T3;
	vector<string> paths;
	Solution solve;
	paths = solve.binaryTreePaths(&T0);
	for(auto v:paths)
	{
		cout<<v<<endl;
	}
	return 0;
}
