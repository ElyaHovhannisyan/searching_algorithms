#include <iostream>
#include <cmath>
#include <chrono>

using namespace std::chrono;

int     linear_search(int *arr, int size, int element);
int     binary_search(int *arr, int size, int element);
int     jump_search(int *arr, int size, int element);
int     *make_arr();
void	time_count(int	*array);
