# CS313-Homework-2
Solutions written by Victoria Cortes for Homework 2.

# Question 1 Approach
Since this question only involved commenting code, I basically just traced each function in my head, or by hand if I felt it was more interesting, and then wrote down
the functionality of each line. 

# Quesiton 2 Approach
For this, I decided that my function that evaluated each prefix statement should have one parameter that would be the expression as a string. At that point, I actually
loop through the expression starting at the end and handle each operator by case, and push the result of each operation to the stack. By the end of all the calculations,
the result is stored in the stack top, so I just returned stack top to give the final answer in the main function. 

# Question 4 Approach
Since I began my stack implementation with this question rather than question 2, this is where the bulk of that work lies. 
I used a pretty standard stack implementation, with two constructors, one that required the size, and one default that
set size to 100 automatically. When it came to listing all elements in the stack, I just did it by using a for loop and printing
each item in the stack. As for changing the value based on position, I decided it would be fun to use c++11 random
library to generate a random position in the stack, after that is generated, I decided to iterate through the stack and
add each preceeding value, and set that total value equal to the position. At the end, I decided to print the 
position changed as well as the new value, which I was able to do by creating variable to store those values without
having to iterate through the list again. 

# Conclusion
Since stacks work very similarly to std::vector, these questions could have been implemented usisng a vector, which
could have saved time if implemented usisng std::vector instead of creating a vector ADT. But, implementing a stack 
was interesting especially when comparing the array implementation I chose to do with the linked list implementation
in the text file, as it was fun to see the different functionality of each. Overall, Stacks are an important structure, and 
the calculator functionality gives a small taste of what they can do. 
