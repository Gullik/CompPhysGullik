#ifndef LIB_H
#define LIB_H

#include<sstream>
template <typename T>
std::string to_string(T value)
{
  //create an output string stream
  std::ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}

double ran2(long *);   //Stolen from FYS-3150 library

double randomGaussian(double mean, double standardDeviation, long *idum); //The algorithm is taked from http://www.design.caltech.edu/erik/Misc/Gaussian.html


#endif // LIB_H

