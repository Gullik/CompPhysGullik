#include <iostream>
#include <armadillo>

#include "atoms.h"
#include "save_load.h"
#include "lib.h"
#include "integrator.h"
#include "unitconverter.h"
#include "list/list.h"
#include "sample.h"
#include "list/neighborlist.h"

using namespace std;
using namespace arma;

double mass = 39.948;   //a.m.u
double boltzmann = 1.;  //a.m.u
double cellLength = 5.26/3.405;
double epsilon = tempAtomicFromSI(119.8)*boltzmann;

rowvec systemSize = zeros <rowvec> (1,3);
double cutOffLength = 1.;

double potentialEnergy = 0;
double kineticEnergy = 0;
double measuredTemperature = 0;


int main()
{
    int nUnitCells = 6;          //Number of fcc crystals, in one dimension
    double temperature = tempMDFromSI(100);
    int nSteps = 1000;
    double dt = 0.001;

//    string filepath = "../MD_project/states/" "state_" + to_string(nUnitCells) + "_" + to_string(tempMDToSI(temperature)) + ".xyz";
    string filepath = "../MD_project/states/testState.xyz";
    const char* samplePath = "../MD_project/statistics/stats";

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

    //Setting up the neighborList
    NeighborList *m_list;
    m_list = new NeighborList(cutOffLength, systemSize);
//    m_list->sortAtoms(atoms, systemSize); //Just for testing purposes


    //Opening statefile
    ofstream file, sampleFile;
    file.open(statefile);
    sampleFile.open(samplePath);



    for(int i = 0; i < nSteps ; i++)
    {
        if(i % 100 == 0)
            cout << "At step number: " << i << endl;


        step(&atoms, &velocities, &forces, dt);
        save(&atoms, &velocities, file);

        if(i % 1 == 0)
            sample(&atoms, &velocities, dt*i, sampleFile);
    }


    return 0;
}

