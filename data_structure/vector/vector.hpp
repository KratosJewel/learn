#ifndef KRATOS_VECTOR_HPP
#define KRATOS_VECTOR_HPP

#include "../base/base.hpp"

namespace kratos
{
	template <typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		explicit vector(uint init_size = 0)
			: size_(0)
			, capacity_(init_size + SPARE_CAPACITY)
		{
			data_ = new T[capacity_];
		}

		vector(const vector& rhs)
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

		const vector& operator=(const vector& rhs)
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

		void push_back(const T &value)
		{
			if (size_ == capacity_)
			{
				reserve(size_ * 2);
			}
			data_[size_++] = value;
		}

		void resize(uint new_size)
		{
			if (capacity_ < new_size)
			{
				reserve(new_size * 2);
			}

			size_ = new_size;
		}

		bool empty() const 
		{
			return 0 == size_;
		}

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

		iterator begin()
		{
			return &data_[0];
		}

		iterator end()
		{
			return &data_[size_];
		}

		const_iterator cbegin() const
		{
			return &data_[0];
		}

		const_iterator cend() const
		{
			return &data_[size_];
		}

		~vector()
		{
			base::del(data_);
		}

		uint get_size() { return size_; }
		uint get_capacity() { return capacity_; }

	private:
		T * data_;
		uint size_;
		uint capacity_;
	};
}

#endif