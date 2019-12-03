#include<vector>
#include<string>
#include<queue>
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        if(root == NULL) return "{}";
        string result;
        vector<TreeNode*> v;
        v.push_back(root);
        for(int i = 0; i < v.size(); ++i)
        {
        	if(v[i] != NULL)
			{	
				v.push_back(v[i]->left);
        		v.push_back(v[i]->right);
        	}
		}
        string out = "{";
        for(int i = 0; i < v.size(); ++i)
        {
        	if(v[i] == NULL) 
			out += "#";
        	else 
			out += to_string(v[i]->val);
			
			if(i < v.size() - 1)
			out += ",";
		}
		out += "}";
        return out;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    vector<string> split(const string &s1, string s2)
    {
    	vector<string> out;
    	int j;
    	for(int i= 0; i < s1.size(); ++i)
    	{
    		if(s1.substr(i, 1) != s2)
    		{
    			j = i+1;
    			for(j; j<s1.size(); ++j)
    			{
    				if(s1.substr(j,1) == s2)
    				break;
				}
			}
    		out.push_back(s1.substr(i, j-i));
    		i = j;
		}
		return out;
	}
    TreeNode * deserialize(string &data) {
        // write your code here
        if(data == "{}")
		return NULL; 
		vector<string> ss = split(data.substr(1,data.size()-2), ",");
		TreeNode *root = new TreeNode(atoi(ss[0].c_str()));
		queue<TreeNode*> Q;
		Q.push(root);
		bool isLeft = true;
		for(int i = 1; i < ss.size(); ++i)
		{
			if(ss[i] != "#")
			{
				TreeNode *node = new TreeNode(atoi(ss[i].c_str()));
				
				if(isLeft) 
				Q.front()->left = node;
				else 
				Q.front()->right = node;
				
				Q.push(node);
			}
			if(!isLeft)
			Q.pop();
			
			isLeft = !isLeft;			
		}
		return root;
    }
};

int main()
{
	Solution solve;
	TreeNode root0(0);
	TreeNode root1(1);
	TreeNode root2(2);
	root0.left = &root1;
	root0.right = &root2;
	string out1 = solve.serialize(&root0);
	cout<<out1<<endl;
//	string s1 = ",";
	vector<string> out2 = solve.split(out1, ",");
	for(auto v : out2)
	cout<<v<<endl;
}
