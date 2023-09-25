#include <iostream>
#ifndef _INIT_CLASS_
#define _INIT_CLASS_
template <typename T>
class vectorclass
{
	private:
		int m_size;
		T* m_ptr;
		int capacity;
	public:
	vectorclass();
	vectorclass(vectorclass &obj);
	vectorclass& operator=(vectorclass& obj);
	vectorclass(vectorclass&& obj);
	vectorclass&& operator=(vectorclass&& obj);
	~vectorclass();
	 void print();
	void push_back(T need_add);
	void pop_back();
	T* begin ();
	T* end ();
	int size ();
	int vectorclasscapacity ();
	void erase(int index);
	void erase(int firstindex, int secondindex);
	bool empty();
	
};
template <typename T>
vectorclass<T>::vectorclass()
	{
		
		m_ptr = new T[1];
		m_size=0;
		capacity = 1;
		std::cout<<"vectorclass constructor"<<std::endl;
	}
template <typename T>
vectorclass<T>::vectorclass(vectorclass &obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=new T[m_size];
		for (int i=0;i<m_size;i++)
		{
			this->m_ptr[i] = obj.m_ptr[i];
		}
		std::cout<<"vectorclass copy constructor"<<std::endl;
	}
template <typename T>
vectorclass<T>& vectorclass<T>::operator=(vectorclass<T>& obj)
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
		std::cout<<"operator assignment for vectorclass"<<std::endl;
		return *this;
	}
template <typename T>
vectorclass<T>::vectorclass(vectorclass&& obj)
	{
		this->m_size=obj.m_size;
		this->m_ptr=obj.m_ptr;
		obj.m_ptr=nullptr;
		obj.m_size = 0;
		std::cout<<"vectorclass move constructor"<<std::endl;
	}
template <typename T>
vectorclass<T>&& vectorclass<T>::operator=(vectorclass<T>&& obj)
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
		std::cout<<"vectorclass move operator assignment"<<std::endl;
		return std::move(*this);
	}
template <typename T>
vectorclass<T>::~vectorclass()
	{
		delete []m_ptr;
		std::cout<<"vectorclass destructor"<<std::endl;
	}
template <typename T>
	 void vectorclass<T>::print()
    {
        for (int i = 0; i < m_size; i++) {
            std::cout << m_ptr[i] << " ";
        }
        std::cout << std::endl;
    }
	template <typename T>
	void vectorclass<T>::push_back(T need_add)
	{
		if (m_size==capacity) {
			 T* m_ptr1 = new T[2*capacity];
			for (int i = 0; i < this->capacity; i++) {
				m_ptr1[i] = m_ptr[i];
			}
			delete[] m_ptr;
			this->m_ptr = m_ptr1;
			capacity*=2;
		}
		// this->m_size++;
        this->m_ptr[this->m_size] = need_add;
		m_size++;
	}
	template <typename T>
	void vectorclass<T>::pop_back()
	{
		T* m_ptr1 = new T[this->m_size-1];
        for (int i = 0; i < this->m_size-1; i++) {
			m_ptr1[i] = m_ptr[i];
        }
        delete[] m_ptr;
        this->m_ptr = m_ptr1;
		this->m_size--;
        
	}
	template <typename T>
	T* vectorclass<T>::begin ()
	{
		T* mm1_ptr=m_ptr;
		
		return mm1_ptr;
	}
	template <typename T>
	T* vectorclass<T>::end ()
	{
		T* mm2_ptr=m_ptr;
		mm2_ptr+=m_size;
		return mm2_ptr;
	}
	template <typename T>
	int vectorclass<T>::size ()
	{
		return m_size;
	}
	template <typename T>
	int vectorclass<T>::vectorclasscapacity ()
	{
		return capacity;
	}
	template <typename T>
	void vectorclass<T>::erase(int index)
	{
		if (index <= capacity) {
			if (index <= m_size)
			{
				T* m_ptr1 = new T[capacity];
				int j=0;
				for (int i = 0; i < m_size; i++) {
					
					if (i==index)
					{
						j=i+1;
					} 
					m_ptr1[i] = m_ptr[j];
					j++;
				}
				delete[] m_ptr;
				this->m_ptr = m_ptr1;
				this->m_size--;
			}
		}
	}
	template <typename T>
	void vectorclass<T>::erase(int firstindex, int secondindex)
	{
		if (firstindex<=secondindex) {
			if ((firstindex<secondindex) && (secondindex<=m_size))
			{
				T* m_ptr1 = new T[capacity];
				int j=0;
				for (int i = 0; i < m_size; i++) {
					
					if (i==firstindex)
					{
						j=i+(secondindex-firstindex);
					} 
					m_ptr1[i] = m_ptr[j];
					j++;
				}
				delete[] m_ptr;
				this->m_ptr = m_ptr1;
				this->m_size-=secondindex-firstindex;
			}
		}
		
	}
	template <typename T>
	bool vectorclass<T>::empty()
	{
		if (m_size==0)
		{
			return true;
		} else {
			return false;
		}
	}
#endif
