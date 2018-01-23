#ifndef KRATOS_STACK_HPP
#define KRATOS_STACK_HPP

#include "../base/base.hpp"

namespace kratos
{
	template <typename T>
	class stack
	{
	public:
		explicit stack()
			: size_(0)
			, capacity_(SPARE_CAPACITY)
		{
			data_ = new T[capacity_];
		}

		stack(const stack& rhs)
		{
			operator=(rhs);
		}

		const T& operator[](int index)const
		{
			return data_[index];
		}

		T& operator[](int index)
		{
			return data_[index];
		}

		const stack& operator=(const stack& rhs)
		{
			if (this != &rhs)
			{
				base::del(data_);

				size_ = rhs.size_;
				capacity_ = rhs.capacity_;

				data_ = new T[capacity_];

				for (uint i = 0; i < size_; ++i)
				{
					data_[i] = rhs.data_[i];
				}
			}

			return *this;
		}

		void push(const T &value)
		{
			if (size_ == capacity_)
			{
				reserve(size_ * 2);
			}
			data_[size_++] = value;
		}

		void pop()
		{
			if (0 <= size_)
			{
				--size_;
			}
		}

		T top()
		{
			return data_[size_ - 1];
		}

		bool empty() const
		{
			return 0 == size_;
		}

		~stack()
		{
			base::del(data_);
		}

		uint get_size() { return size_; }

	private:
		void reserve(uint new_capacity)
		{
			if (size_ < new_capacity)
			{
				T *old_data = data_;

				data_ = new T[new_capacity];

				for (uint i = 0; i < size_; ++i)
				{
					data_[i] = old_data[i];
				}

				capacity_ = new_capacity;

				base::del(old_data);
			}
		}

		void resize(uint new_size)
		{
			if (capacity_ < new_size)
			{
				reserve(new_size * 2);
			}

			size_ = new_size;
		}

	private:
		T * data_;
		uint size_;
		uint capacity_;
	};
}

#endif