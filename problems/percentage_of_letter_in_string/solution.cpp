class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;
        for(char c:s)
            if(c==letter)
                cnt+=100;
        
        return cnt/s.size();
    }
};