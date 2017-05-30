// [I] const iterator

template <typename T>
const T
& ls::list<T>::const_iterator::operator* ( ) const
{
	assert( current != nullptr );
	return current->data;
}

template <typename T>
typename ls::list<T>::const_iterator
& ls::list<T>::const_iterator::operator++ ( ) // ++it;
{
	current = current->next;
	return *this;
}

template <typename T>
typename ls::list<T>::const_iterator
ls::list<T>::const_iterator::operator++ ( int ) // it++;
{
	const_iterator temp = *this;
	current = current->next;
	return temp;
}

template <typename T>
typename ls::list<T>::const_iterator
& ls::list<T>::const_iterator::operator-- ( ) // --it;
{
	current = current->prev;
	return *this;
}

template <typename T>
typename ls::list<T>::const_iterator
ls::list<T>::const_iterator::operator-- ( int ) // it--;
{
	const_iterator temp = *this;
	current = current->prev;
	return temp;
}

template <typename T>
bool ls::list<T>::const_iterator::operator==
( const const_iterator & rhs ) const
{
	return current == rhs.current;
}

template <typename T>
bool ls::list<T>::const_iterator::operator!=
( const const_iterator & rhs ) const
{
	return current != rhs.current;
}

//[II] iterator
template <typename T>
const T & ls::list<T>::iterator::operator* ( ) const
{
	assert( const_iterator::current != nullptr );
	return const_iterator::current->data;
}

template <typename T>
T & ls::list<T>::iterator::operator* ( )
{
	assert( const_iterator::current != nullptr );
	return const_iterator::current->data;
}

template <typename T>
typename ls::list<T>::iterator
& ls::list<T>::iterator::operator++ ( )
{
	const_iterator::current = const_iterator::current->next;
    return *this;
}

template <typename T>
typename ls::list<T>::iterator
ls::list<T>::iterator::operator++ ( int )
{
	iterator temp = *this;
	const_iterator::current = const_iterator::current->next;
    return temp;

}

template <typename T>
typename ls::list<T>::iterator
& ls::list<T>::iterator::operator--( )
{
	const_iterator::current = const_iterator::current->prev;
	return *this;
}

template <typename T>
typename ls::list<T>::iterator 
ls::list<T>::iterator::operator--( int )
{
	iterator temp = *this;
	const_iterator::current = const_iterator::current->prev;
	return temp;
}

// [II] ite

// [I] special members
// template <typename T>
// ls::list<T> & ls::lista<T>::operator=
// ( const list & other )
// {
// 	m_size = m_size.other;
// 	m_head = m_head.other;
// 	m_tail = m_tail.other;


// }