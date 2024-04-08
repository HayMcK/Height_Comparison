// #include "MonoStack.h"

// template <typename T>
// MonoStack<T>::MonoStack(){
//     mSize = 64; // default stack size
//     top = -1;
//     myArray = new T[mSize];
// }

// template <typename T>
// MonoStack<T>::MonoStack(int maxSize){
//     mSize = maxSize;
//     top = -1;
//     myArray = new T[mSize];

// }

// template <typename T>
// MonoStack<T>::~MonoStack(){
//     delete[] myArray;
// }

// template <typename T>
// void MonoStack<T>::push(const T &data){
//     //check if stack is full
//     if (isFull()){
//         T *temp = new T[2*mSize];
//         for(int i = 0; i< mSize; ++i){
//             temp[i] = myArray[i];//copy from old array to new array
//         }
//         mSize *= 2; //mSize = mSize * 2
//         delete[] myArray;
//         myArray = temp;
//     }
//     myArray[++top] = data;
// }

// template <typename T>
// T MonoStack<T>::pop(){
//     //check if empty
//     if (isEmpty()){
//         throw std::runtime_error("stack is empty, nothing to pop");
//     }
//     return myArray[top--];
// }

// template <typename T>
// T MonoStack<T>::peek() const{
//     //check if empty
//     if (isEmpty()){
//         throw std::runtime_error("stack is empty, nothing to peek");
//     }
//     return myArray[top];
// }

// template <typename T>
// bool MonoStack<T>::isEmpty(){
//     return (top == -1);
// }

// template <typename T>
// bool MonoStack<T>::isFull(){
//     return (top == mSize-1);
// }

// template <typename T>
// int MonoStack<T>::getSize(){
//     return top+1;
// }