//mutex
class Foo {
public:
    mutex m1, m2, m3;
public:
    Foo() {
        m1.lock();
        m2.lock();
    }
    ~Foo(){
        m1.unlock();
        m2.unlock();
        m3.unlock();
    }

    void first(function<void()> printFirst) {
        m3.lock();
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};



//condition variable
class Foo {
public:
    condition_variable cv;
    int i;
    mutex m;
public:
    Foo() {
        i = 1;
    }
    
    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{return (i==1)?true:false;});
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{return (i==2)?true:false;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this]{return (i==3)?true:false;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};

class Foo {
public:
    condition_variable cv;
    int i;
    mutex m;
public:
    Foo() {
        i = 1;
    }
    
    void first(function<void()> printFirst) { 
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return (i==1)?true:false;});
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        i++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return (i==2)?true:false;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        i++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{return (i==3)?true:false;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};