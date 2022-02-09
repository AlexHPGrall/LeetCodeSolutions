class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]>rec2[0])
            swap(rec1,rec2);
        if(rec2[0]<rec1[2])
        {
            if(rec1[1]>rec2[1])
            swap(rec1,rec2);
            if(rec2[1]<rec1[3])
                return true;
        }
        return false;
    }
};