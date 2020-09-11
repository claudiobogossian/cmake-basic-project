#include "basiclib.h"
#include "boost/version.hpp"
#include <curl/curl.h>

#include <iostream>

#define BOOST_ALL_DYN_LINK

BasicLib::BasicLib()
{
}

BasicLib::~BasicLib()
{

}


void BasicLib::testCurl()
{
  std::cout <<  *curl_version( ) << std::endl;
}

void BasicLib::testBoost()
{
  std::cout << BOOST_VERSION << std::endl;
}

void BasicLib::testGDAL()
{

}

void BasicLib::testPROJ()
{

}
