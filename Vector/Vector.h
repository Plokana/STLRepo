#include<iostream>
#include<cassert>
#include<algorithm>
#include<string>
using namespace std;
template <class T>
class Vector{
	public:
		typedef T * iterator;

		Vector();
		Vector(unsigned int size);
		Vector(unsigned int size, const T & initial);
		Vector(const Vector<T> & v);      
		~Vector();

		unsigned int capacity() const;
		unsigned int size() const;
		bool empty() const;
		iterator begin();
		iterator end();
		T & front();
		T & back();
		void push_back(const T & value); 
		void pop_back();  

		void reserve(unsigned int capacity);   
		void resize(unsigned int size);   

		T & operator[](unsigned int index);  
		Vector<T> & operator=(const Vector<T> &);

	private:
		unsigned int m_size;
		unsigned int m_capacity;
		T * m_pArray;
};
