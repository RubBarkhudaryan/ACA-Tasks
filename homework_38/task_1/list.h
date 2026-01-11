#ifndef LIST_H

# define LIST_H

#include <cstddef>

namespace rub
{
	template <typename T>
	class	List
	{
		public:

			struct	Node
			{
				T		value;
				Node	*next;
				explicit Node(const T& val);
			};

			/*---------list ctor/dtor---------*/
			List(void);
			List(const T& val);
			List(const List &) = delete;
			List& operator=(const List &) = delete;
			virtual ~List(void) noexcept;

			/*---------list methods---------*/
			void			insert(Node *target, Node *new_node);
			void			push(const T& val);
			virtual void	pop(void);
			Node			*front(void);
			Node			*back(void);
			const Node		*back(void) const;
			const Node		*front(void) const;
			std::size_t		size() const;
			bool			empty() const;

		protected:
			Node		*_head;
			Node		*_tail;
			std::size_t	_size;
	};
}

# include "list.tpp"

#endif //LIST_H