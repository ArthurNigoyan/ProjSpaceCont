#include <iostream>
#ifndef _INIT_CLASS1_
#define _INIT_CLASS1_
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
	T* begin ();
	T* end ();
	void sort();
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
                std::cout<<temp->m_data<<" ";
                temp = temp->m_next;
            }
		}  
		std::cout << std::endl;
	}
template <typename T>
	T* my_list<T>::begin ()
	{
		node<T>* mm1_ptr=head;
		
		return mm1_ptr;
	}
template <typename T>
	T* my_list<T>::end ()
	{
		node<T>* mm1_ptr=head;
            while(mm1_ptr != nullptr)
			{
                
                mm1_ptr = mm1_ptr->m_next;
            }
		return mm1_ptr;
	}
template <typename T>
void my_list<T>::sort ()
{
	node<T>* curr=head;
	node<T>* curr1=head;
	bool finished ;
	while (1)
	{
		finished = false;
	while (head->m_next!=nullptr)
	{
		if (head->m_data > head->m_next->m_data)
		{
			std::swap(head->m_data,head->m_next->m_data);
			finished = true;
		}
		head=head->m_next;
	}
	if (finished == false)
	{
		break;
	} else {
		head=curr->m_next;
	}
	}
	head=curr1;
}
#endif