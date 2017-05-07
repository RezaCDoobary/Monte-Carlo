
#include "to_csv.hpp"
#include <fstream>
#include <sstream>
#include <string>

void to_csv(std::string filename, std::vector<std::string> headers, std::vector<std::vector<double> > parameter)
{
    std::ostringstream off;
    std::ofstream myfile;
    myfile.open(filename);
    std::string text = "";
    for(unsigned long i = 0; i < headers.size(); i++)
    {
        myfile << headers[i];
    }
    const unsigned long k1 = parameter.size();
    const unsigned long k2 = parameter[1].size();
    for(unsigned long i = 0; i < k2; i++)
    {
        for(unsigned long j = 0; j < k1;j++)
        {
            
            text+=std::to_string(parameter[j][i]);
            text+=",";
        }
        text+="\n";
    }
    myfile << text;
    myfile.close();
}

