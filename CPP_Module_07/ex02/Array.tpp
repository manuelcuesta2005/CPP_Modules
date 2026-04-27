#include <exception>

template <typename T>
Array<T>::Array() : _content(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int N)
{
    _content = new T[N]();
    _size = N;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    _content = new T[other._size]();
    _size = other._size;

    for (size_t i = 0; i < other._size; i++)
    {
        _content[i] = other._content[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->_content;
        this->_size = other._size;
        if (_size > 0)
        {
            _content = new T[other._size]();
            for (int i = 0; i < other._size; i++)
            {
                this->_content[i] = other._content[i];
            }
        }
        else
        {
            _content = NULL;
        }
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_content[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::out_of_range("Index out of range");
    return (_content[index]);
}

template <typename T>
Array<T>::~Array()
{
    delete[] _content;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}