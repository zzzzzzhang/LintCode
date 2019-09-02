/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        long long begin = 1, end = n, m = 0;
        while(begin<end-1)
        {
        if((begin+end)%2)
        m = (begin + end - 1)/2;
        else
        m = (begin+end)/2;
        if(SVNRepo::isBadVersion(m))
        {
            if(SVNRepo::isBadVersion(m-1))
                end = m-1;
            else
                return m;
        }
        else
        begin = m+1;
        cout<<begin<<" "<<end<<endl;
        }
        if(SVNRepo::isBadVersion(begin))
        return begin;
        else
        return end;
    }
};
