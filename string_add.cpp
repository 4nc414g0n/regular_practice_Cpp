class Solution {
public:
    string addStrings(string num1, string num2) {
        string s1;
        int add=0,size1=num1.length()-1,size2=num2.length()-1;
        while(size1>=0||size2>=0||add!=0)
        {
            int x=size1>=0?num1[size1]-'0':0;
            int y=size2>=0?num2[size2]-'0':0;
            int sum=x+y+add;
            s1.push_back('0'+sum%10);
            add=sum/10;
            size1--;
            size2--;
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};