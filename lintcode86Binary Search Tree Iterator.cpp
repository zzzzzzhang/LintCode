#include<iostream>
#include<vector>
#include<stack>
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

class BSTIterator {
private:
	stack<TreeNode *> stk;
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        while(root != NULL)
        {
        	stk.push(root);
        	root = root->left;
		}
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !stk.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode *next() {
        // write your code here
        TreeNode *nextNode = stk.top(); stk.pop();
        if(nextNode->right != NULL)
        {	
        	TreeNode *curr = nextNode->right;
	        while(curr != NULL)
    	    {
        		stk.push(curr);
        		curr = curr->left;
			}
		}
		return nextNode;
    }
};

int main()
{	
	TreeNode T0(4), T1(3), T2(2), T3(1), T4(0);
	T0.left = &T1;
	T1.left = &T2;
	T2.left = &T3;
	T3.left = &T4;
	BSTIterator BST(&T0);
	auto out = BST.next();
	auto out1 = out->next();
	cout<<out1->val<<endl;
	return 0;
}
