class Solution {
public:
    static inline int flip(int b)
    {
        if(b)
            return 0;
        return 1;
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<m;++i)
        {
            int l=0;
            int r=n-1;
            while(l<r)
            {
                swap(image[i][l],image[i][r]);
                image[i][l]=flip(image[i][l]);
                image[i][r]=flip(image[i][r]);
                ++l;--r;
            }
            if(l==r)
                image[i][l]=flip(image[i][l]);
        }
        return image;
    }
};