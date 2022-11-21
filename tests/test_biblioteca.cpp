#include "doctest"
#include "Biblioteca.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

TEST_CASE("Testando o q") {
	Biblioteca b;
	CHECK(b.q == 0);
}

TEST_CASE("Testando o B") {
	Biblioteca b;
	CHECK(b.B == 0);
}

TEST_CASE("Testando o p") {
	Biblioteca b;
	CHECK(b.p == 0);
}

TEST_CASE("Testando o arquivo de senha") {
	FILE *f = fopen("password.txt", "r");
	CHECK(f != NULL);
	
	if (f != NULL)
	{
		char str[100];
		fgets(str, 100, f);
		CHECK(str != NULL);
		CHECK(strcmp(str, "pass") == 0);
		fclose(f);
	}
}