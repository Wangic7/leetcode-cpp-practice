// 时间复杂度： 输入的数据越来越多，程序需要做的工作会增长多少？
// 空间复杂度： 输入的数据越来越多，程序额外需要占用的内存会增长多少？

//solution1:hash unordered_set 
// 时间复杂度：平均 O(n)
//空间复杂度：O(n)
// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// class Solution
// {
// public:
//     bool containsDuplicate(vector<int>& nums)
//     {
//         unordered_set<int> s;
//         for(int x : nums)
//         {
//             if(s.find(x) != s.end())
//             {
//                 return true;
//             }
//             s.insert(x);
//         }
//         return false;
//     }
// };

//solution2:sort
//时间复杂度：O(nlogn)
//空间复杂度：O(logn)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0;i + 1 < n;++i)
        {
            if(nums[i] == nums[i+1])
            {
                return true;
            }
        }
        return false;
    }
};