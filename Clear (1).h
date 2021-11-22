#pragma once
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

inline void Clear_stream(istream& object)
{
	object.clear(); 
	object.ignore(100000000, '\n');

	/*
	while (object.peek() != '\n' || object.gcount() != 0)
	{
		object.get();
	}
	*/
}
