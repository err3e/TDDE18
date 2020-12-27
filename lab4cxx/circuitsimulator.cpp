#include "component.h"
#include <cmath>

using namespace std; 
int main(int argc, char** argv)
{
    vector<string> args {argv, argv + argc};
    vector<double> arg_values{};
    Net circuit{};
    
    int size = args.size();
    
    if(args.size() < 5)
    {
        cerr << "Not enough command line arguments, using default values\n";
        arg_values.push_back(200000);
        arg_values.push_back(10);
        arg_values.push_back(0.01);
        arg_values.push_back(24);
    }

    for(int i = 1; i < size; i++)
    {
        try {
        arg_values.push_back(stod(args[i]));
        } 
        catch(invalid_argument)
        {
            cerr << "Invalid argument (only numbers allowed)" << endl;
            args.clear();
            arg_values.clear(); 
            terminate();
        }
    }
    
    circuit.circuit_1(int(arg_values[0]), int(arg_values[1]), arg_values[2], arg_values[3]);
    circuit.circuit_2(int(arg_values[0]), int(arg_values[1]), arg_values[2], arg_values[3]);
    circuit.circuit_3(int(arg_values[0]), int(arg_values[1]), arg_values[2], arg_values[3]);
}