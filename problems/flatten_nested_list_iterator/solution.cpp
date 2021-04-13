/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<NestedInteger*> Start, End;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        Start.push_back(&nestedList.front());
        End.push_back(&nestedList.back());
        
    }
    
    int next() {
        return Start.back()++->getInteger();
        
    }
    
    bool hasNext() {
        while(Start.size())
        {
            auto top = Start.back();
            if(Start.back() > End.back())
            {
                Start.pop_back(); End.pop_back();
                continue;
            }
            if(top->isInteger()) break;
            Start.back()++;
            if(!size(top -> getList())) continue;
            Start.push_back(&top->getList().front());
            End.push_back(&top->getList().back());
        }
        
        return size(Start);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */