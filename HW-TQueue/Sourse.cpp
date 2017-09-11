#include "../simple_memory_leak_detector.h"

#include <queue>
#include <iostream>
#include <string>

#define CHECK

#ifdef CHECK
#include "test_queue.h"

template<class T>
using queue = TQueue<T>;

#else

template<class T>
using queue = std::queue<T>;

#endif // CHECK


#define assert(X) { \
    if(!(X)) {\
        std::cout << "see function:'" << __FUNCTION__ << "' line: " << __LINE__;\
        throw std::logic_error(#X); \
    }\
}

int main()
{
   {
       queue<std::string> m;
       assert(m.empty());

       m.push("a");
       m.push("b");
       m.push("c");
       assert(m.size() == 3);

       assert(m.front() == "a");
       assert(m.front() == "a");
       assert(m.front() == "a");

       auto m1 = m;
       assert(m.front() == "a");

       m1.pop();
       m1.pop();
       m1.pop();
       assert(m1.empty());

       m1.swap(m);
       assert(m.empty());
       assert(m1.size() == 3);

       assert(m1.back() == "c");
       
       m1.pop();
       assert(m1.front() == "b");

       m1.pop();
       assert(m1.front() == "c");

       m1.pop();
       assert(m1.empty());
   }

   std::cout << std::boolalpha << memoryLeakExist() << std::endl;
}
