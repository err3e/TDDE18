#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <iomanip>
#include <iostream>
#include <cmath>

// TODO: Complementary work needed, 8-8: You're missing destructors. FIXED
// TODO: Complementary work needed, 8-8: Remove commented and unused code. FIXED
// TODO: Complementary work needed, 8-8: Your capacitator gives the wrong values. FIXED
// TODO: Complementary work needed, 8-8: You have memoryleeks. Look these up using
// vagrind. 

// COMMENT: You don't need to point with this for all your components, you can
// just assign the values with =. Read up on using this so you don't need to do
// it unnecessary.

class Connection
{
    public:
    Connection() : voltage{0} {};
    double voltage;
};

class Component 
{
    public:
<<<<<<< HEAD
    Component(std::string name, Connection& p, Connection& n);
    virtual ~Component() {} ;
=======
    Component(std::string name, Connection& a, Connection& b);
    virtual ~Component() = default;
>>>>>>> linux
    virtual void simulate(double time_step) = 0;
    virtual double get_current() = 0;
    double get_potential();
    std::string get_name();
    void transfer_volt(double transfer);
    protected:
    Connection& A; 
    Connection& B;
    const std::string name{};
};

class Battery : public Component
{
    public:
<<<<<<< HEAD
    Battery(std::string name, Connection& p, Connection& n, double voltage); 
    ~Battery() {};
=======
    Battery(std::string name, Connection& a, Connection& b, double voltage); 
    ~Battery() = default;
>>>>>>> linux
    void simulate(double time_step) override;
    double get_current() override;

    private:
    const double voltage;
};


class Resistor : public Component
{
    public:
<<<<<<< HEAD
    Resistor(std::string name, Connection& p, Connection& n, double resistance);
    ~Resistor() {};
=======
    Resistor(std::string name, Connection& a, Connection& b, double resistance);
    ~Resistor() = default;
>>>>>>> linux
    void simulate(double time_step) override;
    double get_current() override;

    private: 
    const double resistance;
};

class Capacitor : public Component
{
    public:
<<<<<<< HEAD
    Capacitor(std::string name, Connection& p, Connection& n, double capacitance);
    ~Capacitor() {std::cout<<"cap" << std::endl;};
=======
    Capacitor(std::string name, Connection& a, Connection& b, double capacitance);
    ~Capacitor() = default;
>>>>>>> linux
    void simulate(double time_step) override;
    double get_current() override;

    private: 
    const double capacitance;
    double stored;
};

class Net
{
public:
    Net() : net{} {};
    ~Net();
    void simulate(int iterations, int iteration_print, double time_step, double battery_voltage);
    void deallocate_components();
    void print_all();
    void circuit_1(int iterations, int iteration_print, double time_step, double battery_voltage);
    void circuit_2(int iterations, int iteration_print, double time_step, double battery_voltage);
    void circuit_3(int iterations, int iteration_print, double time_step, double battery_voltage);

private:
    std::vector<Component*> net;
};

#endif