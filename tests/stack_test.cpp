// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "../externals/catch2/catch.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include "carton.h"
#include "stack.h"

const int kMaxSize = 12;

//******************* int Stack ************************

TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type int.",
    "[constructor][size][int]") {
  Stack<int, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type int.",
    "[constructor][top][size][int]") {
  Stack<int, kMaxSize> stack(23);
  REQUIRE(stack.Size() == 1);
  REQUIRE(stack.Top() == 23);
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type int.",
    "[push][top][size][int]") {
  Stack<int, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
  stack.Push(95);
  REQUIRE(stack.Size() == 1);
  REQUIRE(stack.Top() == 95);
  stack.Push(78);
  REQUIRE(stack.Size() == 2);
  REQUIRE(stack.Top() == 78);
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type int.",
    "[push][top][size][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);

    REQUIRE(stack.Size() == i + 1);
    REQUIRE(stack.Top() == i);
  }
  REQUIRE_THROWS_AS(stack.Push(23), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type int.",
    "[pop][top][size][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);

    REQUIRE(stack.Size() == i + 1);
    REQUIRE(stack.Top() == i);
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    REQUIRE(stack.Top() == i);
    REQUIRE(stack.Pop() == i);
    REQUIRE(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type int.",
    "[pop][int]") {
  Stack<int, kMaxSize> stack;
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type int.",
    "[pop][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(i);
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type int.",
    "[full][int]") {
  Stack<int, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Full());
    stack.Push(i);
  }
  REQUIRE(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type int.",
    "[empty][int]") {
  Stack<int, kMaxSize> stack;
  REQUIRE(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(i);
    REQUIRE(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Empty());
    stack.Pop();
  }
  REQUIRE(stack.Empty());
}

//******************* string Stack ************************

TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type string.",
    "[constructor][size][string]") {
  Stack<std::string, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type string.",
    "[constructor][top][size][string]") {
  Stack<std::string, kMaxSize> stack("green");
  REQUIRE(stack.Size() == 1);
  REQUIRE(stack.Top() == "green");
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type std::string.",
    "[push][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
  stack.Push("green");
  REQUIRE(stack.Size() == 1);
  REQUIRE(stack.Top() == "green");
  stack.Push("blue");
  REQUIRE(stack.Size() == 2);
  REQUIRE(stack.Top() == "blue");
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type std::string.",
    "[push][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));

    REQUIRE(stack.Size() == i + 1);
    REQUIRE(stack.Top() == std::to_string(i));
  }
  REQUIRE_THROWS_AS(stack.Push("yellow"), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type std::string.",
    "[pop][top][size][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));

    REQUIRE(stack.Size() == i + 1);
    REQUIRE(stack.Top() == std::to_string(i));
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    REQUIRE(stack.Top() == std::to_string(i));
    REQUIRE(stack.Pop() == std::to_string(i));
    REQUIRE(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type std::string.",
    "[pop][string]") {
  Stack<std::string, kMaxSize> stack;
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type std::string.",
    "[pop][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(std::to_string(i));
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type std::string.",
    "[full][string]") {
  Stack<std::string, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Full());
    stack.Push(std::to_string(i));
  }
  REQUIRE(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type std::string.",
    "[empty][string]") {
  Stack<std::string, kMaxSize> stack;
  REQUIRE(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(std::to_string(i));
    REQUIRE(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Empty());
    stack.Pop();
  }
  REQUIRE(stack.Empty());
}


TEST_CASE(
    "Default constructor creates an Stack with size = 0 "
    "when stack is of type Carton.",
    "[constructor][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
}

TEST_CASE(
    "Non-default constructor creates a Stack with a single item, "
    "Top method returns item added, and Size method returns 1."
    "size 1, and top equal to item when stack is of type Carton.",
    "[constructor][top][size][carton]") {
  Stack<Carton, kMaxSize> stack(Carton(22, 7, 19.38));
  REQUIRE(stack.Size() == 1);
  Carton one(22, 7, 19.38);
  REQUIRE(fabs(stack.Top().Volume() - one.Volume()) < .1);
}

TEST_CASE(
    "Push method adds item to stack, increases size, and top is equal to added "
    "Top method returns top value, and Size method returns expected size "
    "item when stack is of type Carton.",
    "[push][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  REQUIRE(stack.Size() == 0);
  stack.Push(Carton(16, 8, 20));
  REQUIRE(stack.Size() == 1);

  Carton one(16, 8, 20);
  REQUIRE(fabs(stack.Top().Volume() - one.Volume()) < .1);
  stack.Push(Carton(8, 20, 9.54));
  REQUIRE(stack.Size() == 2);

  Carton two(8, 20, 9.54);
  REQUIRE(fabs(stack.Top().Volume() - two.Volume()) < .1);
}

TEST_CASE(
    "Push method throws out_of_range exception when called after stack is full "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type Carton.",
    "[push][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(14, i + 7, 12));
    Carton two;
    REQUIRE(stack.Size() == i + 1);
    two = Carton(14, i + 7, 12);
    REQUIRE(fabs(stack.Top().Volume() - two.Volume()) < .1);
  }
  REQUIRE_THROWS_AS(stack.Push(Carton(14, 9.6, 12)), std::out_of_range);
}

TEST_CASE(
    "Pop method returns top value, and reduces size of stack "
    "Top method returns top value, and Size method returns expected size "
    "when stack is of type Carton.",
    "[pop][top][size][carton]") {
  Stack<Carton, kMaxSize> stack;
  Carton two;
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(20.8, i + 7, 14.2));

    REQUIRE(stack.Size() == i + 1);
    two = Carton(20.8, i + 7, 14.2);
    REQUIRE(fabs(stack.Top().Volume() - two.Volume()) < .1);
  }
  for (int i = kMaxSize - 1; i > -1; i--) {
    two = Carton(20.8, i + 7, 14.2);
    REQUIRE(fabs(stack.Top().Volume() - two.Volume()) < .1);
    REQUIRE(fabs(stack.Pop().Volume() - two.Volume()) < .1);
    REQUIRE(stack.Size() == i);
  }
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is  "
    "empty (just created) when stack is of type Carton.",
    "[pop][carton]") {
  Stack<Carton, kMaxSize> stack;
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Pop method throws out_of_range exception when stack is "
    "empty (Push and Pop used) when stack is of type Carton.",
    "[pop][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < 5; i++) {
    stack.Push(Carton(i + 7, 7.8, 19.3));
  }
  for (int i = 0; i < 5; i++) {
    stack.Pop();
  }
  REQUIRE_THROWS_AS(stack.Pop(), std::out_of_range);
}

TEST_CASE(
    "Full method returns true when stack is full and false when it is not full "
    "when stack is of type Carton.",
    "[full][carton]") {
  Stack<Carton, kMaxSize> stack;
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Full());
    stack.Push(Carton(i + 7, 7.8, 19.3));
  }
  REQUIRE(stack.Full());
}

TEST_CASE(
    "Empty method returns true when stack is empty and false when it is not "
    "empty when stack is of type Carton.",
    "[empty][carton]") {
  Stack<Carton, kMaxSize> stack;
  REQUIRE(stack.Empty());
  for (int i = 0; i < kMaxSize; i++) {
    stack.Push(Carton(i + 7, 7.8, 19.3));
    REQUIRE(!stack.Empty());
  }
  for (int i = 0; i < kMaxSize; i++) {
    REQUIRE(!stack.Empty());
    stack.Pop();
  }
  REQUIRE(stack.Empty());
}
