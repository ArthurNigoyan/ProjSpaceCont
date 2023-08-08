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
	void reverse();
	bool check_cycle();
	T findN(int n);
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
	}
template <typename T>
void my_list<T>::reverse()
	{
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
        } else 
		{
			stack<T> obj;
			node<T>* curr = head;
            while(head != nullptr)
			{
				obj.push(head->m_data);
				head = head->m_next;
            }
			head=curr;
			while(head != nullptr)
			{
				head->m_data=obj.top();
				obj.pop();
				head = head->m_next;
            }
			head=curr;
			
		}
	}
template <typename T>
bool my_list<T>::check_cycle()
	{
		bool cycleyes = false;
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
			
        } else 
		{
			node<T>* temp1 = head;
			node<T>* temp2 = head;
			//uncomment if you need to check
			// head->m_next->m_next->m_next->m_next=head->m_next;
			while (temp2 != nullptr)
			{
				std::cout<<"----------"<<std::endl;
				if (temp1->m_next == temp2->m_next->m_next)
				{
					std::cout<<"find :"<<temp1->m_next<<" "<<temp2->m_next->m_next<<std::endl;
					cycleyes=true;
					break;
				}
				temp1 = temp1->m_next;
				temp2 = temp2->m_next->m_next;
			}
		}
		return cycleyes;
	}
template <typename T>
T my_list<T>::findN(int n)
	{
		T data;
		if(head == nullptr)
		{
            std::cout<<"list is empty"<<std::endl;        
        } else 
		{
			int index =0;
			int cindex =0;
			node<T>* temp = head;
			while (temp != nullptr)
			{
				index++;
				temp=temp->m_next;
			}
			temp =head;
			if (n>index) 
			{
				std::cout<<"the number is over than list size"<<std::endl;
				exit(0);
			} else {
				while (cindex != index-n)
				{
					temp=temp->m_next;
					cindex++;
				}
				data=temp->m_data;
			}
		}
		return data;
	}
#endif