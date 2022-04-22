class MyHashMap {
    vector<vector<pair<int,int>>> buckets;
    int bucketCount;
    int keyCount;
    const float loadFactor=0.8f;
    void rehashIfNecessary()
    {
        
        if((float)keyCount/(float)bucketCount <loadFactor)
            return;
        
        bucketCount<<=1;
        vector<vector<pair<int,int>>>tmp(bucketCount);
        for(auto &v:buckets)
            for(auto &p:v)
                tmp[hash<int>{}(p.first)%bucketCount].push_back(p);
        buckets=move(tmp);

    }
public:
    MyHashMap() {
        bucketCount=1024;
        buckets.resize(bucketCount);
        
    }
    
    void put(int key, int value) {
        for(auto &p:buckets[hash<int>{}(key)%bucketCount])
        {
            if(p.first==key)
            {
                p.second=value;
                return;
            }
           
        }
        buckets[hash<int>{}(key)%bucketCount].push_back({key,value});
        keyCount++;
        rehashIfNecessary();
    }
    
    int get(int key) {
        
        for(auto &p:buckets[hash<int>{}(key)%bucketCount])
        {
            if(p.first==key)
                return p.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int bucket=hash<int>{}(key)%bucketCount;
        for(int i=0; i<buckets[bucket].size();++i)
        {     
            if(key==buckets[bucket][i].first)
            {
                swap(buckets[bucket][i],buckets[bucket].back());
                buckets[bucket].pop_back();
                keyCount--;
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */