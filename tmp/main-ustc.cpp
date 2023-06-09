#include <condition_variable>

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    // 等待直至 main() 发送数据
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});

    // ready=true，结束等待，我们占有锁。
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // 发送数据回 main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // 通知前完成手动解锁，以避免等待线程才被唤醒就阻塞（细节见 notify_one ）
    lk.unlock();
    //cv.notify_one();
}

int main()
{
    std::thread worker(worker_thread);

    data = "Example data";
    // 发送数据到 worker 线程
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    //cv.notify_one();

    worker.join();
}
