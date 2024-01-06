
/* 

    Solution by Rahul Surana
    
    ***********************************************************

Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

    ***********************************************************
*/


#include <bits/stdc++.h>


class FooBar {
private:
    int n;
    std::mutex mtx;
    std::condition_variable cv;
    bool x = false;

public:
    FooBar(int n) {
        this->n = n;
        
    }

    void foo(function<void()> printFoo) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
           cv.wait(lock, [&] { return !x; });
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            x=true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        std::unique_lock<std::mutex> lock(mtx);
        for (int i = 0; i < n; i++) {
            cv.wait(lock, [&] { return x; });
           
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            x=false;
            cv.notify_one();
        }
    }
};