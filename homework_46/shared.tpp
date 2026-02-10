#ifndef SHARED_TPP

# define SHARED_TPP

# include "./shared.hpp"

/*-----ctrl block-----*/
template <typename U, typename Deleter>
rub::control_block<U, Deleter>::control_block(U *ptr, Deleter del) : ptr(ptr), del(del)
{}

template <typename U, typename Deleter>
void	rub::control_block<U, Deleter>::destroy()
{
	if (this->ptr)
		this->del(this->ptr);
	this->ptr = nullptr;
}

/*-----ctors/dtor-----*/
template <typename T>
rub::shared_ptr<T>::shared_ptr() noexcept : ptr(nullptr), ctrl(nullptr)
{}

template <typename T>
rub::shared_ptr<T>::shared_ptr(std::nullptr_t) noexcept : ptr(nullptr), ctrl(nullptr)
{}

template <typename T>
rub::shared_ptr<T>::shared_ptr(const rub::shared_ptr<T>& other) noexcept : ptr(other.get()), ctrl(other.get_ctrl_block())
{
	if (this->ctrl)
		ctrl->count.fetch_add(1, std::memory_order_relaxed);
}

template <typename T>
rub::shared_ptr<T>::shared_ptr(rub::shared_ptr<T>&& other) noexcept : ptr(other.get()), ctrl(other.get_ctrl_block())
{
	other.reset_all(rub::reset::ALL);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(Y* ptr)
{
	if (ptr)
	{
		this->ptr = ptr;
		this->ctrl = new rub::control_block<Y, rub::default_deleter<Y>>(ptr, rub::default_deleter<Y>());
	}
	else
	{
		this->ptr = nullptr;
		this->ctrl = nullptr;
	}
}

template <typename T>
template <typename Y, typename Deleter, typename>
rub::shared_ptr<T>::shared_ptr(Y* ptr, Deleter del)
{
	if (ptr)
	{
		this->ptr = ptr;
		this->ctrl = new rub::control_block<Y, Deleter>(ptr, del);
	}
	else
	{
		this->ptr = nullptr;
		this->ctrl = nullptr;
	}
}

template <typename T>
template <typename Deleter>
rub::shared_ptr<T>::shared_ptr(std::nullptr_t ptr, Deleter del)
{
	this->ptr = nullptr;
	this->ctrl = new rub::control_block<T, Deleter>(nullptr, del);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(const rub::shared_ptr<Y>& other, Y* ptr) noexcept
{
	this->ptr = ptr;
	this->ctrl = other.get_ctrl_block();

	if (this->ctrl)
		ctrl->count.fetch_add(1, std::memory_order_relaxed);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(rub::shared_ptr<Y>&& other, Y* ptr) noexcept
{
	this->ptr = ptr;
	this->ctrl = other.get_ctrl_block();

	other.reset_all(rub::reset::CTRL_ONLY);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(const rub::shared_ptr<Y>& other) noexcept
{
	this->ptr = other.get();
	this->ctrl = other.get_ctrl_block();

	if (this->ctrl)
		ctrl->count.fetch_add(1, std::memory_order_relaxed);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(rub::shared_ptr<Y>&& other) noexcept
{
	this->ptr = other.get();
	this->ctrl = other.get_ctrl_block();

	other.reset_all(rub::reset::ALL);
}

template <typename T>
template <typename Y, typename Deleter, typename>
rub::shared_ptr<T>::shared_ptr(rub::unique_ptr<Y, Deleter>&& other) noexcept
{
	Y	*temp;

	temp = other.release();
	this->ctrl = new rub::control_block<T, Deleter>(temp, std::move(other.get_deleter()));
	this->ptr = temp;
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>::shared_ptr(const std::weak_ptr<Y>& other) noexcept
{
	rub::shared_ptr<T>	temp;

	temp = other.lock();
	if (temp)
	{
		this->ptr = temp.get();
		this->ctrl = temp.get_ctrl_block();
	
		if (this->ctrl)
			ctrl->count.fetch_add(1, std::memory_order_relaxed);
	}
}

template <typename T>
rub::shared_ptr<T>::~shared_ptr() noexcept
{
	if (this->ctrl)
	{
		if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
		{
			this->ctrl->destroy();
			delete ctrl;
		}
	}
}

/*-----operators-----*/
template <typename T>
T&	rub::shared_ptr<T>::operator*(void) noexcept
{
	return (*(this->ptr));
}

template <typename T>
T*	rub::shared_ptr<T>::operator->(void) noexcept
{
	return (this->ptr);
}

template <typename T>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(const rub::shared_ptr<T>& other) noexcept
{
	if (this != &other)
	{
		if (this->ctrl)
		{
			if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}
		this->ptr = other.get();
		this->ctrl = other.get_ctrl_block();
		if (this->ctrl)
			ctrl->count.fetch_add(1, std::memory_order_relaxed);
	}
	return (*this);
}

template <typename T>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(rub::shared_ptr<T>&& other) noexcept
{
	if (this != &other)
	{
		if (this->ctrl)
		{
			if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}
		this->ptr = other.get();
		this->ctrl = other.get_ctrl_block();
		other.reset_all(rub::reset::ALL);
	}
	return (*this);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(const rub::shared_ptr<Y>& other) noexcept
{
	if (this->ctrl != other.get_ctrl_block())
	{
		if (this->ctrl)
		{
			if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}

		this->ptr = other.get();
		this->ctrl = other.get_ctrl_block();

		if (this->ctrl)
			ctrl->count.fetch_add(1, std::memory_order_relaxed);
	}
	return (*this);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(rub::shared_ptr<Y>&& other) noexcept
{
	if (this->ctrl != other.get_ctrl_block())
	{
		if (this->ctrl)
		{
			if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}

		this->ptr = other.get();
		this->ctrl = other.get_ctrl_block();
		other.reset_all(rub::reset::ALL);
	}
	return (*this);
}

template <typename T>
template <typename Y, typename Deleter, typename>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(rub::unique_ptr<Y, Deleter>&& other) noexcept
{
	Y	*temp;

	if (this->ctrl)
	{
		if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
		{
			this->ctrl->destroy();
			delete this->ctrl;
		}
	}
	temp = other.release();
	this->ctrl = new rub::control_block<T, Deleter>(temp, std::move(other.get_deleter()));
	this->ptr = temp;
	return (*this);
}

/*-------methods-------*/
template <typename T>
T*	rub::shared_ptr<T>::get(void) const noexcept
{
	return (this->ptr);
}

template <typename T>
template <typename Deleter>
Deleter*	rub::shared_ptr<T>::get_deleter(void) noexcept
{
	if (!this->ctrl)
		return (nullptr);

	rub::control_block<T, Deleter>	*derived = dynamic_cast<rub::control_block<T, Deleter>*>(this->ctrl);

	if (!derived)
		return (nullptr);

	return (&derived->del);
}

template <typename T>
template <typename Deleter>
const Deleter*	rub::shared_ptr<T>::get_deleter(void) const noexcept
{
	if (this->ctrl)
		return (nullptr);

	rub::control_block<T, Deleter>	*derived = dynamic_cast<rub::control_block<T, Deleter>*>(this->ctrl);

	if (!derived)
		return (nullptr);

	return (&derived->del);
}

template <typename T>
long	rub::shared_ptr<T>::use_count() const noexcept
{
	if (this->ctrl)
		return (this->ctrl->count);
	return (0);
}

template <typename T>
void	rub::shared_ptr<T>::swap(rub::shared_ptr<T>& other) noexcept
{
	T						*ptr_temp;
	rub::control_block_base	*ctrl_temp;

	ptr_temp = other.ptr;
	ctrl_temp = other.ctrl;

	other.ptr = this->ptr;
	other.ctrl = this->ctrl;

	this->ptr = ptr_temp;
	this->ctrl = ctrl_temp;
}

template <typename T>
void	rub::shared_ptr<T>::reset() noexcept
{
	if (this->ctrl)
	{
		if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
		{
			this->ctrl->destroy();
			delete this->ctrl;
		}
	}
	this->ptr = nullptr;
	this->ctrl = nullptr;
}

template <typename T>
void	rub::shared_ptr<T>::reset(std::nullptr_t)
{
	if (this->ctrl)
	{
		if (ctrl->count.fetch_sub(1, std::memory_order_acq_rel) == 1)
		{
			this->ctrl->destroy();
			delete this->ctrl;
		}
	}
	this->ptr = nullptr;
	this->ctrl = nullptr;
}

template <typename T>
template <typename Y, typename>
void	rub::shared_ptr<T>::reset(Y *ptr)
{
	rub::shared_ptr<T>	temp(ptr);
	this->swap(temp);
}

template <typename T>
template <typename Y, typename Deleter, typename>
void	rub::shared_ptr<T>::reset(Y *ptr, Deleter del)
{
	rub::shared_ptr<T>	temp;
	temp.ctrl = new rub::control_block<Y, Deleter>(ptr, del);
	temp.ptr = ptr;
	this->swap(temp);
}

template <typename T>
rub::control_block_base	*rub::shared_ptr<T>::get_ctrl_block(void) const noexcept
{
	return (this->ctrl);
}

template <typename T>
void	rub::shared_ptr<T>::reset_all(int which) noexcept
{
	if (which == rub::reset::ALL)
	{
		this->ptr = nullptr;
		this->ctrl = nullptr;
	}
	else if (which == rub::reset::PTR_ONLY)
		this->ptr = nullptr;
	else if (which == rub::reset::CTRL_ONLY)
		this->ctrl = nullptr;
}

#endif //SHARED_TPP