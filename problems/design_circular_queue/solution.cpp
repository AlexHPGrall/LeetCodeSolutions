class MyCircularQueue {
    int base[1000];
    int *front, *rear;
    int  max, size;
        
public:
    MyCircularQueue(int k) {
        //base = (int *) malloc(k*sizeof(int));
        max =k;
        size= 0;
        rear =front = base;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(rear == base + max)
        {
            ++size;
            *base = value;
            rear = base +1;
            return true;
        }
        *rear = value;
        ++rear;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front == base+(max -1))
        {
            front = base;
            --size;
            return true;
        }
        ++front;
        --size;
        return true;
        
    }
    
    int Front() {
        return (size == 0) ? -1 : *front;
    }
    
    int Rear() {
        return (size == 0) ? -1 : *(rear -1);
    }
    
    bool isEmpty() {
        return(size == 0);
    }
    
    bool isFull() {
        return(size == max);
    }
    
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */