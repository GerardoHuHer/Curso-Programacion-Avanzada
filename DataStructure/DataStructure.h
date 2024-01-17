#pragma once
#include <iostream>
#include <iterator> 
#include <vector>
#include <algorithm> // copy algorithm
#include <iterator> // ostream_iterator iterator
#include <stdexcept> // out_of_range exception

using namespace std;

int Fig15_04();
int Fig15_10();

template <typename T> void printVector(const vector<T>& integers2);