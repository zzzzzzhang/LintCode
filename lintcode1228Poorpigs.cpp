#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    /**
     * @param buckets: an integer
     * @param minutesToDie: an integer
     * @param minutesToTest: an integer
     * @return: how many pigs you need to figure out the "poison" bucket within p minutes 
     */
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // Write your code here
        int pigs = 0;
        while(pow(minutesToTest/ minutesToDie + 1, pigs) < buckets)
        {
        	pigs++;
		}
		return pigs;
    }
}; 
int main()
{
	Solution solve;
	int pigs = 0;
	pigs = solve.poorPigs(1000, 15, 60);
	cout<<"ÐèÒª"<<pigs<<"Í·Öí"<<endl; 
}
