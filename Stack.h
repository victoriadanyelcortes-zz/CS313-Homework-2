#ifndef STACK_QUEUE_STACK_H
#define STACK_QUEUE_STACK_H

#include <random>

template <typename T> class Stack {
    int max_size;
    int stack_top;
    T* elements;

public:
   explicit Stack(int size) {
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

    ~Stack() {
        delete [] elements;
    }

    void initialize() {
        stack_top = 0;
    }

    T top() {
        return stack_top;
   }

    void push(const T& item) {
       if(check_full()) {
           std::cout << "Stack is full, cannot push any more elements" << std::endl;
       } else {
           elements[stack_top] = item;
           stack_top++;
       }
    }

    void pop() {
        if(!check_empty()){
            max_size--;
        }
        else {
            std::cout << "Stack is empty, cannot remove from empty stack." << std::endl;
        }

    }

    bool check_empty() {
        return(stack_top == 0);
    }

    bool check_full() {
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

       //explicit Itr() :ptr(nullptr) {}

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
       Itr it(elements);
       for(it = elements.begin(); it!= elements.end(); ++it) {
          std::cout << *it << std::endl;
      }
//      for( int i = 0; i < max_size; ++i) {
//          std::cout << elements[i] << std::endl;
//      }
   }

   void change_element_value() {
       // using random number generator to get a random position in the stack
       std::random_device rd;
       std::mt19937 bl(rd());
       std::uniform_int_distribution<int> int_dist(0, stack_top);
       int pos_to_change = int_dist(bl);

       // iterating thru the list to come up with a way to change the value
       for(int i = 0; i < pos_to_change; ++i) {
           if(pos_to_change < stack_top/2) {

           } else {

           }
       }

       // set position to that value
       elements[pos_to_change];
   }

};

#endif //STACK_QUEUE_STACK_H
