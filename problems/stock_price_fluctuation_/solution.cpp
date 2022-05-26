class StockPrice {
public:
    int curr;
    unordered_map<int, int> stocks;
    multiset<int> prices;
    StockPrice() {
        int curr=0;
        int maximumPrice=0;
        int minimumPrice=0;
    }
    
    void update(int timestamp, int price) {
        if(curr<timestamp)
            curr=timestamp;
        if(stocks[timestamp])
        {
            prices.erase(prices.find(stocks[timestamp]));    
        }
        stocks[timestamp]=price;
        prices.insert(price);
        
    }
    
    int current() {
        return stocks[curr];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */