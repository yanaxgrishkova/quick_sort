#include <iostream>
using namespace std;

template <typename Iterator>
void quickSort(Iterator left, Iterator right)
{
	Iterator i = left;
	Iterator j = right;
	Iterator k = left;
	while (i <= j)
	{
		while (*i < *k) i++;
		while (*j > *k) j--;
		if (i <= j)
		{
			swap(*i, *j);
			i++;
			j--;
		}
	} 
	if (left < j) quickSort(left, j);
	if (right > i) quickSort(i, right);
}
