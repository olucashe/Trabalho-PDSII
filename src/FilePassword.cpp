#include "FilePassword.hpp"

ifstream FilePassword::read()
{
	return ifstream("password.txt");
}