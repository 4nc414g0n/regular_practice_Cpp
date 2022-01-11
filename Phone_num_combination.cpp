//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

//回溯算法
class Solution {
public:
    vector<vector<string>> arr={{""},{""},{"a","b","c"},{"d","e","f"},{"g","h","i"},
            {"j","k","l"},{"m","n","o"},{"p","q","r","s"},
            {"t","u","v"},{"w","x","y","z"}};
    //全局ret的vector<string>
    vector<string> ret;
    void Recursive(string& digits,string& s,int index) 
    {
        if(index==digits.size())
        {
            ret.push_back(s);
            return;
        }   
        else
        {
            for(auto e :arr[digits[index]-'0'])
            {
                s+=e;
                Recursive(digits,s,index+1);
                s.pop_back();
            }
            
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return ret;
        }
        int length=digits.size()-1;
        string s;
        Recursive(digits,s,0);
        return ret;
    }
};