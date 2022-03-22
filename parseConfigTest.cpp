
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

//#include "ParseConfig.h"
const std::string WHITESPACE = " \n\r\t\f\v";
 
 /* ltrim will delete any preceding whitespace from the string
 * parameters: address to a string
 */
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
/* rtrim will delete any whitespace from the end of a string
 * parameters: address to a string
 */
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
/* trim will delete any preceding whitespace and following whitespace from the string
 * parameters: address to a string
 */
std::string trim(const std::string &s) 
{
    return rtrim(ltrim(s));
}

 /*This main function will take in a config file with the extension .cfg
 * The user can pass in the file path to the config file via an -f flag followed by the path
 * (ex: -f /learningCpp/DemoConfigParameters.cfg)
 * If the path is not provided it defaults to /demoParameters.cfg
 * After, the file is opened the file format should be in the form of (key=value)
 * where key is a string and valus an int.  The values are stripped from the file and the variables
 * are set to the values that are in the config file. 
 */
int main(int argc, char **argv){

//config file parameters to fill in.
int rank =-1; 
int nodes = -1;
int group = -1; 
int test_iterations = -1;
int size =-1;
int AdapterNo = -1;
int client = -1;
int server = -1;
std::string fileName = "demoParameters.cfg";

std::vector<std::string>  params;

//Check for command args.  If file name passed in use that.
if (argc > 1)
{
  std::string argCheck;
  argCheck = argv[1];

  //check for -f flag and use file name given instead of default
  if (argCheck == "-f" && argv[2] != NULL)
  {
    fileName = argv[2];
  }
}

//open file
std::ifstream cfg(fileName);
//return error if can't open file
 if ( !cfg.is_open() )
      std::cout<<"Could not open file.  Please check file path.\n";


std::string line;
std::cout << "Values of variables before reading file" << std::endl;
std::cout << "rank = " << rank << std::endl;
std::cout << "nodes = " << nodes << std::endl;
std::cout << "group = " << group << std::endl;
std::cout << "test_iterations = " << test_iterations << std::endl;
std::cout << "size = " << size << std::endl;
std::cout << "AdapterNo = " << AdapterNo << std::endl;
std::cout << "client = " << client << std::endl;
std::cout << "server = " << server << std::endl << std::endl;
std::cout << "Values printed line by line from file" << std::endl;


//step through file line by line until EOF
while( std::getline(cfg, line) )
{
  //look for commented line
  if(line.find("#") != std::string::npos)
  {
    continue; //comment found take no action and move on to next line
  }
  else //continue with looking for parameters
  {
    std::istringstream is_line(line);

    //variable to hold key being read in
    std::string key;

    //variable to hold value of key being read in
    std::string value;

    //variable to hold params string for params vecors
    std::string VecString;
    //put value before equal sign into key variable
    
    if( std::getline(is_line, key, '=') )
    {    
        //remove whitespace
        key = trim(key);
    
      //put value after equal sign into value variable
      if( std::getline(is_line, value) )
      { 

        std::cout << key << " == " << value << std::endl;
        value = trim(value);
      }

    }
  
    //assign key value to proper parameter variable
    if (key == "rank")
    {
      rank = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "nodes")
    {
      nodes = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "group")
    {
      group = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "test_iterations")
    {
      test_iterations = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "size")
    {
      size = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }
    
    if (key == "AdapterNo")
    {
      AdapterNo = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "client")
    {
      client = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }

    if (key == "server")
    {
      server = std::stoi (value,nullptr,0);
      VecString = key + ":" + value;
      params.push_back(VecString);
    }
  }//end else 
}//end while loop

std::cout << std::endl << "Values of variables after reading file and assigning proper parameters" << std::endl << std::endl;
std::cout << "rank = " << rank << std::endl;
std::cout << "nodes = " << nodes << std::endl;
std::cout << "group = " << group << std::endl;
std::cout << "test_iterations = " << test_iterations << std::endl;
std::cout << "size = " << size << std::endl;
std::cout << "AdapterNo = " << AdapterNo << std::endl;
std::cout << "client = " << client << std::endl;
std::cout << "server = " << server << std::endl << std::endl;

std::cout << "\n\n Now that output of string Vector before returning it.\n" << std::endl;

for (int i = 0; i < params.size(); i++)
{
  std::cout << "params[" << i << "] = " << params[i] << std::endl;
}

return 0; //successful

}//end main


