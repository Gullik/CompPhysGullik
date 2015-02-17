#ifndef ATOMS_H
#define ATOMS_H

#include <armadillo>

using namespace arma;


void createFCCLattice(mat *atoms, double cellLength, int nUnitCells);
void setBoltzmannVelocity(mat *velocities, double temperature);
void removeMomentum(mat &velocities);



#endif // ATOMS_H
