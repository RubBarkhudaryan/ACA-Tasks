#ifndef LIST_TPP

# define LIST_TPP

# include "./list.h"

template <typename T>
rub::List<T>::Node::Node(const T& val) : value(val), next(nullptr)
{}

template <typename T>
rub::List<T>::List(void) : _head(nullptr), _tail(nullptr), _size(0)
{}

template <typename T>
rub::List<T>::List(const T& val) : _head(new Node(val)), _tail(_head), _size(1)
{}

template <typename T>
rub::List<T>::~List(void) noexcept
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
	if (!target || !new_node)
		return ;

	new_node->next = target->next;
	target->next = new_node;
	if (target == this->_tail)
		this->_tail = new_node;
	++(this->_size);
}

template <typename T>
void	rub::List<T>::push(const T& val)
{
	Node	*new_node;

	new_node = new Node(val);

	if (!_head)
	{
		this->_head = new_node;
		this->_tail = new_node;
	}
	else
	{
		this->_tail->next = new_node;
		this->_tail = this->_tail->next;
	}
	++(this->_size);
}

template <typename T>
void	rub::List<T>::pop(void)
{
	Node	*temp;

	if (!this->_head)
		return ;

	if (this->_head == this->_tail)
	{
		delete this->_head;
		this->_head = nullptr;
		this->_tail = nullptr;
		this->_size = 0;
		return ;
	}

	temp = this->_head;
	while (temp->next != this->_tail)
		temp = temp->next;

	delete this->_tail;
	this->_tail = temp;
	this->_tail->next = nullptr;
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
typename rub::List<T>::Node	*rub::List<T>::back(void)
{
	return (this->_tail);
}

template <typename T>
const typename rub::List<T>::Node	*rub::List<T>::back(void) const
{
	return (this->_tail);
}

template <typename T>
std::size_t	rub::List<T>::size() const
{
	return (this->_size);
}

template <typename T>
bool	rub::List<T>::empty() const
{
	return (this->_size == 0);
}

#endif //LIST_TPP