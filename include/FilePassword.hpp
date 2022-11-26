#ifndef __FILE_PASSWORD_HPP__
#define __FILE_PASSWORD_HPP__

#include "File.hpp"

class FilePassword : public File
{
  public:
	  virtual ifstream read() override;
};

#endif