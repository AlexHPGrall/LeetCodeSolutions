class BrowserHistory {
    vector<string> hist;
    int curr;
    int end;
public:
    BrowserHistory(string homepage) {
        hist.push_back(move(homepage));
        curr=0;
        end=1;
    }
    
    void visit(string url) {
        curr++;
        end=curr+1;
        if(hist.size()<end)
        {
            hist.push_back(move(url));
        }
        else
        {
            hist[curr]=move(url);
        }
    }
    
    string back(int steps) {
        curr=max(0, curr-steps);
        return hist[curr];
    }
    
    string forward(int steps) {
        curr=min(curr+steps, end-1);
        return hist[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */