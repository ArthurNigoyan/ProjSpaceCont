#include <iostream>
#ifndef _INIT_CLASS_
#define _INIT_CLASS_
template <typename T>
class node 
{
	public:
		T m_data;
		node<T> *m_next;
		node<T> *m_prev;
	node();
	
};
template <typename T>
node<T>::node()
	{
		m_next=nullptr;
		m_prev=nullptr;
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
	T first_element();
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
			node<T> *prev;
			while(temp->m_next != nullptr)
			{
				prev=temp;
				//run on list 
				temp = temp->m_next;
			}
			temp->m_next=new_node;
			temp->m_prev=prev;
		}
	}
template <typename T>
void my_list<T>::pop_back()
	{
		
		//////////////
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
        } else 
		{
			// node<T>* temp = head->m_next;
			head = head->m_next;
			head->m_prev=nullptr;
		}
	}
template <typename T>	
void my_list<T>::print()
	{
		if(head == nullptr)
		{
            std::cout<<"print list is empty"<<std::endl;        
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
            std::cout<<"last---list is empty"<<std::endl;     
			val= nullptr;
        } else
		{
			node<T>* temp = head;
            while(temp != nullptr)
			{
				if (temp->m_next == nullptr) 
				{
					val= temp->m_data;
				}
				temp = temp->m_next;
            }
		}
		return val;
}
template <typename T>	
T my_list<T>::first_element()
{
	T val;
	if(head == nullptr)
		{
            std::cout<<"first---list is empty"<<std::endl;     
			val= nullptr;
        } else
		{
            val= head->m_data;
			
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
	T front();
	T back ();
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
T stack<T>::front ()
	{
		return my_list<T>::last_element();
	}
template <typename T>
T stack<T>::back ()
	{
		return my_list<T>::first_element();
	}
#endif