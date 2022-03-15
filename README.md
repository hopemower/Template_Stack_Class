# TRY-IT-OUT: THE TEMPLATE STACK CLASS 

---

A stack is a widely used data structure. It stores data by adding new elements
at the top of the stack. It allows access to only the top element in the stack.
And when you remove an element, it removes the top element. All the action
happens at the top of the stack.

You can think of it like a stack of plates. When you want one plate, you take
the top one. When you add a new plate to the stack, you add it to the top
of the stack. When you look at the stack of plates it is mostly the top one
that you see.

Because we might want to have stacks that hold different types, we will create
a template stack class. Then we will test it with ints, strings, and Cartons.


---
### Files to work on
We will be working in the following files.

- There is a header file `src/stack.h` where we will write the 
   template Stack class.
- There is a library `carton` that contains the carton class. The library 
  consists of these two files:
  - `src/carton.cpp`
  - `src/carton.h`
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying other files may result 
            in the unit tests not passing.

---

## Part 1: Begin the Template Stack Class

The `Stack` class is a template class so that it can be used with a 
variety of types. It needs a private data member to store the values. 

Note: The instructions 
use an array but all the storing and retrieving of the values is internal
to the class so it does not need to be an array. If there is another type
of data structure that you are confident working with, you may use it. You 
will need to adapt the data members and methods to work with this other 
data structure. 

1. In the `stack.h` file begin the `Stack` class.
- the include guard is already in the stack.h header file
- add the template header that includes two parts
  - the variable type
  - an int that specifies the maximum size of the Stack
- add the class named Stack
- add two private data members
   - an array to hold the items in the stack
        - use a C++ container array
        - the type will be the variable type 
        - the size will be the maximum size  
   - an int to keep track of the index of the top of the Stack 
- add a public section with the following method declarations
  - Stack();
  - Stack(T item);
  - ~Stack();
  - void Push(T item);
  - T Pop();
  - T Top() const;
  - int Size() const;
  - bool Empty() const;
  - bool Full() const;

2. Write the implementation for the default constructor. This constructor 
   initializes the top to 0. 
   
   Remember to put the template header above this method definition and to add 
   the name of the class followed by the template types before the name of the
   method. Remember this each time you add a method implementation outside 
   the class declaration.
   
   Also, remember to keep the function implementations in the .h file.

3. Write the implementation of Push method. This method adds the item to the 
   top of the stack and changes the variable 
   that is keeping track of the top.
   If the stack is full when Push is called, there is no place to put another 
   item in the stack.
   When this happens, throw an out_of_range exception.   
   Include an exception message that explains the exception.

    When you are creating this, you might want to print the array and the 
    top position so 
    you can see how it is changing.

4. Now you can write the other constructor. This constructor needs to 
   initialize the top to 0 and call the Push method to add the one item sent.

6. Write the destructor. It does not need to do anything. Just add the {}s

---

## Part 2: The Pop and Top Methods 

A stack removes items from the top of the stack. The method that does this is 
the Pop method. 

You can also see the value at the top of the stack without making any changes
to the stack. The Top method does this.

1. Write the Pop method. This method does two things. It moves the top down one 
   and returns the item 
   at the top of the stack. (Be careful about order
   on this one. Once you return from a method, nothing else happens. So the 
   return statement has to be last.)

   If the stack is empty when Pop is called, throw an out_of_range exception.   
   Include an exception message that explains the exception.

   Notice how the item is actually still sitting in the array. However, 
   since the top has changed, we will not see it.


2. Write the Top method. This method returns the item at the top of the stack.
   If the stack is empty when Top is called, throw an out_of_range exception. 
   Include an exception message that explains the exception.

---


## Part 3: The Size, Empty, and Full Methods

1. Write the Size method. This method returns how many items are 
   currently in the stack.

2. Write the Empty method. This method returns true when the stack is 
   empty. When there are items in the stack, it returns false.

3. Write the Full method. This method returns true when the stack is 
   full. When there is still room for additional items in the stack, it 
   returns false.



---

## Part 4: Demonstrate Using the Stack Class

The unit tests will test Stack objects using int, string, and Carton objects.
Demonstrate how to create and use Stack objects with two of these types. You 
can pick which two types to demonstrate.

In `main.cpp` create two Stack objects with different types. 


For each Stack do the following.

 - Define a Stack object. Make it small, a maximum size of 3-6, so we can
 see it get full and empty.
 - Use Push to fill up the stack, then Push one more time
   - Handle the exception by using a try/catch block. 
   - When an exception 
       occurs, print the exception message to the screen
 - Print out the following information about the Stack
    - size of Stack
    - value at the top of the Stack
        - This can potentially throw an exception. Handle this by using
              a try/catch block to handle the exception.
         - When an exception 
             occurs, print the exception message to the screen
         - For Cartons, use the WriteCarton method to print the value
 - Use Pop to remove all the items from the Stack.
    - This can potentially throw an exception. Use the Empty method
     to prevent an exception. 
    - Print each value as it is popped.
 - Print out the following information about the Stack
    - size of Stack
    - value at the top of the Stack
        - This can potentially throw an exception. Handle this by using
              a try/catch block to handle the exception.
        - When an exception 
             occurs, print the exception message to the screen
        - For Cartons, use the WriteCarton method to print the value
 
Notice how we are using two different methods for handling the exceptions. 
One way prevents the exception (when we call Pop) and the other
handles the exception (when we call Push and Top). This give us experience using
both these approaches.
     
---
     
## Validate your code

Once you are satisfied with your work, run the unit test file:

From the dropdown select main_test and run.

Sample output:

Tests passed: 27 of 27 tests

---

## Submit your code

Zip your src folder and submit in Canvas.

---
