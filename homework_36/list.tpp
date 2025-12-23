#include "./list.h"
#include <iostream>

template <typename T>
rub::List<T>::Node::Node(const T& val) : value(val), next(nullptr)
{}

template <typename T>
rub::List<T>::List() : _head(nullptr), _size(0)
{}

template <typename T>
rub::List<T>::List(const T& val) : _head(new Node(val)), _size(1)
{}

template <typename T>
rub::List<T>::~List()
{
	Node	*temp;
	Node	*nxt;

	temp = this->_head;
	while (temp)
	{
		nxt = temp->next;
		delete temp;
		temp = nxt;
	}
}

template <typename T>
void	rub::List<T>::insert(Node *target, Node *new_node)
{
	Node	*temp;

	if (!target || !new_node)
		return ;

	temp = target->next;
	target->next = new_node;
	new_node->next = temp;
	++(this->_size);
}

template <typename T>
void	rub::List<T>::push_front(Node *new_node)
{
	Node	*temp;

	if (!new_node)
		return ;

	temp = this->_head;
	new_node->next = temp;
	this->_head = new_node;
	++(this->_size);
}

template <typename T>
void	rub::List<T>::pop_front(void)
{
	Node	*temp;

	if (!this->_head)
		return ;

	temp = this->_head;
	this->_head = this->_head->next;
	delete temp;
	--(this->_size);
}

template <typename T>
typename rub::List<T>::Node	*rub::List<T>::front(void)
{
	return (this->_head);
}

template <typename T>
const typename rub::List<T>::Node	*rub::List<T>::front(void) const
{
	return (this->_head);
}

template <typename T>
std::size_t	rub::List<T>::size(void) const
{
	return (this->_size);
}
