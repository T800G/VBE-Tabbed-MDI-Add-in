#ifndef _ARRAY_13F923D6_6030_43C0_89AB_0B570BB4BB7E_
#define _ARRAY_13F923D6_6030_43C0_89AB_0B570BB4BB7E_


//https://solarianprogrammer.com/2016/11/28/cpp-passing-c-style-array-with-size-information-to-function/
template <class T, size_t N> T GetArrayMin(const T (&arr)[N])
{
	T m = arr[0];
	size_t i;
	for (i = 1; i < N; i++)
	{
		if (arr[i] < m) m = arr[i];
	}
return m;
};

template <class T, size_t N> T GetArrayMax(const T (&arr)[N])
{
	T m = arr[0];
	size_t i;
	for (i = 1; i < N; i++)
	{
		if (arr[i] > m) m = arr[i];
	}
return m;
};

template <class T, size_t N> BOOL IsArrayElement(const T (&arr)[N], const T el)
{
	size_t i;
	for (i = 0; i < N; i++)
	{
		if (arr[i] == el) return TRUE;
	}
return FALSE;
};

#endif//_ARRAY_13F923D6_6030_43C0_89AB_0B570BB4BB7E_
