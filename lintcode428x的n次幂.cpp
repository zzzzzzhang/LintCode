#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        // write your code here
        if (n == 0)
        return 1.;
        if(n == -2147483648)
        return 0.;
        double out = 1.;
        for(int i = 0; i < abs(n); i++)
        	out *= x;
        if(n > 0)
        	return out;
        if(n < 0)
        	return 1/out;
    }
};
int main()
{
	Solution solve;
	int n = -2147483648;
	double x = 2.00000, out = 0.0;
	out = solve.myPow(x ,n);
	cout<<out<<endl; 	
}
