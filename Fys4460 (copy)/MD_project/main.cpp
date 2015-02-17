#include <iostream>
#include <armadillo>

#include "atoms.h"
#include "save_load.h"
#include "lib.h"
#include "integrator.h"
#include "unitconverter.h"
#include "list/list.h"

using namespace std;
using namespace arma;

double mass = 39.948;   //a.m.u
double boltzmann = 1.;  //a.m.u
double cellLength = 5.26/3.405;
double epsilon = tempAtomicFromSI(119.8)*boltzmann;

rowvec systemSize = zeros <rowvec> (1,3);


int main()
{
    int nUnitCells = 2;          //Number of fcc crystals, in one dimension
    double temperature = tempMDFromSI(100);
    int nSteps = 10;
    double dt = 0.005;

    //Create the list

    list_t *list = list_create();

//    string filepath = "../MD_project/states/" "state_" + to_string(nUnitCells) + "_" + to_string(tempMDToSI(temperature)) + ".xyz";
    string filepath = "../MD_project/states/testState.xyz";

    const char* statefile = filepath.c_str();

    //The atoms is stored as an array where the first 3 columns are positions, next 3 velocities
    mat atoms = zeros <mat> (4*nUnitCells*nUnitCells*nUnitCells,3);
    mat velocities = zeros <mat> (4*nUnitCells*nUnitCells*nUnitCells,3);
    mat forces = zeros <mat> (4*nUnitCells*nUnitCells*nUnitCells,3);

    createFCCLattice(&atoms, cellLength, nUnitCells);
    setBoltzmannVelocity(&velocities, temperature);
    removeMomentum(velocities);

    //setting the global variable, systemSize, it is used in the force calculations and in the periodic boundary implementation
    systemSize << cellLength * nUnitCells << cellLength * nUnitCells << cellLength * nUnitCells;

    //Opening statefile
    ofstream file;
    file.open(statefile);


    for(int i = 0; i < nSteps ; i++)
    {
        if(i % 100 == 0)
            cout << "At step number: " << i << endl;

        step(&atoms, &velocities, &forces, dt);
        save(&atoms, &velocities, file);
    }


    return 0;
}

