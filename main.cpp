#include <iostream>
#include <string>
#include "Stack.h"


double eval_prefix(std::string exp) {

    Stack<double> stack;
    double op1, op2;

    for(int i = exp.size()-1; i >= 0; i--) {
        if(isdigit(exp[i])) {
            stack.push(exp[i] - '0');
        }
        else {
            op1 = stack.top();
            stack.pop();

            if(stack.check_empty()) {
                std::cout << "No operations"  << std::endl;
            }
            else {
                op2 = stack.top();
                stack.pop();

                switch (exp[i]) {
                    case '+':
                        stack.push(op1 + op2);
                        break;
                    case '-':
                        stack.push(op1 - op2);
                        break;
                    case '*':
                        stack.push(op1 * op2);
                        break;
                    case '/':
                        stack.push(op1 / op2);
                        break;
                }
            }
        }
    }
    return stack.top();
}

int main(int argc, char** argv) {
    //Question 2:
    // using prefix notation to use a stack as a calculator
    std::cout << "Question 2: " << std::endl;
    std::string expression;
    // choosing to just use a  few sample strings to demonstrate functionality
    expression = "+9*26";
    std::cout << expression << "= " << eval_prefix(expression) << std::endl;
    expression = "+85";
    std::cout << expression << "= " << eval_prefix(expression) << std::endl;
    expression = "+4*2+78";  // should be
    std::cout << expression << "= " << eval_prefix(expression) << std::endl;
    expression = "+9*6/24";  // should be 12
    std::cout << expression << "= " << eval_prefix(expression) << std::endl;


    //Question 4:
    // using function to list all elements in the stack
    // using function to change element in stack based on its position
    std::cout << "Question 4: " << std::endl;
    int size;
    std::cout << "What size do you want the stack to be? ";
    std::cin >> size;
    Stack<int> stack_nums(size);

    for(int i = 1; i < size+1; ++i) {
        stack_nums.push(i);
    }

    stack_nums.list_all_elements();
    stack_nums.change_element_value();

    return 0;
}
