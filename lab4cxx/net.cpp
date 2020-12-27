#include "component.h"
#include <vector>

using namespace std;

void Net::circuit_1(int iterations, int iteration_print, double time_step, double voltage)
{
    Connection P, N, R124, R23;
    net.push_back(new Battery{"Bat", P, N, voltage});
    net.push_back(new Resistor{"R1", P, R124, 6});
    net.push_back(new Resistor{"R2", R124, R23, 4});
    net.push_back(new Resistor{"R3", R23, N, 8});
    net.push_back(new Resistor{"R4", R124, N, 12});
    simulate(iterations, iteration_print, time_step, voltage);
    deallocate_components();
}

void Net::circuit_2(int iterations, int iteration_print, double time_step, double voltage)
{
    Connection P, N, L, R;
    net.push_back(new Battery{"Bat", P, N, voltage});
    net.push_back(new Resistor{"R1", P, L, 150});
    net.push_back(new Resistor{"R2", P, R, 50});
    net.push_back(new Resistor{"R3", R, L, 100});
    net.push_back(new Resistor{"R4", L, N, 300});
    net.push_back(new Resistor{"R5", R, N, 250});
    simulate(iterations, iteration_print, time_step, voltage);
    deallocate_components();
}

void Net::circuit_3(int iterations, int iteration_print, double time_step, double voltage)
{
    Connection P, N, L, R;

    net.push_back(new Battery{"Bat", P, N, voltage});
    net.push_back(new Resistor{"R1", P, L, 150});
    net.push_back(new Resistor{"R2", P, R, 50});
    net.push_back(new Capacitor{"C3", R, L, 1.0});
    net.push_back(new Resistor{"R4", N, L, 300});
    net.push_back(new Capacitor{"C5", R, N, 0.75});
    simulate(iterations, iteration_print, time_step, voltage);
    deallocate_components();
}


void Net::simulate(int iterations, int iteration_print, double time_step, double battery_voltage)
{

    cout << setw(12);
    for (Component *element : net)
    {
        cout << element->get_name() << setw(12);
    }
    cout << setw(6) << endl;
    for (Component *element : net)
    {
        cout << "Volt" << setw(6);
        cout << "Curr" << setw(6);
    }
    cout << setw(0) << endl;


    int print_i = iterations / iteration_print;
    for (int i = 0; i <= iterations; i++)
    {
        for (Component *element : net)
        {
           element->simulate(time_step);
        }
        if(i % print_i == 0 && i != 0)
        {
            print_all();
        }
    }
}
    
void Net::print_all()
{
    cout << setw(6) << fixed << setprecision(2);
    for (Component *element : net)
    {
        cout << element->get_potential() << setw(6) << flush;
        cout << element->get_current() << setw(6) << flush;
    }
    cout << endl; 
}

void Net::deallocate_components()
{
    for (auto element : net)
    {
        delete element;
    }
    net.clear();
}

Net::~Net()
{
    deallocate_components();
}