/*
+-----------------------------------------------------------------------+
| C++ Code DoubleLinkedList                                             |
+-----------------------------------------------------------------------+
| Copyright (c) 2013 - 2014, CILAB. All rights reserved.                |
+-----------------------------------------------------------------------+
| Authors: Giles                                                        |
+-----------------------------------------------------------------------+
 */


#include <iostream>

#ifndef _OBJECT_MANAGE_H
#define _OBJECT_MANAGE_H

template <class diff_type>
inline void Destruct(diff_type *_obj)
{
    _obj->~diff_type();
}

#endif

#ifndef _LIST_NODE_H
#define _LIST_NODE_H
#include <cstdlib>

template <class _Tp>
class Node
{
public:
    typedef  Node<_Tp>   _Node;
    typedef  Node<_Tp>*  Node_ptr;

public:
    Node()
    {
        m_prev = NULL;
        m_next = NULL;
    }

    ~Node() {}

    Node_ptr get_alloc()
    {
        Node_ptr _tmp = new _Node;
        return _tmp;
    }

public:
    _Tp         m_data;
    Node_ptr    m_prev;
    Node_ptr    m_next;
};

#endif

#ifndef _LIST_ITERATOR_H
#define _LIST_ITERATOR_H

template <class _Tp>
class Iterator
{
public:
    typedef  _Tp&                   value_ref;
    typedef  Node<_Tp>*             Node_ptr;
    typedef  Iterator<_Tp>          iterator;
    typedef  const iterator&        const_iterator;

    Iterator() {}
    Iterator(Node_ptr init) : iter(init) {}
    ~Iterator()
    {}

    value_ref operator *()
    {
        return iter->m_data;
    }
    
    inline bool operator ==(const_iterator cmpIter) const
    {
        return (iter == cmpIter.iter);
    }

    inline bool operator !=(const_iterator cmpIter) const
    {
        return (iter != cmpIter.iter);
    }

    iterator& operator ++()
    {
        iter = iter->m_next;
        return *this;
    }

    iterator operator ++(int)
    {
        iterator _tmp;
        _tmp.iter = _tmp.iter->m_next;
        return _tmp;
    }

    iterator& operator --()
    {
        iter = iter->m_prev;
        return *this;
    }

    iterator operator --(int)
    {
        iterator _tmp = *this;
        _tmp.iter = _tmp.iter->m_prev;
        return _tmp;
    }

public:
    Node_ptr iter;
};

#endif

#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include <iostream>
#include <cstdlib>

template <class _Tp>
class List
{
public:
    typedef  Node<_Tp>          _Node;
    typedef  Node<_Tp>*         Node_ptr;
    typedef  Node<_Tp>&         Node_ref;
    typedef  Iterator<_Tp>      iterator;
    //typedef    const Iterator<const _Tp&> const_iterator;
    
public: 
    List()
    {
        m_node = m_node->get_alloc();
        m_node->m_next = m_node;
        m_node->m_prev = m_node;
    }

    ~List() {}

    void clear()
    {
        Node_ptr p_current = m_node->m_next;

        // delete each node to end
        while (p_current != m_node) {
            Node_ptr _tmp = p_current;
            p_current = p_current->m_next;
            delete _tmp;
        }
        // back to origin
        m_node->m_prev = m_node;
        m_node->m_next = m_node;
    }

    inline bool empty() const
    {
        return (m_node == m_node->m_next);
    }

    iterator begin()
    {
        return (Node_ptr)(m_node->m_next);
    }

    iterator end()
    {
        return (Node_ptr)(m_node);
    }

    iterator insert(iterator _position, const _Tp& _data)
    {
        // insert before position
        Node_ptr _tmp = creat_node(_data);

        _tmp->m_next = _position.iter;
        _tmp->m_prev = _position.iter->m_prev;
        _position.iter->m_prev->m_next = _tmp;
        _position.iter->m_prev = _tmp;

        return _tmp;
    }

    iterator erase(iterator _position)
    {
        Node_ptr next_node = _position.iter->m_next;
        Node_ptr prev_node = _position.iter->m_prev;
        Node_ptr tmp_node  = _position.iter;
        next_node->m_prev  = prev_node;
        prev_node->m_next  = next_node;
        Destruct(tmp_node);
        return ((Node_ptr)next_node);
    }

    iterator insert(iterator _position)
    {
        insert(_position, _Tp());
    }

    _Tp& front()
    {
        return *begin();
    }

    _Tp& back()
    {
        return *(--end());
    }

    const _Tp& front() const
    {
        return *begin();
    }

    const _Tp& back() const
    {
        return *(--end());
    }
    
    void remove(const _Tp& _value)
    {
        iterator first_pos = begin();
        iterator last_pos = end();

        while (first_pos != last_pos) {
            iterator _cursor = first_pos;
            ++_cursor;
            if (*first_pos == _value)
                erase(first_pos);
            first_pos = _cursor;
        }
    }

    

    void push_back(const _Tp& _x)
    {
        insert(end(), _x);
    }

    void push_back()
    {
        insert(end());
    }

    void push_front(const _Tp& _x)
    {
        insert(begin(), _x);
    }

    void push_front()
    {
        insert(begin());
    }

    void pop_front()
    {
        iterator _tmp = end();
        erase(--_tmp);
    }

    void pop_back()
    {
        erase(begin());
    }

    void reverse()
    {
        reverse(this->m_node);
    }

    void reverse(Node_ptr _pos)
    {
        Node_ptr _tmp = _pos;
        do {
            swap(_tmp->m_next, _tmp->m_prev);
            _tmp = _tmp->m_next;
        } while(_tmp != _pos);
    }

    Node_ptr creat_node(_Tp _x)
    {
        Node_ptr _tmp = NULL;
        _tmp = _tmp->get_alloc();
        _tmp->m_data = _x;
        return _tmp;
    }
    
protected:
    Node_ptr m_node;
};

#endif