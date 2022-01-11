// 给定一个整数数组 nums，其中恰好有两个元素只出现一次，
// 其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

//  

// 进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2)
            return nums;
        //按二进制特征分两组

        int ret=0;
        for(auto e:nums)
        {
            ret^=e;
        }
        //找二进制标志位为1代表两数不相等
        int pos=0;
        for(int i=0;i<32;i++)
        {
            //cout<<((ret>>i)&1)<<endl;
            if(((ret>>i)&1)==1)
            {
                pos=i;
                break;
            }    
        }
        cout<<pos<<endl;
        //分组
        int num1=0;
        int num2=0;
        for(auto e:nums)
        {
            if(((e>>pos)&1)==0)
            {
                num1^=e;
            }
            else if(((e>>pos)&1)==1)
            {
                num2^=e;
            }
        }
        //分组^
        return {num1,num2};
    }
    
};