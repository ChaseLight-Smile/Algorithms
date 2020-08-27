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