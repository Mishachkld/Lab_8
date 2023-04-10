
#include "Stack/Stack.hpp"

int main() {
    st::Stack<int> stack(101214551151553156145);   // вывод реализован ч-з std::cout
    std::cout << stack.empty() << std::endl;                                 /// empty()
    //stack.top();
    for (int i = 0; i < 10; ++i) {
        stack.push(5 + i);
    }
    std::cout << stack.empty() << std::endl;
    std::cout << stack << "Size of stack: " << stack.size() << std::endl;    /// size()

    std::cout << "delete item: " << stack.top() << std::endl;                /// top()
    stack.pop();                                                             /// pop()
    std::cout << "Size changed " << stack.size() << ", and top element too: " << stack.top() << std::endl;


    /*int &i = stack.top();
    const int &ii = stack.top();
    std::cout << "The top integer of the stack s1 is " << i << "." << std::endl;
    i--;
    std::cout << "The next integer down is " << ii << "." << std::endl;

*/

    st::Stack<std::string> stack1(10,"sdfs");
    std::cout << stack1;

    return 0;
}
