 #include<vector>
 #include<queue> 
 #include<unordered_map>
using namespace std; 
struct UndirectedGraphNode 
{
	int label;	
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if(!node) return nullptr;
        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        map[node] = p2;
        while(!q.empty())
        {
        	p1 = q.front(); p2 = map[p1]; q.pop();
	        for(int i = 0; i < p1->neighbors.size(); ++i)
	        {
	        	UndirectedGraphNode *nb = p1->neighbors[i];
	        	if(map.count(nb))
				{
					p2->neighbors.push_back(map[nb]);
				}
				else
				{
					UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
					p2->neighbors.push_back(temp);
					map[nb] = temp;
					q.push(nb); 
				} 
			}
		}
		return map[node];
    }
};

