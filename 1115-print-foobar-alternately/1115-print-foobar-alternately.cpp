class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int state=0;

public:
    FooBar(int n) {
        this->n = n;
    }
    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
              unique_lock<mutex> lock(m);
            cv.wait(lock, [&]{ return state == 0; });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            state = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
             unique_lock<mutex> lock(m);
          cv.wait(lock, [&]{ return state == 1; });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state=0;
            cv.notify_all();

        }
    }
};