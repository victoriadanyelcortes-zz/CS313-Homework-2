#include <iostream>
#include <string>
#include "Stack.h"
#include <fstream>

bool is_digit(char c) {

}

double eval_prefix(std::string exp, Stack<double> stack) {
    double op1, op2;

    for(int i = 0; i < exp.size()-1; ++i) {
        if(is_digit(exp[i])) {
            if(!stack.check_full()) {
                stack.push(exp[i] - '0');
            }
        }
        else {

        }
    }

    return stack.top();
}

//choosing to read files from command line rather than open specific file
// doing this to create multiple input files and choose from the files
// sample input files are included with project submission
int main(int argc, char** argv) {
    //Question 2:
    // using prefix notation to use a stack as a calculator
    std::cout << "Question 2: " << std::endl;
    Stack<double> prefix(100);
    std::string expression;

    expression = "+9*26";
    std::cout << eval_prefix(expression,prefix) << std::endl;

    std::ifstream in_str;
    while(in_str >> expression) {
        eval_prefix(expression, prefix);
    }


    // Question 4:
    // using function to list all elements in the stack
    // using function to change element in stack based on its position
    std::cout << "Question 4: " << std::endl;
    int size;
    std::cout << "What size do you want the stack to be? ";
    std::cin >> size;
    Stack<int> stack_nums(size);
    Stack<std::string> stack_strings(size);

    for(int i = 1; i < size; ++i) {
        stack_nums.push(i);
        stack_strings.push(std::to_string(i));
    }

    //stack_nums.list_all_elements();




    std::cout << "Listing all elements of a stack filled with numbers:" << std::endl;

    return 0;
}
