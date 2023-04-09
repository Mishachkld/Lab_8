//
// Created by Mishach on 08.04.2023.
//
#pragma once

#include <vector>
#include <iostream>


namespace st {
    template<class T>
    class Stack {
    public:
        Stack(int size) {  // не имеет смысла
            try {
                sizeArray = size;
                stack_array.reserve(size);
            }
            catch (const std::bad_alloc &e) {
                std::cout << e.what() << std::endl;
            }
        }

        Stack(int size, T item) {  // в этом конструкторе больше смысла, т.к. мы чем-то забиваем массив
            try {
                sizeArray = size;
                for (int i = 0; i < sizeArray; i++)
                    stack_array.push_back(item);
            }
            catch (const std::bad_alloc &e) {
                std::cout << e.what() << std::endl;
            }
        }

        /*Stack() {
            sizeArray = SIZE;
            std::fill(stack_array->begin(), stack_array->end() + SIZE, nullptr);
        }*/

        Stack() {
            sizeArray = 0;
        }

        ~Stack() {
            //delete stack_array;
        }
        /// возвращает размер
        int size() {
            return sizeArray;
        }
        /// возвращает true или false
        bool empty() {
            bool result = true;
            if (sizeArray != 0)
                result = false;
            return result;
        }
        /// добавляем элемент в стек
        void push(const T &item) {
            try {
                sizeArray++;
                stack_array.push_back(item);
            }
            catch (const std::overflow_error &e) {
                std::cout << e.what() << std::endl;
            }
        }
        /// извлекаем элемент из стека
        void pop() {
            if (!empty()) {
                sizeArray--;
                stack_array.pop_back();
            } else
                throw std::out_of_range("pop exeption: man, stack is empty");
        }
        /// просто смотрим на элемент
        T &top() {
            if (!empty())
                return stack_array[sizeArray - 1];
            throw std::logic_error("top exeption: WTF maaan! stack is empty!");
        }

    private:
        std::vector<T> stack_array;
        int sizeArray;

        friend std::ostream &operator<<(std::ostream &out, const Stack st) {
            for (const T item: st.stack_array) {
                out << item << " ";
            }
            out << std::endl;
            return out;
        }
    };

} // st

