//给你一个整数数组 nums ，
// 除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。
// 请你找出并返回那个只出现了一次的元素。

 

class Solution {
public:
    int singleNumber(vector<int>& nums) {   
        vector<int> bit_arr(32,0);
        for(int i=0;i<nums.size();i++)
        {
            int bit=32;
            while(bit--)
            {
                bit_arr[bit]+= (1&(nums[i]>>bit));
            }
        }

        int ret=0;
        for(int i=0;i<32;i++)
        {
            if(bit_arr[i]%3==1)
            {
                ret|=(1<<i);//例如左移3位 0000001000，按位或达到效果
            }
        }
        return ret;
    }
};