#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool countUpDone = false;

void countUp() {
    for (int i = 0; i <= 20; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
        std::cout << "Count Up: " << i << std::endl;
    }

    // signal the second thread start
    {
        std::lock_guard<std::mutex> lock(mtx);
        countUpDone = true;
    }
    cv.notify_one();
}

void countDown() {
    // wait for countUp()
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return countUpDone; });

    for (int i = 20; i >= 0; --i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // simulate work
        std::cout << "Count Down: " << i << std::endl;
    }
}

int main() {
    std::cout << "Starting counting threads...\n";

    // create threads
    std::thread t1(countUp);
    std::thread t2(countDown);

    // wait for threads to finish
    t1.join();
    t2.join();

    std::cout << "Both threads completed.\n";
    return 0;
}
