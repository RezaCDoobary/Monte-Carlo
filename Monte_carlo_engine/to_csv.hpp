
#ifndef to_csv_hpp
#define to_csv_hpp
#include <stdio.h>
#include <vector>
#include <string>

void to_csv(std::string filename, std::vector<std::string> headers, std::vector<std::vector<double> > parameter);
#endif /* to_csv_hpp */
