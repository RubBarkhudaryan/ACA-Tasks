#ifndef SET_H

# define SET_H

// # include "./pair.h"
# include <initializer_list>

namespace rub
{

	enum	print_modes
	{
		INORDER,
		PREORDER,
		POSTORDER
	};

	template <typename T>
	struct	set_node
	{
		T			value;
		set_node	*left;
		set_node	*right;

		set_node(void);
		set_node(const T& val);
		~set_node(void) = default;
	};

	template <typename T>
	class	set
	{
		private:
			set_node<T>	*root;

			void	bst_insert(rub::set_node<T> *node, const T& val);
			void	print(rub::set_node<T> *node, int mode) const;
			void	delete_tree(rub::set_node<T> *node);
		public:
			public:
			/*---------set ctor/dtor---------*/
			set(void);
			set(std::initializer_list<T> list);
			set(const rub::set<T>& other) = delete;
			~set(void);

			/*---------set operators---------*/
			rub::set<T>&	operator=(const rub::set<T>& other) = delete;

			/*---------set methods---------*/
			void	inorder(rub::set_node<T> *node) const;
			void	preorder(rub::set_node<T> *node) const;
			void	postorder(rub::set_node<T> *node) const;
	};
};

#endif //SET_H