#ifndef SHARED_TPP

# define SHARED_TPP

# include "./shared.hpp"

/*-----ctrl block-----*/
template <typename U, typename Deleter>
rub::control_block<U, Deleter>::control_block(U *ptr, Deleter del = Deleter{}) : ptr(ptr), del(del)
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
rub::shared_ptr<T>::shared_ptr(const rub::shared_ptr<T>& other) noexcept : ptr(other.ptr), ctrl(other.ctrl)
{
	if (this->ctrl)
		++(this->ctrl->count);
}

template <typename T>
rub::shared_ptr<T>::shared_ptr(rub::shared_ptr<T>&& other) noexcept : ptr(std::move(other.ptr)), ctrl(std::move(other.ctrl))
{
	other.ptr = nullptr;
	other.ctrl = nullptr;
}

template <typename T>
rub::shared_ptr<T>::~shared_ptr() noexcept
{
	if (this->ctrl)
	{
		if (this->ctrl->count == 1)
		{
			this->ctrl->destroy();
			delete ctrl;
		}
		else
			--(this->ctrl->count);
	}
}

/*-----operators-----*/

template<typename T>
T&	rub::shared_ptr<T>::operator*(void) noexcept
{
	return (*(this->ptr));
}

template<typename T>
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
			if (--(this->ctrl->count) == 0)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}
		this->ptr = other.ptr;
		this->ctrl = other.ctrl;
		if (this->ctrl)
			++(this->ctrl->count);
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
			if (--(this->ctrl->count) == 0)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}
		this->ptr = other.ptr;
		this->ctrl = other.ctrl;
		other.ptr = nullptr;
		other.ctrl = nullptr;
	}
	return (*this);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(const rub::shared_ptr<Y>& other) noexcept
{
	if (this->ctrl != other.ctrl)
	{
		if (this->ctrl)
		{
			if (--(this->ctrl->count) == 0)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}

		this->ptr = other.ptr;
		this->ctrl = other.ctrl;

		if (this->ctrl)
			++(this->ctrl->count);
	}
	return (*this);
}

template <typename T>
template <typename Y, typename>
rub::shared_ptr<T>&	rub::shared_ptr<T>::operator=(rub::shared_ptr<Y>&& other) noexcept
{
	if (this->ctrl != other.ctrl)
	{
		if (this->ctrl)
		{
			if (--(this->ctrl->count) == 0)
			{
				this->ctrl->destroy();
				delete this->ctrl;
			}
		}

		this->ptr = other.ptr;
		this->ctrl = other.ctrl;
		other.ptr = nullptr;
		other.ctrl = nullptr;
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
		if (--(this->ctrl->count) == 0)
		{
			this->ctrl->destroy();
			delete this->ctrl;
		}
	}
	temp = other.release();
	this->ctrl = new rub::control_block<Y, Deleter>(temp, std::move(other.get_deleter()));
	this->ptr = temp;
	return (*this);
}

/*-------methods-------*/

template<typename T>
T*	rub::shared_ptr<T>::get(void) const noexcept
{
	return (this->ptr);
}

template <typename T>
template <typename Deleter>
Deleter&	rub::shared_ptr<T>::get_deleter(void) noexcept
{
	if (this->ctrl)
		return (nullptr);

	rub::control_block<T, Deleter>	*derived = dynamic_cast<rub::control_block<T, Deleter>*>(this->ctrl);

	if (!derived)
		return (nullptr);

	return (&derived->del);
}

template<typename T>
template <typename Deleter>
const Deleter&	rub::shared_ptr<T>::get_deleter(void) const noexcept
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
		if (--(this->ctrl->count) == 0)
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
void	rub::shared_ptr<T>::reset(Y *ptr) noexcept
{
	rub::shared_ptr<T>	temp(ptr);
	this->swap(temp);
}

template <typename T>
template <typename Y, typename Deleter, typename>
void	rub::shared_ptr<T>::reset(Y *ptr, Deleter del) noexcept
{
	rub::shared_ptr<T>	temp;
	temp.ctrl = new rub::control_block<Y, Deleter>(ptr, del);
	temp.ptr = ptr;
	this->swap(temp);
}

#endif //SHARED_TPP