#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

void threadFunc(const vector<int>& vec, long long unsigned int& res) {
    cout << "my id is : " << this_thread::get_id() << endl;
    for (auto const& v : vec) {
        res += v;
    }
}

int main() {
    long long unsigned int res = 0;
    vector<int> vec(100000, 1);
    const auto start = chrono::high_resolution_clock::now();
    thread t1(threadFunc, std::cref(vec), std::ref(res));
    t1.join();
    auto end = chrono::high_resolution_clock::now();

    cout << "took " << chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "ms \n";

    cout << "total is " << res << endl;

}