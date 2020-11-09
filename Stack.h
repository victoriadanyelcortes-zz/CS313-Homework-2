#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H

#include <random>

template <typename T> class Stack {
    // set member variables
    int max_size;
    int stack_top;
    T* elements;

public:
   explicit Stack(int size) {
       // set max size to the given size, and create
       // array of that size, if the given size
       // is less than 0, use the default of 100
       if(size > 0) {
           max_size = size;
           stack_top = 0;
           elements = new T[max_size];
       } else {
           max_size = 100;
           stack_top = 0;
           elements = new T[max_size];
       }
    }

    Stack() {
       // no argument constructor, sets
       // everything to the default size of 100
       max_size = 100;
       stack_top = 0;
       elements = new T[max_size];
   }

    ~Stack() {
       // destructor
        delete [] elements;
    }

    void initialize() {
        stack_top = 0;
    }

    T top() {
       // return the value at the top of the stack
        return elements[stack_top - 1];
   }

    void push(T item) {
       if(check_full()) {
           // if the stack is full, nothing can be pushed
           std::cout << "Stack is full, cannot push any more elements" << std::endl;
       } else {
           // add the new value to the top of the stack
           elements[stack_top] = item;
           stack_top++;
       }
    }

    void pop() {
        if(!check_empty()){
            // decrease the stack top
            stack_top--;
        }
        else {
            std::cout << "Stack is empty, cannot remove from empty stack." << std::endl;
        }

    }

    bool check_empty() {
       // return true if empty
        return(stack_top == 0);
    }

    bool check_full() {
       // return true if full
        return (stack_top == max_size);
    }

    class Itr {
       friend class Stack<T>;
       T* ptr;

    public:
       using self_type = Itr;
       using iterator_category = std::forward_iterator_tag;
       using value_type = T;
       using difference_type = int;
       using pointer = T*;
       using reference = T&;

       explicit Itr() :ptr(nullptr) {}

       explicit Itr(T* p) :ptr(p) {}

       bool operator==(const Itr& rhs) {
           return ptr == rhs.ptr;
       }

       bool operator!=(const Itr& rhs) {
           return ptr != rhs.ptr;
       }

       reference operator*() {
           return *ptr;
       }

       self_type operator++() {
          ptr++;
          return *this;
       }

//       self_type operator++(int junk) {
//           Itr temp(*this);
//           ++*this;
//           return temp;
//       }

   };

   Itr begin() {
       return Itr(elements);
   }

   Itr end() {
       return Itr(elements+max_size);
   }

   void list_all_elements() {
       // iterate thru the list and print every value
      for( int i = 0; i < max_size; ++i) {
          std::cout << elements[i] << std::endl;
      }
   }

   void change_element_value() {
       // using random number generator to get a random position in the stack
       std::random_device rd;
       std::mt19937 bl(rd());
       std::uniform_int_distribution<int> int_dist(0, stack_top);
       int pos_to_change = int_dist(bl);

       T changed_val;
       T old_val;
       // iterating thru the list to come up with a way to change the value
       for(int i = 0; i < pos_to_change; ++i) {
           // add all values up to the changed value to create a unique value
           changed_val += elements[i];

           // set position in stack to changed value
           if(i == pos_to_change-1) {
               old_val = elements[i+1];
               elements[i+1] = changed_val;
           }
       }

       // print changed postion and new value
       std::cout << "Changed postition: " << pos_to_change << std::endl;
       std::cout << "Previous Value: " << old_val << " Changed value: " << changed_val << std::endl;
   }

};

#endif //STACK_QUEUE_STACK_H
