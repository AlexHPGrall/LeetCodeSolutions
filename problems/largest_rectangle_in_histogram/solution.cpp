class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        h.insert(h.begin(), 0);
        h.push_back(0);
        int res=h[0];
        int idx;
        st.push(0);
        for(int i=0; i<h.size();++i)
        {
            //cout<<i<<endl;
            res=max(res,h[i]);
            while(h[i]<h[idx=st.top()])
            {
                st.pop();
                res=max(res, h[idx]*(i-st.top()-1));
            }

            st.push(i);

        }
        
        return res;
    }
};
/* Notes for myself:
basically the same idea than the one i had
but instead of going through the stack for each i in h, 
we're computing the size of the rectangles we're popping off while 
constructing the monotone stack
we add a dummy zero at the beginning so no empty stack
and more importantly one at the end which has us 
go through the entire remaining stack
*/