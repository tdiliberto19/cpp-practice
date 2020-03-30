/**
    Calculates the kinetic energy of an object, given the mass and velocity of the object at an arbitrary
    instant

    @author Timothy Diliberto
    @version 1.0 3/30/2020
*/

#include <iostream>
#include <cmath>

using namespace std;

double kineticEnergy(double, double);

// Controls the flow of the program

int main() {
    double mass,
           velocity,
           kinetic_energy;

    cout << "Enter the mass and velocity of an object\n"
         << "Mass (in kg): ";
    cin >> mass;
    cout << "Velocity (in m/s): ";
    cin >> velocity;

    kinetic_energy = kineticEnergy(mass, velocity);

    cout << "The object's kinetic energy is "<< kinetic_energy << endl;

    return 0;
}

/**
    Calculates the KINETIC_ENERGY of an object with MASS at VELOCITY
    
    @param mass the mass of the object of subject
           velocity the velocity of the object
    @return the kinetic_energy of the object
*/

double kineticEnergy(double mass, double velocity) {
    double kinetic_energy = mass * pow(velocity, 2) / 2;

    return kinetic_energy;
}
