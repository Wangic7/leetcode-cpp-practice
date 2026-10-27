//Boyer–Moore 投票算法 不需要哈希表 仅需两个变量
//时间复杂度O(n)，空间复杂度O(1);
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }

            if (x == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
