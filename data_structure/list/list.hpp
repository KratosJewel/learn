#ifndef KRATOS_LIST_HPP
#define KRATOS_LIST_HPP

#include "../base/base.hpp"

namespace kratos
{
	template <typename T>
	class list
	{
	public:
		explicit list()
		{
			init();
		}

		~list()
		{
			Node* node = head_->next_;
			Node* temp = nullptr;

			while (node != tail_)
			{
				temp = node;
				node = node->next_;
				base::del(temp);
			}

			base::del(head_);
			base::del(tail_);
		}

		void init()
		{
			head_ = new Node();
			tail_ = new Node();

			head_->next_ = tail_;
			tail_->perv_ = head_;
		}

		uint get_size() const
		{
			return size_;
		}

		const T & retrieve() const
		{
			return current_->data_;
		}

	private:
		struct Node
		{
			Node(T value = T(), Node* perv = nullptr, Node* next = nullptr)
				: data_(value)
				, perv_(perv)
				, next_(next)
			{}
			T data_;
			Node* perv_;
			Node* next_;
		};

	public:
		class const_iterator
		{
		public:
			const_iterator(Node* node = nullptr)
				:current_(node) {}

			const_iterator& operator++()
			{
				current_ = current_->next_;
				return *this;
			}

			const_iterator& operator++(int)
			{
				const_iterator *temp = *this;

				++*this;

				return temp;
			}

			const T& operator*() const
			{
				return retrieve();
			}

			bool operator==(const const_iterator & rhs)
			{
				return current_ == rhs.current_;
			}

			bool operator!=(const const_iterator & rhs)
			{
				return !(*this == rhs);
			}

			Node* get_current()
			{
				return current_;
			}

		protected:
			T & retrieve() const
			{
				return current_->data_;
			}

			Node * current_;

			friend class list<T>;
		};

		class iterator : public const_iterator
		{
		public:
			iterator(){}
			iterator(Node* node = nullptr)
				:const_iterator(node)
			{}
			~iterator(){}

			T& operator*() const
			{
				return this->retrieve();
			}

			iterator& operator++()
			{
				this->current_ = this->current_->next_;
				return *this;
			}

			iterator& operator++(int)
			{
				const_iterator *temp = *this;

				++*this;

				return temp;
			}
		};

		iterator insert(iterator iter, const T&  value)
		{
			Node *cur = iter.get_current();
			Node* temp = new Node(value, cur->perv_, tail_);

			cur->perv_->next_ = temp;
			cur->perv_ = temp;

			return iterator(temp);
		}

		void push_back(const T& value)
		{
			insert(tail_, value);

			++size_;
		}

		iterator begin()
		{
			return iterator(head_->next_);
		}

		const_iterator cbegin() const
		{
			return const_iterator(head_->next_);
		}

		iterator end()
		{
			return iterator(tail_);
		}

		const_iterator cend() const
		{
			return const_iterator(tail_);
		}

	private:
		Node * head_;
		Node* tail_;

		uint size_;
	};
}

#endif