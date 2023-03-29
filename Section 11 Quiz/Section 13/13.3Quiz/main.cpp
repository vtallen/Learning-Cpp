/*
 * The class should be named Stack, and should contain:

    A private array of integers of length 10.
    A private integer to keep track of the size of the stack.
    A public member function named reset() that sets the size to 0.
    A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
    A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
    A public member function named print() that prints all the values in the stack.
 */

#include <iostream>

class Stack {
    int m_array[10] {};
    int m_stack_size {0};

public:
    void reset() {
        this->m_stack_size = 0;
    }

    bool push(int i) {
        if (m_stack_size >= 10) {
            return false;
        } else {
            ++m_stack_size;
            m_array[m_stack_size - 1] = i;
        }
    }

    int pop() {
        assert((m_stack_size == 0) || "Stack contains no values");

        --m_stack_size;
        return m_array[m_stack_size + 1];
    }

    void print() {
        std::cout << "(";
        for (int i {0}; i < m_stack_size; ++i) {
            std::cout << " " << m_array[i] << " ";
        }
        std::cout << ")" << '\n';
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}