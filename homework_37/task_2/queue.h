#ifndef QUEUE_H

# define QUEUE_H

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
			void			push(Node *new_node);
			virtual void	pop(void);
			Node			*front(void);
			Node			*back(void);
			const Node		*back(void) const;
			const Node		*front(void) const;
			std::size_t		size() const;

		protected:
			Node		*_head;
			Node		*_tail;
			std::size_t	_size;
	};

	template <typename T>
	class	Queue : public List<T>
	{
		public:
			/*---------queue ctor/dtor---------*/
			Queue(void);
			Queue(const T& val);
			~Queue(void) noexcept = default;
			Queue(const Queue &) = delete;
			Queue& operator=(const Queue &) = delete;

			/*---------queue methods---------*/
			void	pop(void) override;
	};
}

#include "./queue.tpp"

#endif //QUEUE_H