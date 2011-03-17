/**
 * Simple C++ program that uses boost program options.
 * This functions as a simple test that I can use
 * the boost libraries.
 *
 * Usage:
 * 1. boost_hello --frap 1
 * 2. boost_hello
 */
#include "boost/program_options.hpp"
#include <iostream>
#include <iterator>

namespace po = boost::program_options;
using namespace std;

int main(int ac, char** av)
{
    po::options_description desc("Available options");
    desc.add_options()
        ("frap", po::value<int>(), "set frap mode")
    ;

    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);    

    if (vm.count("frap")) {
        cout << "Frap Mode " << vm["frap"].as<int>() << " Engaged" << endl;
    } else {
        cout << "Zero Entity Frap Mode Enabled" << endl;
    }

    return 0;
}
