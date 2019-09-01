#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        vector<int> out = {};
        if(k == 0)
        	return out;
        unordered_map<int, int> distance;
        for(int i = 0; i < A.size(); i ++)
        {
        	if(A[i] - target >= 0)
        	{
        		distance[abs(target - A[i])] = A[i];
        		cout<<"get: "<<abs(target - A[i])<<endl;
			}
			else
			{
				distance[abs(target - A[i]) + 100000000] = A[i];
				cout<<"get: "<<abs(target - A[i]) + 100000000<<endl;
			}
		}
		int max = 0;
		
		if (target - A[0] < A[A.size() - 1] - target)
			max =  A[A.size() - 1] - target;
		else
			max = target - A[0];
		
		cout<<"max= "<<max<<endl;
		
		for(int i = 0; i <= max; i ++)
		{
			if (distance.count(i) > 0)
			{
				if(distance.count(i + 100000000) > 0)
				{
					out.push_back(distance[i + 100000000]);
					cout<<"add:"<< distance[i + 100000000] << endl;
					if(out.size() == k)
						break;
					out.push_back(distance[i]);
					cout<<"add:"<< distance[i] << endl;
				}
				else
				{
					out.push_back(distance[i]);
					cout<<"add:"<< distance[i] << endl;
				}
			}
			else if(distance.count(i + 100000000) > 0)
				{
					out.push_back(distance[i + 100000000]);
					cout<<"add:"<< distance[i + 100000000] << endl;
				}
			if(out.size() == k)
				break;
		}
		return out;
    }
};
int main()
{
	Solution solve;
	int k = 5, target = 30;
	vector<int> input = {1,10,15,25,35,45,50,59};
	vector<int> out = {};
	out = solve.kClosestNumbers(input, target, k);
	for(int i = 0; i < k; i ++)
		cout<<out[i]<<" "<<endl; 	
}
