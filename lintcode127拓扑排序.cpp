#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

struct DirectedGraphNode 
{
	int label;
	vector<DirectedGraphNode *> neighbors;
	DirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) 
	{
        // write your code here
        map<DirectedGraphNode*, int> cnt;
        vector<DirectedGraphNode*> ans;
        for(int i = 0; i < graph.size(); ++i)
        {
        	for(int j = 0; j < graph[i]->neighbors.size(); ++j)	 
        	(cnt.count(graph[i]->neighbors[j]))? cnt[graph[i]->neighbors[j]]++ : cnt[graph[i]->neighbors[j]] = 1;
		}
		queue<DirectedGraphNode*> q;
		DirectedGraphNode *p;
		for(int i = 0; i < graph.size(); ++i)
		if(!cnt.count(graph[i])) q.push(graph[i]);
		while(!q.empty())
		{
			p = q.front(); q.pop(); ans.push_back(p);
			for(int i = 0; i < p->neighbors.size(); ++i)
			{
				cnt[p->neighbors[i]]--;
				if(!cnt[p->neighbors[i]]) 
				{
					q.push(p->neighbors[i]);
				}
			}
		}
		return ans;
    }
};

int main()
{
	Solution solve;
	DirectedGraphNode node1(1);
	DirectedGraphNode node2(0);
	node1.neighbors.push_back(&node2);
	vector<DirectedGraphNode*> graph = {&node1};
	vector<DirectedGraphNode*> ans;
	ans = solve.topSort(graph);
	cout<<ans[1]->label<<endl;
	return 0;
}
