class ATM {
    vector<long long> bills=vector<long long>(5,0);
public:
    ATM() {
        
    }
    
    void deposit(vector<int> dep) {
        for(int i=0;i<5;++i)
            bills[i]+=(long long)dep[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> w(5,0);
        vector<int> t(5,0);
        if(amount >= 500)
        {
            t[4]-=min((long long)amount/500, bills[4]);
            w[4]+=min((long long)amount/500, bills[4]);
            if(bills[4]<amount/500)
                amount-=(int)(500*( long long)bills[4]);
            else
                amount %=500;
            
        }
        if(amount >= 200)
        {
            t[3]-=min((long long)amount/200, bills[3]);
            w[3]+=min((long long)amount/200, bills[3]);
            if(bills[3]<amount/200)
                amount-=(int)(200*( long long)bills[3]);
            else
                amount %=200;
            
        }if(amount >= 100)
        {
            t[2]-=min((long long)amount/100, bills[2]);
            w[2]+=min((long long)amount/100, bills[2]);
            if(bills[2]<amount/100)
                amount-=(int)(100*( long long)bills[2]);
            else
                amount %=100;
        }if(amount >= 50)
        {
            t[1]-=min((long long)amount/50, bills[1]);
            w[1]+=min((long long)amount/50, bills[1]);
            if(bills[1]<amount/50)
                amount-=(int)(50*( long long)bills[1]);
            else
                amount %=50;
           
        }if(amount >= 20)
        {
            t[0]-=min((long long)amount/20, bills[0]);
            w[0]+=min((long long)amount/20, bills[0]);
            if(bills[0]<amount/20)
                amount-=(int)(20*( long long)bills[0]);
            else
                amount %=20;
            
        }
        
        if(amount)
            return {-1};
        for(int i=0;i<5;++i)
            bills[i]+=(long long)t[i];
        
        return w;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */