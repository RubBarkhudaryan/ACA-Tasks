#ifndef SET_TPP

# define SET_TPP

# include <iostream>
# include "./set.h"


template <typename T>
rub::set_node<T>::set_node(void) : left(nullptr), right(nullptr), value(T{})
{}

template <typename T>
rub::set_node<T>::set_node(const T& val) : left(nullptr), right(nullptr), value(val)
{}

template <typename T>
void	rub::set<T>::bst_insert(rub::set_node<T> *node, const T& val)
{
	if (val < node->value)
	{
		if (node->left)
			bst_insert(node->left, val);
		else
			node->left = new rub::set_node<T>(val);
	}
	else if (val > node->value)
	{
		if (node->right)
			bst_insert(node->right, val);
		else
			node->right = new rub::set_node<T>(val);
	}
}

template <typename T>
rub::set<T>::set(void) : root(nullptr)
{}

template <typename T>
rub::set<T>::set(std::initializer_list<T> list) : root(new rub::set_node<T>())
{
	rub::set_node<T>					*temp;
	std::initializer_list<T>::iterator	it;

	if (list.size() == 0)
		return ;
	it = list.begin();
	root->value = *(it);
	++it;

	for (; it != list.end(); ++it)
		bst_insert(root, *it);
}

template <typename T>
rub::set<T>::~set(void)
{
	delete_tree(root);
}

template <typename T>
void	rub::set<T>::delete_tree(rub::set_node<T> *node)
{
	if (!node)
		return ;
	delete_tree(node->left);
	delete_tree(node->left);
	delete node;
}

template <typename T>
void	rub::set<T>::print(rub::set_node<T> *node, int mode) const
{
	if (!node)
		return ;
	if (mode == INORDER)
	{
		print(node->left);
		std::cout << node->value << std::endl;
		print(node->right);
	}
	else if (mode == PREORDER)
	{
		std::cout << node->value << std::endl;
		print(node->left);
		print(node->right);
	}
	else if (mode == POSTORDER)
	{
		print(node->left);
		print(node->right);
		std::cout << node->value << std::endl;
	}
}

template <typename T>
void	rub::set<T>::inorder(rub::set_node<T> *node) const
{
	print(root, INORDER);
}

template <typename T>
void	rub::set<T>::preorder(rub::set_node<T> *node) const
{
	print(root, PREORDER);
}

template <typename T>
void	rub::set<T>::postorder(rub::set_node<T> *node) const
{
	print(root, PREORDER);
}

#endif //SET_TPP