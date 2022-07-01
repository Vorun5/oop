#pragma once

#include <vector>

template <typename T, typename Less>
// TODO: сделать версию функции с двумя операторами
bool FindMaxEx(std::vector<T> const& arr, T& maxValue, Less const& less)
{
	if (arr.empty())
	{
		return false;
	}

	const T* maxElement = &arr[0];
	for (const T& arrElem : arr)
	{
		if (less(*maxElement, arrElem))
		{
			(maxElement = &arrElem);
		}
	}
	maxValue = std::move(*maxElement);

	return true;
}