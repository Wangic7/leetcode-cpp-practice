#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int , int> count;

        count[0] = 1;

        int prefix = 0;
        int result = 0;

        for(int x : nums)
        {
            prefix += x;
            //查找是否存在之前的前缀和使子数组和等于k
            if(count.find(prefix - k) != count.end())
            {
                result +=count[prefix - k];
            }
            count[prefix]++;//记录当前前缀和出现的次数；
        }
        return result;
    }
};