#ifndef INTEGRATOR
#define INTEGRATOR

#include <armadillo>

using namespace arma;

void step(mat *atoms, mat *velocities, mat * forces, double dt);
void move(mat &atoms, mat &velocities, double dt);
void updateVelocities(mat &velocities, mat &forces, double dt);
void periodicBoundary(mat &atoms);

#endif // INTEGRATOR

