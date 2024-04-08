#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
#include <exception>

template<typename T>
class MonoStack{
    public:
        MonoStack();
        MonoStack(int maxSize); 
        ~MonoStack(); 

        void push(const T &data);
        T pop();
        T peek();

        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        T *myArray;
        int top;
        int mSize;
};

//Default Constructor
template <typename T>
MonoStack<T>::MonoStack(){
    mSize = 64; // default stack size
    top = -1;
    myArray = new T[mSize];
}
//Overloaded Constructor
template <typename T>
MonoStack<T>::MonoStack(int maxSize){
    mSize = maxSize;
    top = -1;
    myArray = new T[mSize];

}

//Destructor
template <typename T>
MonoStack<T>::~MonoStack(){
    delete[] myArray;
}

//Push function to push a new value onto the stack
template <typename T>
void MonoStack<T>::push(const T &data){
    //check if stack is full
    if (isFull()){
        T *temp = new T[2*mSize];
        for(int i = 0; i< mSize; ++i){
            temp[i] = myArray[i];//copy from old array to new array
        }
        mSize *= 2; //mSize = mSize * 2
        delete[] myArray;
        myArray = temp;
    }
    myArray[++top] = data;
}

//Pop function to remove and return top value
template <typename T>
T MonoStack<T>::pop(){
    //check if empty
    if (isEmpty()){
        throw std::runtime_error("stack is empty, nothing to pop");
    }
    return myArray[top--];
}

//Peek function to view the top value without removing it
template <typename T>
T MonoStack<T>::peek(){
    //check if empty
    if (isEmpty()){
        throw std::runtime_error("stack is empty, nothing to peek");
    }
    return myArray[top];
}

//Function to check if the stack is empty
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (top == -1);
}

//Function to check if the stack reached max size
template <typename T>
bool MonoStack<T>::isFull(){
    return (top == mSize-1);
}

//Function to get the size of the stack
template <typename T>
int MonoStack<T>::getSize(){
    return top+1;
}

#endif