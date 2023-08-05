#include <iostream>
#include <stdlib.h>
#include "stack.h"


// template <typename T>
// class array
// {
	// private:
		// int m_size;
		// T* m_ptr;
	// public:
	// array()
	// {
		// m_ptr = new T[1];
	// m_size=1;
		// std::cout<<"array constructor"<<std::endl;
	// }
	// array(array &obj)
	// {
		// this->m_size=obj.m_size;
		// this->m_ptr=new T[m_size];
		// for (int i=0;i<m_size;i++)
		// {
			// this->m_ptr[i] = obj.m_ptr[i];
		// }
		// std::cout<<"array copy constructor"<<std::endl;
	// }
	// array& operator=(array& obj)
	// {
		// if (this==&obj)
		// {
			// return *this;
		// }
		// delete []m_ptr;
		// this->m_size=obj.m_size;
		// this->m_ptr=new int[m_size];
		// for (int i=0;i<m_size;i++)
		// {
			// this->m_ptr[i] = obj.m_ptr[i];
		// }
		// std::cout<<"operator assignment for array"<<std::endl;
		// return *this;
	// }
	// array(array&& obj)
	// {
		// this->m_size=obj.m_size;
		// this->m_ptr=obj.m_ptr;
		// obj.m_ptr=nullptr;
		// obj.m_size = 0;
		// std::cout<<"array move constructor"<<std::endl;
	// }
	// array&& operator=(array&& obj)
	// {
		// if (this==&obj)
		// {
			// return std::move(*this);
		// }
		// delete []m_ptr;
		// this->m_size=obj.m_size;
		// this->m_ptr=obj.m_ptr;
		// obj.m_ptr=nullptr;
		// obj.m_size = 0;
		// std::cout<<"array move operator assignment"<<std::endl;
		// return std::move(*this);
	// }
	// ~array()
	// {
		// delete []m_ptr;
		// std::cout<<"array destructor"<<std::endl;
	// }
	// void print_array()
	// {
		// for (int i=0; i<m_size;i++)
		// {
			// std::cout<<m_ptr[i]<<" ";	
		// }
		// std::cout<<std::endl;
	// }
	// void push_back(T need_add)
	// {
        // T* m_ptr1 = new T[this->m_size+1];
        // for (int i = 0; i < this->m_size; i++) {
			// m_ptr1[i] = m_ptr[i];
        // }
        // delete[] m_ptr;
        // this->m_ptr = m_ptr1;
		// this->m_size++;
        // this->m_ptr[this->m_size-1] = need_add;
		
	// }
	// void pop_back()
	// {
		
		// this->m_size--;
        
	// }
// };


// template <typename T>
// class stack : private array<T> 
// {
	// public:
	
	// void push(T data)
	// {
		// array<T>::push_back(data);
	// }
	// void pop()
	// {
		// array<T>::pop_back();
	// }
	// void print ()
	// {
		// array<T>::print_array();
	// }
// };


int main()
{
	stack<std::string> obj6;
	obj6.push("kuku");
	obj6.push("didi");
	obj6.push("guru");
	obj6.print();
	obj6.pop();
	obj6.print();
	std::cout<<obj6.top()<<std::endl;;

	return 0;
}