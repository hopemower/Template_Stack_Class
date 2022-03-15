#ifndef STACK_H
#define STACK_H
#include <array>

template<typename T, int max_size>

class Stack
{
private:
    std::array<T, max_size> stack_;
    int top_position_;

public:
    //constructors
    Stack();
    Stack(T item);
    //destructor
    ~Stack() {}

    void Push(T item);
    T Pop();
    T Top() const;
    int Size() const;
    bool Empty() const;
    bool Full() const;

    //other methods
    friend std::ostream& operator << (std::ostream& out, const Stack<T, max_size>& rhs)
    {
        out << rhs.stack_;
        return out;
    }
};

/**
 * @brief - initialize top_position_ to 0
 *
 * @tparam T - variable type
 * @tparam max_size - users array max size
 */

template<typename T, int max_size>
Stack<T, max_size>::Stack()
{
    top_position_ = 0;
}

/**
 * @brief - method to add data into a given array
 *
 * @tparam T - variable type
 * @tparam max_size - max size of the given array
 * @param item - item given to add to the array
 */

template<typename T, int max_size>
void Stack<T, max_size>::Push(T item)
{
    if (top_position_ == max_size)
    {
        throw std::out_of_range("The stack is full, item was not added");
    }
    stack_[top_position_++] = item;
}

/**
 * @brief - method to initialize the top_position to 0 and call the push method
 *
 * @tparam T - variable type
 * @tparam max_size - max size of given array
 * @param item - new item to add to array
 */

template<typename T, int max_size>
Stack<T, max_size>::Stack(T item)
{
    top_position_ = 0;
    Push(item);
}

/**
 * @brief - method to remove values in a stack
 *
 * @tparam T - variable type
 * @tparam max_size - max size of the array
 * @return - the new top item
 */

template<typename T, int max_size>
T Stack<T, max_size>::Pop()
{
    if (top_position_ == 0) {
        throw std::out_of_range("The stack is empty, no item to show");
    }

    T top_item = stack_[top_position_ - 1];

    top_position_--;

    return top_item;
}

/**
 * @brief - method to display the top item in the array
 *
 * @tparam T - variable type
 * @tparam max_size - max size of array
 * @return - the top_item
 */

template<typename T, int max_size>
T Stack<T, max_size>::Top() const
{
    if (top_position_ == 0)
    {
        throw std::out_of_range("The stack is empty, no item to show");
    }

    T top_item = stack_[top_position_ - 1];

    return top_item;
}

/**
 * @brief - method to return how many items are in the stack
 *
 * @tparam T - variable type
 * @tparam max_size - max size of the given array
 * @return - the current size of the stack
 */

template<typename T, int max_size>
int Stack<T, max_size>::Size() const
{
    if (top_position_ > max_size)
    {
        throw std::out_of_range("The stack is full, index too high");
    }
    return top_position_;
}

/**
 * @brief - method to check if the stack is empty
 *
 * @tparam T - variable type
 * @tparam max_size - max size of the given array
 * @return - true if the stack is empty and false if it stack has items
 */

template<typename T, int max_size>
bool Stack<T, max_size>::Empty() const
{
    if (top_position_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief - method to check if the stack is full
 *
 * @tparam T - variable type
 * @tparam max_size - max size of the array
 * @return - true if the stack is equal to the max_size and false if it is not equal to max_size
 */

template<typename T, int max_size>
bool Stack<T, max_size>::Full() const
{
    if (top_position_ == max_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif
