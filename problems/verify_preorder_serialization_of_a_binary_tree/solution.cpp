class Solution {
public:
    int i, n;
    bool checkNode(string &preorder)
    {
        if(i>=n)
            return false;
        if(preorder[i] == '#')
            return true;
        while(preorder[i++]!=',')
        {
            if(i>=n)
            return false;
        }
        bool res = checkNode(preorder);
        while(preorder[i++]!=',')
        {
            if(i>=n)
            return false;
        }
        return  res && checkNode(preorder);
    }
    bool isValidSerialization(string preorder)
    {
        i =0;
        n=preorder.length();
        if(!checkNode(preorder))
        {
            //cout<< i << " "<< n<<endl;
            return false;
        }
            
        
        if(i<n-1)
        {
            return false;
        }
            
        return true;
    }
};