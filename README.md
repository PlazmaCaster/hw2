# CS 302 - 1003 Homework 2
<u>Name:</u> *Gildardo Haro* <br>

<u>Preferred Name:</u> *Quinn* <br>

<u>NSHE:</u> 50044653996 <br>

## How to build:
*If GNU Make is installed*:<br>

-   While in the ***/HW2*** directory, simply type `make` in the terminal and the program will be compiled & built in the ***/build*** directory.
    * Program name is by default: **hw2**
    * Compiler flags used: -std=c++20 -Wall -Wextra -pedantic -Wshadow -Wconversion -Werror=vla -Werror=old-style-cast -Werror=return-type -Werror=missing-declarations -Wno-deprecated-copy -g -Ilib

*IF GNU Make is not installed*:<br>

*   While in ***/HW2*** directory, run:<br>
    `g++ ./src/hw2.cpp -Ilib -o (program_name_optional)`

    * This will create the program in the ***/hw2*** directory instead of ***/build***

## How to Run:
Running the program is straight forward, When prompted, enter the relative path to the text file.

*   EXAMPLE: if you run the program from the ***/hw2*** directory and want to use the `L_input.txt` file:
    * `./resources/L_input.txt` 

* You can also just... move the file into your current directory

## Unit Tests:
Created my own unit tests to test myStack. If you'd like to see it run `make unit_test`.

* Uses "Catch2" test framework (included in ***/lib***)
* Tests is built in the ***/build*** director

## Cleaning Up:
(If GNU Make is installed): While in the ***/hw2*** directory, running `make clean` will delete the contents of the build folder.

## Contact Me:
If there are any issues with build/ any questions you can contact me (in order of most likely to see it):

* Discord: **plazmacaster**
* Email: **qharo@protonmail.com**
* Canvas
* Rebel Mail: **harog2@unlv.nevada.edu**

