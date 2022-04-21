class MyHashSet {
    vector<uint8_t> hashMap=vector<uint8_t>((1e6)+1,0);
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        hashMap[key]=1;
    }
    
    void remove(int key) {
        hashMap[key]=0;
    }
    
    bool contains(int key) {
        return hashMap[key]==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */