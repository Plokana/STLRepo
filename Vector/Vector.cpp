#include"Vector.h"

template <typename T>
Vector<T>::Vector():m_size(0), m_capacity(0), m_pArray(0){}

template <typename T>
Vector<T>::Vector(unsigned int n):m_size(n),m_capacity(n), m_pArray(new T[n]){}

template <typename T>
Vector<T>::Vector(const Vector<T>& v) {
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_pArray = new T[m_size];
	for(int i = 0; i<m_size; i++)
		m_pArray[i] = v.m_pArray[i];
}

template <typename T>
Vector<T>::Vector(unsigned int size, const T& initial){
	m_size = size;
	m_capacity = size;
	m_pArray  = new T[size];
	for(int i =0; i<size; i++)
		m_pArray[i] = initial;
}
template <class T>
Vector<T> & Vector<T>::operator=(const Vector<T> &v){
	delete[] m_pArray;
	m_size = v.m_size;
	m_capacity = v.m_capacity;
	m_pArray = new T[m_size];
	for(int i =0; i<m_size; i++)
		m_pArray[i] = v.m_pArray[i];
	return *this;
}
template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return m_pArray;
}

template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return m_pArray + size();
}

template<class T>
T& Vector<T>::front()
{
    return m_pArray[0];
}

template<class T>
T& Vector<T>::back()
{
    return m_pArray[m_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (m_size >= m_capacity)
    reserve(m_capacity + m_size);
    m_pArray [m_size++] = v;
}

template<class T>
void Vector<T>::pop_back()
{
    m_size--;
}

template<class T>
unsigned int Vector<T>::size()const//
{
    return m_size;
}

template<class T>
void Vector<T>::resize(unsigned int size)
{
    reserve(size);
    m_size = size;
}
template<class T>
void Vector<T>::reserve(unsigned int capacity){
	m_capacity = capacity;
	T* newArray = new T[m_capacity];
	for(int i =0; i<m_size; i++)
		newArray[i] = m_pArray[i];
	delete []m_pArray;
	m_pArray = newArray;
}

template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    return m_pArray[index];
}  

template<class T>
unsigned int Vector<T>::capacity()const
{
    return m_capacity;
}

template<class T>
Vector<T>::~Vector()
{
    delete[]m_pArray;
}


int main()
{  

   Vector<int> v;

   v.reserve(2);
   assert(v.capacity() == 2);

   Vector<string> v1(2);
   assert(v1.capacity() == 2);
   assert(v1.size() == 2);
   v.resize(1);
   Vector<string> v3(2, "hello");
   Vector<string> v4 = v3;
   v3.pop_back();

	cout<<"Elements in v4\n";
	for(auto x : v4)
		cout<<x<<" ";
cout<<"\n";
}
