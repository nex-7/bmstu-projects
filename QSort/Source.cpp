#include<iostream>
#include<vector>
using namespace std;
template<class It, class Cmp>
It Srt(It beg, It end, Cmp cmp)
{
	It position = beg;
	while (1)
	{
		It iter = end;
		while (cmp(*position, *iter) && (iter > position))
			--iter;
		if (iter != position)swap(*position, *iter);
		else
		{
			return position;
			break;
		}
		position = iter;
		iter = beg;
		++iter;
		while (cmp(*iter, *position) && (iter < position))
			++iter;
		if (iter != position) swap(*position, *iter);
		else
		{
			return position;
			break;
		}
		position = iter;
	}
}
template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp)
{
	It i = end;
	--end;
	It p = Srt<It, Cmp>(beg, end, cmp);
	It Next = p;
	if (Next != end) ++Next;
	if (distance(beg, p)>0) qsort<It, Cmp>(beg, p, cmp);
	if (distance(Next, end)>0) qsort<It, Cmp>(Next, i, cmp);
}
void main()
{
	vector<int> buffer;
	for (unsigned int i = 0; i < 15; ++i) buffer.push_back(rand() % 100);
	qsort<vector<int>::iterator, less<int>>(buffer.begin(), buffer.end(), less<int>());
	for (unsigned int i = 0; i < 15; ++i) cout << buffer[i] << endl;
	system("pause");
	return;
}