#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        // 1. 统计每个数字出现的次数
        for (int x : nums) {
            count[x]++;
        }

        // 2. 将哈希表转换为可以排序的 vector
        vector<pair<int, int>> freq(count.begin(), count.end());

        // 3. 按出现次数从高到低排序
        sort(freq.begin(), freq.end(),
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;//sort() 的比较函数需要通过 return 告诉排序算法，两个元素应该如何排列
            });

        // 4. 取出现次数最高的 k 个数字
        vector<int> result;

        for (int i = 0; i < k; ++i) {
            result.push_back(freq[i].first);
        }

        return result;
    }
};
// 复杂度方面，设 n 是数组长度，m 是不同数字的数量：
// - 时间复杂度：平均 On+mlog m)。
// - 空间复杂度：O(m)。

pair 的比较规则：优先比较第一个元素，第一个元素相等时再比较第二个元素

priority_queue 是 C++ 标准库提供的优先队列。一种特殊的容器：每次都能快速查看当前优先级最高的元素。
代码	含义
pq.push(x)	把元素 x 放入队列
pq.top()	查看队列顶部的元素，不删除它
pq.pop()	删除队列顶部的元素
pq.size()	查看当前元素数量

注意:pop() 只负责删除，不会返回被删除的元素

默认情况下：
priority_queue<int> pq;
创建的是大顶堆，也就是最大的元素位于顶部

小顶堆：
#include <queue>
#include <vector>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

priority_queue<
    int,                 // 元素类型
    vector<int>,         // 底层使用的容器
    greater<int>         // 排列规则，让较小的整数具有更高的顶部优先级，因此最小值位于顶部
> pq;
与默认的大顶堆相反，小顶堆的 top() 返回最小值

小顶堆解法：

#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. 统计每个数字出现的次数
        unordered_map<int, int> count;

        for (int x : nums) {
            count[x]++;
        }

        // 2. 创建小顶堆
        // pair 的 first 是出现次数，second 是数字本身
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // 3. 遍历哈希表，维护最多 k 个元素
        for (const auto& item : count) {
            int num = item.first;
            int frequency = item.second;

            if (pq.size() < k) {
                // 堆还没装满，直接加入
                pq.push({frequency, num});
            }
            else if (frequency > pq.top().first) {
                // 新数字频率更高，淘汰堆顶
                pq.pop();
                pq.push({frequency, num});
            }
        }

        // 4. 取出堆中的 k 个数字
        vector<int> result;

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
//时间复杂度	(O(N+Mlog k)，平均情况
空间复杂度	O(M+k)
其中 N 是数组长度,M 是不同数字的数量



解法三:桶排序
vector<vector<int>> buckets(nums.size() + 1);//创建桶
//平均时间复杂度O(N)
//空间复杂度O(N).   N：输入数组 nums 的长度

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. 统计每个数字出现的次数
        unordered_map<int,int> count;
        for(int x : nums)
        {
            count[x]++;
        }

        // 2. 创建桶，桶的数量为 nums.size() + 1
        int n = nums.size();
        vector<vector<int>> buckets(n+1);


        // 3. 遍历哈希表，将每个数字放入对应的频率桶
        for(const auto& item : count)
        {
            int num = item.first;
            int freq = item.second;

            buckets[freq].push_back(num);
        }

        // 4. 从高频桶向低频桶遍历
        //    将桶里的数字加入 result
        //    收集到 k 个数字后结束
        vector<int> result;
        for(int freq = n;freq >= 1 && result.size() < k;--freq)
        {
            for(int num : buckets[freq])
            {
                result.push_back(num);

                if(result.size() == k)
                {
                    break;
                }
            }
        }

        return result;
    }
};
