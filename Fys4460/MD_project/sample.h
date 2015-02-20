#ifndef SAMPLE
#define SAMPLE

#include <fstream>
#include <armadillo>

using namespace arma;
using namespace std;

void sample(mat *atoms, mat *velocities, double time, ofstream &sampleFile);

void sampleKineticEnergy(mat &velocities);

#endif // SAMPLE

