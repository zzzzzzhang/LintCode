#include<string>
#include<queue>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        int n = start.size();
        if (start == end) return 1;
		if(n < 1 || n != end.size()) return 0;
		queue<string> Q;
		Q.push(start);
		int length = 2;
		while(Q.size()!=0)
		{
			int size = Q.size();
			for(int j = 0; j < size; ++j)
			{
				string word = Q.front(); Q.pop();
				for(int i = 0; i < n; ++i)
				{
					char ori_char = word[i];
					for(char c = 'a'; c <= 'z'; ++c)
					{
						if(c == ori_char) continue;
						else word[i] = c;
						if(word == end) return length;
						if(dict.find(word) != dict.end())
						{
							Q.push(word);
							dict.erase(word);
						}
					}
					word[i] = ori_char;
				}
			}
			length++;
		} 
		return 0;
    }
};
int main()
{
	Solution solve;
	string start = "hit", end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","lot","log"};
	int out = 0;
	out = solve.ladderLength(start, end, dict);
	cout<<out<<endl;
}
