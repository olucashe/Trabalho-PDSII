#ifndef __FILE_HPP__
#define __FILE_HPP__

#include <fstream>

using namespace std;

class File
{
  public:
    virtual ifstream read() = 0;
};

#endif