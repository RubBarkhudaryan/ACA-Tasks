#ifndef QUEUE_H

# define QUEUE_H

#include "./list.h"
#include <cstddef>

namespace rub
{
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