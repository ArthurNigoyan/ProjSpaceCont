#include <iostream>
#ifndef _INIT_CLASS_
#define _INIT_CLASS_
template <typename T>
class node 
{
	public:
		T m_data;
		node<T> *m_next;
	node();
	
};
template <typename T>
node<T>::node()
	{
		m_next=nullptr;
	}

template <typename T>
class my_list 
{
	public:
		node<T> *head;
	my_list();
	void push_back(T value);
	void pop_back();
	void print();
	T last_element();
};
template <typename T>
my_list<T>::my_list()
	{
		head=nullptr;
	}
template <typename T>
void my_list<T>::push_back(T value)
	{
		node<T> *new_node=new node<T>[1];
		new_node->m_data=value;
		if (head==nullptr)
		{
			//if list is empty
			head=new_node;
		} else {
			//if list isn't empty
			node<T> *temp=head;
			while(temp->m_next != nullptr)
			{
				//run on list 
				temp = temp->m_next;
			}
			temp->m_next=new_node;
		}
	}
template <typename T>
void my_list<T>::pop_back()
	{
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
        } else if (head->m_next == nullptr) 
		{
			head=nullptr;			
		} else 
		{
			node<T>* temp = head;
            while(temp != nullptr)
			{
				if (temp->m_next->m_next == nullptr) 
				{
					temp->m_next=nullptr;
				}
				temp = temp->m_next;
            }
		}
	}
template <typename T>	
void my_list<T>::print()
	{
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
        } else 
		{
			node<T>* temp = head;
            while(temp != nullptr)
			{
                std::cout<<temp->m_data<<" | ";
                temp = temp->m_next;
            }
		}  
	}
template <typename T>	
T my_list<T>::last_element()
{
	T val;
	if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;     
			val= nullptr;
        } else
		{
			// node<T>* temp = head;
            while(head != nullptr)
			{
				if (head->m_next == nullptr) 
				{
					val= head->m_data;
				}
				head = head->m_next;
            }
		}
		return val;
}
template <typename T>
class stack : private my_list<T> 
{
	
	public:
	
	void push(T data);
	void pop();
	void printstack ();
	T top();
};
template <typename T>
void stack<T>::push(T data)
	{
		my_list<T>::push_back(data);
		
	}
template <typename T>
void stack<T>::pop()
	{
		my_list<T>::pop_back();
	}
template <typename T>
void stack<T>::printstack ()
	{
		my_list<T>::print();
	}
template <typename T>
T stack<T>::top ()
	{
		return my_list<T>::last_element();
	}
#endif