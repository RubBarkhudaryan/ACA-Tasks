#ifndef LIST_H

# define LIST_H

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
				Node(const T& val);
			};

			/*---------list ctor/dtor---------*/
			List();
			List(const T& val);
			~List();

			/*---------list methods---------*/
			void		insert(Node *target, Node *new_node);
			void		push_front(Node *new_node);
			void		pop_front(void);
			Node		*front(void);
			const Node	*front(void) const;
			std::size_t	size(void) const;

		private:
			Node		*_head;
			std::size_t	_size;
	};
}

#include "./list.tpp"

#endif //LIST_H