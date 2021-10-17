class Foo {
    atomic_bool b1, b2;
public:
    Foo() {
        b1= false;
        b2 = false;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        
        printFirst();
        atomic_store(&b1, true);
    }

    void second(function<void()> printSecond) {
        while(!atomic_load(&b1))
        {
            this_thread::sleep_for(1ms);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        atomic_store(&b2, true);
        
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        while(!atomic_load(&b2))
        {
            this_thread::sleep_for(1ms);
        }
        printThird();
    }
};