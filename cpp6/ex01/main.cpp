#include <cstdint>
#include <iostream>

typedef struct	s_data
{
	int		value;
}	Data;

/*
 ** Need clone
*/

uintptr_t	serialize(Data* ptr)
{
	Data*	new_ptr = new Data();

	new_ptr->value = reinterpret_cast<int>(ptr->value);
	return (reinterpret_cast<uintptr_t>(new_ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data		data;
	Data		*ptr_data = NULL;
	Data		*ptr_data_serialize = NULL;
	uintptr_t	value = 0;

	data.value = 2147483647;
	ptr_data = &data;
	value = serialize(ptr_data);
	//ptr_data->value = 4;
	ptr_data_serialize = deserialize(value);
	if (ptr_data->value == ptr_data_serialize->value
		&& ptr_data_serialize != ptr_data)
		std::cout << "Same values." << std::endl;
	else
		std::cout << "Serialized values are not equal to old value." << std::endl;
	delete ptr_data_serialize;
	return (0);
}
