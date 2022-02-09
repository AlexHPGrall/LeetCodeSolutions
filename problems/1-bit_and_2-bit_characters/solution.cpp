class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i=0;;i=bits[i]?i+2:i+1)
        {
            if(i>=bits.size())
                return false;
            else if(i==bits.size()-1)
            {
                return true;
            }
        }
    }
};