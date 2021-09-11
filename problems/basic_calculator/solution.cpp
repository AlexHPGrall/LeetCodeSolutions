class Solution {
public:
    int calculate(string s) {
        stack<int> sign;
        sign.push(1);
        int localSign = 1;
        int ans = 0;
        for(int i = 0; i< s.size();i++)
        {
            char c = s[i];
            if(isdigit(c))
            {
                int num = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    num = num*10 + (s[i++] - '0');
                }
                ans += num*localSign*sign.top();
                i--;
            }
            else if(c == '+')
                localSign = 1;
            else if(c == '-')
                localSign = -1;
            else if(c == '(')
            {
                sign.push(sign.top()*localSign);
                localSign = 1;
            }
            else if(c == ')')
                sign.pop();
        }
        return ans;
    }
};