#include <cassert>
#include <sstream>
#include <string>
#include <vector>
#include <initializer_list>

#include "../lib/myStack.h"

#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"

// static constexpr std::initializer_list<Type> INIT = { 97, 98, 99, 100 };

// Default Constructor
TEMPLATE_TEST_CASE("myStack()", "", char, int, double) {
    myStack<TestType> test {};

    REQUIRE(test.isEmpty());
}

// Copy Constructor
TEMPLATE_TEST_CASE("myStack(const myStack& other)", "", char, int, double) {
    myStack<TestType> reference {};

    for (TestType val = 0; val != 11; ++val) {
        reference.push(val + 33);
    }

    myStack<TestType> test(reference);

    while (!reference.isEmpty()) {
        REQUIRE(reference.top() == test.top());
        reference.pop();
        test.pop();
    }
}

TEMPLATE_TEST_CASE("myStack& operator=(const myStack& rhs)", "", char, int, double) {
    myStack<TestType> reference {};
    myStack<TestType> test {};
    
    for (TestType val = 0; val != 11; ++val) {
        reference.push(val + 33);
        test.push(val + 34);
    }

    REQUIRE(test.top() != reference.top());

    test = reference;

    while (!test.isEmpty()) {
        REQUIRE(test.top() == reference.top());
        reference.pop();
        test.pop();
    }
}

TEMPLATE_TEST_CASE("~myStack()", "", char, int, double) {
        myStack<TestType> test{};

        REQUIRE_THROWS(test.top());

        for (TestType val = 0; val != 11; ++val) {
            test.push(val + 33);
        }

        REQUIRE_NOTHROW(test.top());

        test.~myStack();

        REQUIRE_THROWS(test.top());
}

TEMPLATE_TEST_CASE("void push(const Type& value)", "", char, int, double) {
    myStack<TestType> test {};

    REQUIRE_THROWS(test.top());

    for (TestType val = 0; val != 11; ++val) {
        REQUIRE_NOTHROW(test.push(val + 33));
        REQUIRE(test.top() == val + 33);
    }
}

TEMPLATE_TEST_CASE("void pop()","",char,int,double) {
    myStack<TestType> test{};

    for (TestType val = 0; val != 11; ++val) {
        test.push(val + 33);
    }

    for (TestType val = 11; val != 0; --val) {
        REQUIRE(test.top() == static_cast<TestType>(val + 32));
        test.pop();
    }
}

TEMPLATE_TEST_CASE("Type top() const","",char,int,double) {
    myStack<TestType> test {};

    REQUIRE_THROWS(test.top());

    for (TestType val = 0; val != 11; ++val) {
        test.push(val + 33);
        REQUIRE(test.top() == val + 33);
    }
}

TEMPLATE_TEST_CASE("bool isEmpty() const","",char,int,double) {
    myStack<TestType> test {};

    REQUIRE(test.isEmpty());

    test.push(33);

    REQUIRE(!test.isEmpty());

    test.pop();

    REQUIRE(test.isEmpty());
}