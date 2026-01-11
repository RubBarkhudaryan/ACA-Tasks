#ifndef TREE_TPP

# define TREE_TPP

# include <iostream>
# include "./queue.h"
# include "./tree.h"

template <typename T>
rub::Tree<T>::Tree(const T& val) : value(val)
{}

template <typename T>
rub::Tree<T>::~Tree(void)
{
	remove_children();
}

template <typename T>
void	rub::Tree<T>::add_child(const T& val)
{
	Tree	*new_node = new Tree(val);
	this->nodes.push_back(new_node);
}

template <typename T>
void	rub::Tree<T>::remove_children(void)
{
	for (Tree<T> *child : nodes)
		delete child;
	nodes.clear();
}

template <typename T>
void	rub::Tree<T>::print(void) const
{
	rub::Queue<Tree<T> *>	q;

	Tree<T>*	root = (Tree<T>*) this;

	q.push(root);
	while (!q.empty())
	{
		Tree<T>	*temp;
		temp = q.front()->value;

		q.pop();
		std::cout << temp->value << std::endl;
		for (std::size_t i = 0; i < temp->nodes.size(); ++i)
			q.push(temp->nodes[i]);
	}
}

template <typename T>
rub::Tree<T>	*rub::Tree<T>::get_child(std::size_t index)
{
	if (index >= nodes.size())
		return (nullptr);
	return (this->nodes[index]);
}

template <typename T>
const rub::Tree<T>	*rub::Tree<T>::get_child(std::size_t index) const
{
	if (index >= nodes.size())
		return (nullptr);
	return (this->nodes[index]);
}

#endif // TREE_TPP