#include <iostream>
#include "TQueue.h"
​
int main() {
    TQueue<int> q;
    std::cout << "q.empty:" << q.empty() << std::endl;
    std::cout << "q.size:" << q.size() << std::endl;
    std::cout << "q.push(1, 2, 3); q.pop();" << std::endl;  q.push(1); q.push(2); q.push(3); q.pop();
    std::cout << "q.print: "; q.print();
    std::cout << "q.empty:" << q.empty() << std::endl;
    std::cout << "q.size:" << q.size() << std::endl;
    std::cout << "q.front:" << q.front() << std::endl;
    std::cout << "q.back:" << q.back() << std::endl << std::endl;
​
    TQueue<int> q2;
    std::cout << "q2.empty: " << q2.empty() << std::endl;
    std::cout << "q2.size: " << q2.size() << std::endl;
    std::cout << "q2.swap(q); q2.pop();" << std::endl; q2.swap(q); q2.pop();
    std::cout << "q.empty: " << q.empty() << std::endl;
    std::cout << "q.size: " << q.size() << std::endl;
    std::cout << "q2.print: "; q2.print();
    std::cout << "q2.empty: " << q2.empty() << std::endl;
    std::cout << "q2.size: " << q2.size() << std::endl;
    std::cout << "q2.front: " << q2.front() << std::endl;
    std::cout << "q2.back: " << q2.back() << std::endl;
    std::cout << "q2.pop();" << std::endl; q2.pop();
    std::cout << "q2.print: "; q2.print();
    std::cout << "q2.empty: " << q2.empty() << std::endl;
    std::cout << "q2.size: " << q2.size() << std::endl;
​
    try {
        std::cout << "q2.front: " << q2.front() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
​
    system("pause");
    return 0;
}
