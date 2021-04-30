class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> res;
        int rx =1, ry=1;
        while(rx + ry <= bound )
        {
            while(rx + ry <= bound )
            {
               res.insert(rx+ry);
                ry*=y;
                if(y==1)
                    break;
                
            }
            ry=1;
            rx *=x;
            if(x==1)
                break;
        }
        return vector<int>(res.begin(), res.end());
    }
    
};