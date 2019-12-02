#include<vector>
#include<string>
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
}
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        if(root == NULL) return "{}";
        string result;
        vector<*node> v;
        v.push_back(root);
        for(int i = 0; i < v.size(); ++i)
        {
        	if(v[i] != NUll)
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
			out += to_string(v[i].val);
			
			if(i < v.size() - 1)
			out += ",";
			else
			out += "}";
		}
        return out;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
        
    }
};
