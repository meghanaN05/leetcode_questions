
class Foo {
private:
    mutex m;
    condition_variable cv;
    int state = 0;
public:
    Foo() {}
    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        printFirst();
        state = 1;
        cv.notify_all();
    }
    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{ return state >= 1; });
        printSecond();
        state = 2;
        cv.notify_all();
    }
    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&]{ return state >= 2; });
        printThird();
    }
};