#include <iostream>
#include <string>
#include "stack.h"
#include "carton.h"

const int kMaxSize = 12;
using namespace std;

int main() {

    // Part 4, First Stack Type
    cout << "Part 4\nFirst Stack\n";

    // Define a Stack object. Make it small, a maximum size of 3-6
    Stack<int, 6> one;

    // Use Push to fill up the stack, then Push one more time
    // Handle the exception by using a try/catch block. When an exception
    // occurs, print the exception message to the screen
    try
    {
        one.Push(345);
        one.Push(323);
        one.Push(234);
        one.Push(451);
        one.Push(212);

    } catch(out_of_range e)
    {
        cout << e.what() << endl;
    }

    cout << "After exception" << endl;
    cout << "Item at the top: " << one.Top() << endl;

    if(one.Full())
    {
        cout << "Too full\n";
    } else
    {
        one.Push(345);
    }

    //  Print out the following information about the Stack
    //  size of Stack
    //  value at the top of the Stack. Handle this by using a try/catch block
    //  When an exception occurs, print the exception message to the screen
    cout << "Size of stack: " << one.Size() << endl;

    try
    {
        one.Push(345);
        one.Push(355);
        one.Push(445);

    } catch(out_of_range e)
    {
        cout << e.what() << endl;
    }
    cout << "Top of Stack: " << one.Top() << endl;


    //  Use Pop to remove all the items from the Stack. Use the Empty method
    //  to prevent an exception. Print each value as it is popped.

    try
    {
        cout << "New top value: " << one.Pop() << endl;
        cout << "New top value: " << one.Pop() << endl;
        cout << "New top value: " << one.Pop() << endl;
        cout << "New top value: " << one.Pop() << endl;
        cout << "New top value: " << one.Pop() << endl;

    } catch(out_of_range e)
    {
        cout << e.what() << endl;
    }

    if (one.Empty()) {
        cout << "The stack is empty, no item to show\n";
    }

    //  Print out the following information about the Stack
    //  size of Stack
    //  value at the top of the Stack. Handle this by using a try/catch block
    //  When an exception occurs, print the exception message to the screen


    // Part 4, Second Stack Type
    cout << "Part 4\n\nSecond Stack\n";

    // Define a Stack object. Make it small, a maximum size of 3-6
    Stack<double, 4> double_stack;

    // Use Push to fill up the stack plus one additional Push
    // Handle the exception by using a try/catch block to handle the exception.

    try
    {
        double_stack.Push(13.1);
        double_stack.Push(133.1);
        double_stack.Push(134.1);

    } catch(out_of_range e)
    {
        cout << e.what() << endl;
    }

    if (one.Empty()) {
        cout << "The stack is empty, no item to show\n";
    }

    //  Print out the following information about the Stack
    //  size of Stack
    //  value at the top of the Stack. Handle this by using a try/catch block
    cout << "Size of stack: " << double_stack.Size() << endl;
    try
    {
        double_stack.Top();
    } catch(out_of_range e)
    {
        cout << "Top of stack: " << double_stack.Top() << endl;
        cout << e.what() << endl;
    }


    //  Use Pop to remove all the items from the Stack. Use the Empty method
    //  to prevent an exception. Print each value as it is popped.
    cout << "Value of current item: " << double_stack.Pop() << endl;
    cout << "Value of current item: " << double_stack.Pop() << endl;
    cout << "Value of current item: " << double_stack.Pop() << endl;


    //  Print out the following information about the Stack
    //  size of Stack
    //  value at the top of the Stack. Handle this by using a try/catch block


    try {
        if(double_stack.Empty())
        {
            double_stack.Push(123.4);
        }
    } catch (out_of_range e) {
        cout << e.what() << endl;
    }
    cout << "Size of stack: " << double_stack.Size() << endl;
    cout << "Top of stack: " << double_stack.Top() << endl;

//    Stack<Carton, kMaxSize> stack_carton;
//
//    try {
//        for (int i = 0; i < kMaxSize; i++) {
//            if (!stack_carton.Full()) {
//                stack_carton.Push(Carton(i + 7, 7.8, 19.3));
//            }
//        }
//    } catch(out_of_range e)
//    {
//        cout << e.what() << endl;
//    }
//
//    Carton ones(22, 7, 19.38);
//
//    cout << "Size of Carton stack: " << stack_carton.Size() << endl;
//    cout << "Top of Carton stack: ";
//    stack_carton.Top();
//    ones.WriteCarton(cout);
//    cout << endl;
//
//    //testing non default constructor
//    Stack<int, kMaxSize> stacks(23);
//
//    cout << "Top of stacks: " << stacks.Top() << endl;
//    cout << "Current Size of stacks: " << stacks.Size() << endl;


    return 0;
}