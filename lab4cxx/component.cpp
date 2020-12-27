#include "component.h"


using namespace std;

Component::Component(std::string name, Connection& a, Connection& b)
   : A{a}, B{b}, name{name} {} 
 
 
double Component::get_potential()
{
    return abs(A.voltage - B.voltage);
}

string Component::get_name()
{
    return name; 
}

void Component::transfer_volt(double transfer)
{
     if(A.voltage > B.voltage)
    {
        A.voltage -= transfer;
        B.voltage += transfer;  
    } 
    else if(A.voltage < B.voltage)
    {
        A.voltage += transfer;
        B.voltage -= transfer;
    }
}

Battery::Battery(std::string name, Connection& a, Connection& b, double voltage) 
    : Component::Component{name, a, b}, voltage{voltage} {}

void Battery::simulate(double time_step)
{   
    A.voltage = this->voltage;
    B.voltage = 0;  
    
}

double Battery::get_current()
{
    return 0;
}

Resistor::Resistor(std::string name, Connection& a, Connection& b, double resistance) 
    : Component::Component{name, a, b}, resistance{resistance} {}

double Resistor::get_current()
{
    return get_potential()/resistance;
}


void Resistor::simulate(double time_step)
{
    double transfer = (get_current() * time_step);
    transfer_volt(transfer);
}

Capacitor::Capacitor(std::string name, Connection& a, Connection& b, double capacitance) 
    : Component::Component{name, a, b}, capacitance{capacitance}
{   
    stored = 0; 
}

void Capacitor::simulate(double time_step)
{
    double transfer = (capacitance * (get_potential() - stored)) * time_step;
    transfer_volt(transfer);
    stored += transfer;
 
}

double Capacitor::get_current()
{
   return capacitance * (get_potential() - stored);
}

