#ifndef KRATOS_BASE_HPP
#define KRATOS_BASE_HPP

namespace kratos
{
	const int SPARE_CAPACITY = 8;
	using uint = unsigned int;

	namespace base
	{
		template <typename T>
		void del(T* &p) noexcept
		{
			if (p)
			{
				delete p;
				p = nullptr;
			}
		}
	}
}

#endif