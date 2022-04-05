class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool b1=false, b2=false, b3=false;
        for(auto &t:triplets)
        {
            if(t[0]<=target[0]&&t[1]<=target[1]&&t[2]<=target[2])
            {
                if(t[0]==target[0])
                    b1=true;
                if(t[1]==target[1])
                    b2=true;
                if(t[2]==target[2])
                    b3=true;
            }
        }
        return b1 && b2 &&b3;
    }
};