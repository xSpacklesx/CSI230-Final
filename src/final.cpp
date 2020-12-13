

#include "dataGen.h"
#include "functions.h"

#include <iostream>


#include <boost/program_options.hpp>
using namespace boost::program_options;



int main(int argc, const char *argv[])
{

std::string outFileName;
int size = 0;
int uChoice = 0;
    try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("outFile", value<std::string>(&outFileName)->default_value("outFile.txt"), "of")
      ("size", value<int>(&size)->default_value(100), "Size")
      ("algorithm", value<int>(&uChoice)->default_value(0), "Algorithm");


    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("outFile"))
      outFileName = vm["outFile"].as<std::string>();
    else if (vm.count("size"))
      size = vm["size"].as<int>();
    else if (vm.count("size"))
      size = vm["size"].as<int>();
  }

  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }

    numberGen(size);
    std::cout << "hello from the func" << std::endl;

    int* dataSet = NULL;
	dataSet = new int[size];


	loadData("bin/dataset.txt", dataSet, size);

    int* copyArray = NULL;

    copyArray = copyData(dataSet, size);

    callFunction(uChoice, copyArray, size, 1, "bin/"+outFileName, 1);
    std::cout << "Algorithm chosen:" << uChoice << "\t\tSize chosen:" << size << std::endl << "Sorted file can be found at bin/" << outFileName << std::endl; 

    std::cout << "Goodbye from the func" << std::endl;
}