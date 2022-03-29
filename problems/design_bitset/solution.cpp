class Bitset {
    int size;
    vector<unsigned long long> arr;
    int cnt;
    string s;
public:
    Bitset(int size) : size(size){
        int arrSize=1+size/64;
        arr.resize(arrSize,0);
        cnt=0;
        s.resize(size,'0');
        
    }
    
    void fix(int idx) {
        int arrIndex=idx/64;
        int bitIndex=idx%64;
        cout<<idx<<' '<<arrIndex<<' '<<bitIndex<<endl;
        //cout<<arr[arrIndex]<<' '<<bitIndex<<' ';
        if(!(arr[arrIndex]&((unsigned long long)1<<bitIndex)))
            cnt++;
        arr[arrIndex]|=((unsigned long long)1<<bitIndex);
        //cout<<arr[arrIndex]<<endl;
        
    }
    
    void unfix(int idx) {
        int arrIndex=idx/64;
        int bitIndex=idx%64;
        
        if((arr[arrIndex]&((unsigned long long)1<<bitIndex)) != 0)
        {
            cnt--;
        }
        arr[arrIndex]&=~((unsigned long long)1<<bitIndex);
        
    }
    
    void flip() {
        for(int i=0;i<arr.size(); ++i)
        {
            arr[i]=~arr[i];
        }
        cnt=size-cnt;
        //cout<<cnt<<endl;
    }
    
    bool all() {
        return cnt==size;
    }
    
    bool one() {
        return cnt>0;
    }
    
    int count() {
        return cnt;
    }
    
    string toString() {
        for(int i=0; i<size;++i)
            s[i]=!(arr[i/64]&((unsigned long long)1<<(i%64)))?'0':'1';
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */