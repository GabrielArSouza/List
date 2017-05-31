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

// [III] list
template <typename T>
typename ls::list<T>::iterator
ls::list<T>::begin( )
{
	return iterator(m_head->next);
}

template <typename T>
typename ls::list<T>::const_iterator
ls::list<T>::cbegin( ) const
{
	return const_iterator(m_head->next);
}

template <typename T>
typename ls::list<T>::iterator
ls::list<T>::end( )
{
	return iterator(m_tail);
}

template <typename T>
typename ls::list<T>::const_iterator
ls::list<T>::cend( ) const
{
	return const_iterator(m_tail);
}

template <typename T>
int ls::list<T>::size( ) const
{
	return m_size;
}

template <typename T>
bool ls::list<T>::empty( ) const
{
	return m_size == 0;
}

template <typename T>
void ls::list<T>::clear( )
{
	Node * current = m_head->next;

	while ( current != m_tail )
	{
		Node * temp = current;
		current = current->next;
		delete temp;
	}

	m_size = 0;
	m_head->next = m_tail;
	m_tail->prev = m_head;
}

template <typename T>
T & ls::list<T>::front( )
{
	auto aux = m_head->next;
	return aux->data;
}

template <typename T>
const T & ls::list<T>::front( ) const
{
	auto aux = m_head->next;
	return aux->data;
}

template <typename T>
T & ls::list<T>::back( )
{
	auto aux = m_tail->prev;
	return aux->data;
}

template <typename T>
const T & ls::list<T>::back( ) const
{
	auto aux = m_tail->prev;
	return aux->data;
}

template <typename T>
void ls::list<T>::push_front
( const T & value )
{
	insert(begin(), value);
}

template <typename T>
void ls::list<T>::push_back
( const T & value )
{
	insert(end(), value);
}

template <typename T>
void ls::list<T>::pop_front( )
{
	erase(cbegin());
}

template <typename T>
void ls::list<T>::pop_back( )
{
	auto it = end();
	erase(--it);
}

template <typename T>
void ls::list<T>::assign(const T& value )
{
	auto current = m_head;
	while ( current->next != m_tail )
	{
		current = current->next;
		current->data = value;
	}
}

template <typename T>
template <class InItr>
void ls::list<T>::assign( InItr first, InItr last )
{
	auto current = m_head;
	auto fixed = first;

	while ( current->next != m_tail )
	{
		if ( first == last ) first = fixed;
		current = current->next;
		current->data = *first; 

		first++;
	}
}

template <typename T>
void ls::list<T>::assign( std::initializer_list<T> ilist )
{
	auto current = m_head;
	auto fixed = ilist.begin();
	auto _nfixed = ilist.begin();

	while ( current->next != m_tail )
	{
		if ( _nfixed == ilist.end() ) _nfixed = fixed;
		current = current->next;
		current->data = *_nfixed;

		_nfixed++;

	}
}

template <typename T>
typename ls::list<T>::iterator
ls::list<T>::insert( const_iterator itr, const T & value )
{
	//<! atualiza tamanho
	m_size++;
	//<! cria novo nó com o valor
	auto new_node = new Node(value);
	//<! next do novo nó igual a itr
	new_node->next = itr.current;
	//<! prev do novo nó recebe prev do itr
	new_node->prev = (itr.current)->prev;
	//<! anterior a itr aponta para novo nó
	((itr.current)->prev)->next = new_node;
	//<! itr aponta para novo nó
	(itr.current)->prev = new_node;

	return iterator(new_node);
}

template <typename T>
typename ls::list<T>::iterator ls::list<T>::insert
( const_iterator pos, std::initializer_list<T> ilist )
{
	for (auto i = ilist.begin(); i != ilist.end(); ++i )
	{
		insert(pos, *i );
	}

	return iterator(pos.current);
	

}

template <typename T>
typename ls::list<T>::iterator
ls::list<T>::erase( const_iterator itr )
{
	if (itr.current != m_tail)
	{
		auto before( (itr.current)->prev ); //anterior ao removido
		auto after( (itr.current)->next ); //posterior ao rmeovido
		
		//Avança para poder excluir o no
		before->next = after;
		after->prev = before;
		m_size--;

		delete itr.current;	
		return iterator( (itr.current)->next);
	}

	return iterator( itr.current );
	
}

template <typename T>
typename ls::list<T>::iterator
ls::list<T>::erase( const_iterator first, const_iterator last )
{
	
	while( first != last )
	{
		auto aux = first;
		first.current = (first.current)->next;

		auto before( (aux.current)->prev ); //anterior ao removido
		auto after( (aux.current)->next ); //posterior ao rmeovido
		
		//Avança para poder excluir o no
		before->next = after;
		after->prev = before;
		m_size--;

		delete aux.current;	
	}

	return iterator( first.current );
}

template <typename T>
typename ls::list<T>::const_iterator 
ls::list<T>::find( const T & value ) const
{
	auto curr = m_head;
	while ( curr->next != m_tail )
	{
		curr = curr->next;
		if( curr->data == value )
			return const_iterator( curr );
	}

	return const_iterator( m_tail );
}



