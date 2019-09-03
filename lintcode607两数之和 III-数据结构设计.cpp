#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class TwoSum {
public:
    /**
     * @param number: An integer
     * @return: nothing
     */
     vector<int> nums = {};
     unordered_map<int, int> arr;
    void add(int number) {
        // write your code here
        nums.push_back(number);
        cout<<nums.at(nums.size()-1)<<endl;
    }

    /**
     * @param value: An integer
     * @return: Find if there exists any pair of numbers which sum is equal to the value.
     */
    bool find(int value) {
        // write your code here
        arr.clear();
        for(int i = 0; i < nums.size(); i++)
        	{
				if (arr.count(nums.at(i)) > 0)
        			return true;
        			cout<<value - nums.at(i)<<" "<<value<<endl;
        		arr[value - nums.at(i)] = nums.at(i);
			}
		return false;
    }
};
int main()
{
	TwoSum solve;
	solve.add(1);
	solve.add(3);
	solve.add(5);
	bool flag_1 = solve.find(4);
	bool flag_2 = solve.find(7);
	cout<<flag_2<<endl;
}
