class CombinationIterator {
    int curr;
    int last;
    int first;
    int clength;
    string chars;
    string perm;
    stack<int> cmb;
    int n;
    
    int next(int x)
    {
    int smallest, ripple, new_smallest, ones;

     if (x == 0) return first;
     smallest     = (x & -x);
     ripple       = x + smallest;
     new_smallest = (ripple & -ripple);
     ones         = ((new_smallest/smallest) >> 1) - 1;
     return ripple | ones;
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        chars=characters;
        n=chars.length();
        first=0;
        last=0;
        clength=combinationLength;
        for(int i=0; i<clength; ++i)
        {
            first |= (1<<i);
            last |=(1<<(n-1-i));
        }
        curr=0;
        perm.resize(clength);
        for(;curr!=last;)
        {
            curr=next(curr);
            cmb.push(curr);
        }
    }
    
    string next() {
        int mask = cmb.top();
        cmb.pop();
        
        int j=0;
        for(int i=0; i<n;++i)
        {
            if(mask & (1<<(n-1-i)))
                perm[j++] =chars[i];
        }
            
        return perm;
    }
    
    bool hasNext() {
        return !(cmb.empty());
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */