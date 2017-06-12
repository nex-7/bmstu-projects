#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

template<class It, class Cmp>

void qsort(It beg, It end, Cmp cmp)
{
	It left = beg;
	It tmp = left++;
	It right = end;
	while (left != right)
	{
		if (cmp(*left, *tmp))
			++left;
		else
		{
			while ((left != --right) && cmp(*tmp, *right));
			std::iter_swap(left, right);
		}
	}
	std::iter_swap(beg, --left);
	if (std::distance(beg, left)>0)
		qsort(beg, left, cmp);
	if (std::distance(right, end)>0)
		qsort(right, end, cmp);
}

