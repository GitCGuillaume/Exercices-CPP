#include <cstdint>
#include <iostream>

typedef struct	s_data
{
	int		value;
}	Data;

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int	main(void)
{
	Data		data;
	Data		*ptr_data_serialize = NULL;
	uintptr_t	value = 0;

	data.value = 4;
	value = serialize(&data);
	data.value = 4;
	ptr_data_serialize = deserialize(value);
	if (data.value == ptr_data_serialize->value)
		std::cout << "Same values." << std::endl;
	return (0);
}
