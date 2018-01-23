#include <iostream>
#include <string>
#include "vector/vector.hpp"
#include "list/list.hpp"
#include "stack/stack.hpp"
int main()
{
	kratos::vector<int> vec_i(1);

	vec_i.push_back(5);
	vec_i.push_back(10);

	const kratos::vector<int> vec_i2 = vec_i;

	for (kratos::vector<int>::iterator iter = vec_i.begin(); iter != vec_i.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	kratos::list<std::string> lst_i;

	lst_i.push_back("ss");
	lst_i.push_back("aa");

	kratos::list<std::string>::const_iterator iter = lst_i.cbegin();

	for(;iter != lst_i.cend();++iter)
	{
		std::cout << *iter << std::endl;
	}


	kratos::stack<int> sta_i;
	int top = 0;
	sta_i.push(1);
	sta_i.push(2);
	sta_i.push(3);
	top = sta_i.top();
	sta_i.pop();
	top = sta_i.top();
	sta_i.pop();
	top = sta_i.top();
	sta_i.pop();

	return 1;
}