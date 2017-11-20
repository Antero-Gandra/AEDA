#ifndef _UTIL_H
#define _UTIL_H
#include <iostream>
#include <string>
#include <vector>
extern const std::streamsize max;
void removeSpaces(std::string &string);

template <class T>
T * binarySearch(std::vector<T*> vec, T * value) {
	int left = 0;
	int right = vec.size() - 1;
	while (left <= right) {
		int middle = (left + right) / 2;
		if (*vec[middle] < *value)
			left = middle + 1;
		else if (*value < *vec[middle])
			right = middle - 1;
		else return vec[middle];
	}
	return NULL;
}


#endif

