#ifndef SHARED_HPP

# define SHARED_HPP

# include <cstddef>
# include <type_traits>
# include "../homework_45/unique.hpp"

namespace rub
{
	struct	control_block_base
	{
		public:
			std::size_t	count = 1;

			virtual	~control_block_base() = default;
			virtual void	destroy() = 0;
	};

	template <typename U, typename Deleter = rub::default_deleter<U>>
	struct	control_block : public control_block_base
	{
		public:
			U			*ptr;
			Deleter		del;

			control_block(U *ptr, Deleter del = Deleter{});
			void	destroy() override;
	};

	template <typename T>
	class	shared_ptr
	{
		private:
			T						*ptr;
			rub::control_block_base	*ctrl;

		public:
			/*-----shared_ptr ctor/dtor-----*/
			shared_ptr() noexcept;
			shared_ptr(std::nullptr_t) noexcept;
			shared_ptr(const rub::shared_ptr<T>& other) noexcept;
			shared_ptr(rub::shared_ptr<T>&& other) noexcept;
			~shared_ptr() noexcept;

			/*-----shared_ptr template ctors-----*/
			// template <typename Y>
			// explicit shared_ptr(Y* ptr);
			
			// template <typename Y, typename Deleter>
			// shared_ptr(Y* ptr, Deleter del);
			
			// template <typename Deleter>
			// shared_ptr(std::nullptr_t ptr, Deleter del);
			
			// template <typename Y, typename Deleter, typename Alloc>
			// shared_ptr(Y* ptr, Deleter del, Alloc alloc);
			
			// template <typename Deleter, typename Alloc>
			// shared_ptr(std::nullptr_t ptr, Deleter del, Alloc alloc);
			
			// template <typename Y>
			// shared_ptr(const rub::shared_ptr<Y>& other, Y* ptr) noexcept;
			
			// template <typename Y>
			// shared_ptr(rub::shared_ptr<Y>&& r, Y* ptr) noexcept;

			// template <typename Y>
			// shared_ptr(const rub::shared_ptr<Y>& other) noexcept;

			// template <typename Y>
			// shared_ptr(rub::shared_ptr<Y>&& other) noexcept;

			// template <typename Y>
			// explicit shared_ptr(const std::weak_ptr<Y>& other) noexcept;

			// template <typename  Y, typename Deleter>
			// shared_ptr(rub::unique_ptr<Y, Deleter>&& other) noexcept;

			/*-----shared_ptr operators-----*/
			T&					operator*(void) noexcept;
			T*					operator->(void) noexcept;
			rub::shared_ptr<T>&	operator=(const rub::shared_ptr<T>& other) noexcept;
			rub::shared_ptr<T>&	operator=(rub::shared_ptr<T>&& other) noexcept;

			template <typename Y,
					typename = std::enable_if_t<
								std::is_convertible<Y *, T *>::value
					>
			>
			rub::shared_ptr<T>&	operator=(const rub::shared_ptr<Y>& other) noexcept;

			template <typename Y,
					typename = std::enable_if_t<
								std::is_convertible<Y *, T *>::value
					>
			>
			rub::shared_ptr<T>&	operator=(rub::shared_ptr<Y>&& other) noexcept;

			template <typename Y,
					typename Deleter,
					typename = std::enable_if_t<
								std::is_convertible<Y *, T *>::value
					>
			>
			rub::shared_ptr<T>&	operator=(rub::unique_ptr<Y, Deleter>&& other) noexcept;

			/*-----shared_ptr methods-----*/
			T*					get(void) const noexcept;
			void				reset() noexcept;
			long				use_count() const noexcept;
			void				swap(rub::shared_ptr<T>& r) noexcept;

			/*-----shared_ptr templated methods-----*/
			template <typename Y,
					typename = std::enable_if_t<
								std::is_convertible<Y *, T *>::value
					>
			>
			void				reset(Y* ptr);

			template <typename Y,
					typename Deleter,
					typename = std::enable_if_t<
								std::is_convertible<Y *, T *>::value
					>
			>
			void				reset(Y* ptr, Deleter del);

			template <typename Deleter>
			Deleter&			get_deleter(void) noexcept;
	
			template <typename Deleter>
			const Deleter&		get_deleter(void) const noexcept;
	};
}

# include "./shared.tpp"

#endif //SHARED_HPP