#ifndef QUEUE_TPP

# define QUEUE_TPP

# include "./queue.h"
# include <iostream>

template <typename T>
rub::Queue<T>::Queue(void) : List<T>()
{}

template <typename T>
rub::Queue<T>::Queue(const T& val) : List<T>(val)
{}

template <typename T>
void	rub::Queue<T>::pop(void)
{
	typename rub::List<T>::Node*	del_node;

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
	del_node = this->_head;
	this->_head = this->_head->next;
	delete del_node;
	--(this->_size);
}

#endif //QUEUE_TPP
