#include "sample.h"

extern double kineticEnergy;
extern double potentialEnergy;
extern double measuredTemperature;

ofstream samplefile;

void sample(mat *atoms, mat *velocities, double time, ofstream &sampleFile)
{
    if(time == 0)
        sampleFile << "Time" << "\t" <<"KineticEnergy" << "\t" << "Potential Energy"   <<"\t" << "Temperature"  << endl;

    sampleKineticEnergy(*velocities);

    //The potentialEnergy is already calculated in the potential function

    sampleFile << time << "\t" << kineticEnergy << "\t" << potentialEnergy <<"\t" << measuredTemperature <<  endl;


    return;
}

void sampleKineticEnergy(mat &velocities)
{

    kineticEnergy = accu(square(velocities))/2 ;

    measuredTemperature = (2./3.)*kineticEnergy / velocities.n_rows;

    return;
}
