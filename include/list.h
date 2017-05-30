#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>  // cout, endl
#include <iterator>  // bidirectional_iterator_tag
#include <cassert>   // assert()
#include <algorithm> // copy
#include <cstddef>   // std::ptrdiff_t

namespace ls {

	template <typename T>
	class list {

	private:

		struct Node {
		
			T data; //<! Data field
			Node *prev; //<! Pointer to the previous node in the list.
			Node *next; //<! Pointer to the next node in the list.
			
			//<! Basic constructor.
			Node( const T & d = T( ), Node * p = nullptr, Node * n = nullptr )
				: data( d ), prev(p), next( n ) { /* Empty */ }
		};

	private:

		int m_size;
		Node *m_head;
		Node *m_tail;

	public:

		class const_iterator;
		class iterator;

		list( size_t sz = 0 )
			: m_size( sz )
			, m_head( new Node() )
			, m_tail( new Node() )
		{ 
			m_head->next = m_tail;
			m_tail->prev = m_head;
		}

		~list( )
		{
			//clear(); //Apaga os outros nos da lista
	        delete m_head;
	        delete m_tail;
		}

		// list( const list & other)
		// 	   : m_size(0)
		//     , m_head( new Node() )
		//     , m_tail( new Node() )
		// {
		// 	for( auto it(other.begin()); it != begin(); ++it)
	 	//     	push_back(*it); //TODO: it retorna data do nó
		// }
		// 
		// list( list && );
		// 
		list & operator= ( const list & );
		// list & operator= ( List && );
		// iterator begin( );
		// const_iterator cbegin( ) const;
		// iterator end( );
		// const_iterator cend( ) const;
		// int size( ) const;
		// bool empty( ) const;
		// void clear( );
		// T & front( );
		// const T & front( ) const;
		// T & back( );
		// const T & back( ) const;
		// void push_front( const T & value );
		// void push_back( const T & value );
		// void pop_front( );
		// void pop_back( );
		// void assign(const T& value );
		// template < class InItr >
		// void assign( InItr first, InItr last );
		// void assign( std::initializer_list<T> ilist );
		// iterator insert( const_iterator itr, const T & value );
		// iterator insert( const_iterator pos, std::initializer_list<T> ilist );
		// iterator erase( const_iterator itr );
		// iterator erase( const_iterator first, const_iterator last );
		// const_iterator find( const T & value ) const;

	};

	template <typename T>
	class list<T>::const_iterator {

		protected:
			Node *current;
		 	const_iterator( Node * p ) : current( p ) {}
		 	friend class list<T>;

		public:

		 	const_iterator( ){ /*empty*/ }

		 	const T & operator* ( ) const;
		 	const_iterator & operator++ ( ); // ++it;
		 	const_iterator operator++ ( int ); // it++;
		 	const_iterator & operator-- ( ); // --it;
		 	const_iterator operator-- ( int ); // it--;
		 	bool operator== ( const const_iterator & rhs ) const;
		 	bool operator!= ( const const_iterator & rhs ) const;
		
	};

	template <typename T>
	class list<T>::iterator : public list<T>::const_iterator {

		protected:
			iterator( Node *p ) : const_iterator( p ){}
			friend class list<T>;

		public:

			iterator( ) : const_iterator() { /* Empty */ }
			const T & operator* ( ) const;
			T & operator* ( );

			iterator & operator++ ( );
			iterator operator++ ( int );
			iterator & operator--( );
			iterator operator--( int );

	};

	/**
	 * impletação do template.
	 */
	#include "list.inl"
}

#endif