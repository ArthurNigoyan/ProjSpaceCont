#include <iostream>
#ifndef _INIT_CLASS_
#define _INIT_CLASS_
template <typename T>
class array
{
	private:
		int m_size;
		T* m_ptr;
	public:
	array();
	array(array &obj);
	array& operator=(array& obj);
	array(array&& obj);
	array&& operator=(array&& obj);
	~array();
	void print_array();
	void push_back(T need_add);
	void pop_back();
	T last_element();
};
template <typename T>
array<T>::array()
	{
		m_ptr = new T[1];
	m_size=1;
		std::cout<<"array constructor"<<std::endl;
	}
template <typename T>
array<T>::array(array &obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=new T[m_size];
		for (int i=0;i<m_size;i++)
		{
			this->m_ptr[i] = obj.m_ptr[i];
		}
		std::cout<<"array copy constructor"<<std::endl;
	}
template <typename T>
array<T>& array<T>::operator=(array& obj)
	{
		if (this==&obj)
		{
			return *this;
		}
		delete []m_ptr;
		this->m_size=obj.m_size;
		this->m_ptr=new int[m_size];
		for (int i=0;i<m_size;i++)
		{
			this->m_ptr[i] = obj.m_ptr[i];
		}
		std::cout<<"operator assignment for array"<<std::endl;
		return *this;
	}
template <typename T>
array<T>::array(array&& obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		obj.m_size = 0;
		std::cout<<"array move constructor"<<std::endl;
	}
template <typename T>
array<T>&& array<T>::operator=(array&& obj)
	{
		if (this==&obj)
		{
			return std::move(*this);
		}
		delete []m_ptr;
		this->m_size=obj.m_size;
		this->m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		obj.m_size = 0;
		std::cout<<"array move operator assignment"<<std::endl;
		return std::move(*this);
	}
template <typename T>
array<T>::~array()
	{
		delete []m_ptr;
		std::cout<<"array destructor"<<std::endl;
	}
template <typename T>
void array<T>::print_array()
	{
		for (int i=0; i<m_size;i++)
		{
			std::cout<<m_ptr[i]<<" ";	
		}
		std::cout<<std::endl;
	}
template <typename T>
void array<T>::push_back(T need_add)
	{
        T* m_ptr1 = new T[this->m_size+1];
        for (int i = 0; i < this->m_size; i++) {
			m_ptr1[i] = m_ptr[i];
        }
        delete[] m_ptr;
        this->m_ptr = m_ptr1;
		this->m_size++;
        this->m_ptr[this->m_size-1] = need_add;
		
	}
template <typename T>
void array<T>::pop_back()
	{
		
		this->m_size--;
        
	}
template <typename T>
T array<T>::last_element()
	{
		
		return this->m_ptr[m_size-1];
        
	}

template <typename T>
class stack : private array<T> 
{
	private:
		T top_val;
	public:
	
	void push(T data);
	void pop();
	void print ();
	T top();
};
template <typename T>
void stack<T>::push(T data)
	{
		array<T>::push_back(data);
		top_val=data;
	}
template <typename T>
void stack<T>::pop()
	{
		array<T>::pop_back();
	}
template <typename T>
void stack<T>::print ()
	{
		array<T>::print_array();
	}
template <typename T>
T stack<T>::top ()
	{
		return this->last_element();
	}
#endif