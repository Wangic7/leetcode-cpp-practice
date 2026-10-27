class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);

        // 第一步：保存每个位置左边所有数字的乘积
        int prefix = 1;
        for(int i = 0; i<n;++i)
        {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // 第二步：从右往左，乘上右边所有数字的乘积
        int suffix = 1;
        for(int i  = n - 1;i >= 0;--i)
        {
            answer[i] *= suffix;
            suffix *= nums[i]; 
        }

        return answer;
        
    }
};