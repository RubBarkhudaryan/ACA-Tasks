#ifndef UNIQUE_HPP

# define UNIQUE_HPP

# include <cstddef>

namespace rub
{
	template <typename T, typename Deleter>
	class	unique_ptr
	{
		private:
			T*		target;
			Deleter	d;

		public:
			/*-----unique_ptr ctor/dtor-----*/
			unique_ptr() noexcept;
			unique_ptr(T* ptr) noexcept;
			unique_ptr(std::nullptr_t nl_ptr) noexcept;
			unique_ptr(rub::unique_ptr &&other) noexcept;
			unique_ptr(T *ptr, Deleter del) noexcept;
			
			~unique_ptr();
	};
}

# include "./unique.tpp"

#endif //UNIQUE_HPP