#include <integrator.h>
#include <potential.h>

extern double mass;
extern rowvec systemSize;

bool firstStep = true;

void step(mat *atoms, mat *velocities, mat *forces, double dt)
{
    if(firstStep)
    {
        calculateForces(*atoms, *forces);
        firstStep = false;
     }

    updateVelocities(*velocities, *forces, dt);

    move(*atoms, *velocities, dt);

    //Boundary conditions
    periodicBoundary(*atoms);

    //Calculate forces
    calculateForces(*atoms, *forces);

    updateVelocities(*velocities, *forces, dt);


    return;
}

void move(mat &atoms, mat &velocities, double dt)
{
    atoms = atoms + velocities*dt;

    return;
}

void periodicBoundary(mat &atoms)
{

    for(int i = 0; i < atoms.n_rows; i++)
    {
        //Setting the atom back if it goes over
        if(atoms(i,0) > systemSize(0))
            atoms(i,0) -= systemSize(0);
        if(atoms(i,1) > systemSize(1))
            atoms(i,1) -= systemSize(1);
        if(atoms(i,2) > systemSize(2))
            atoms(i,2) -= systemSize(2);

        //Setting the atom back if it goes under
        if(atoms(i,0) <= 0)
            atoms(i,0) += systemSize(0);
        if(atoms(i,1) <= 0)
            atoms(i,1) += systemSize(1);
        if(atoms(i,2) <= 0)
            atoms(i,2) += systemSize(2);
    }

}


void updateVelocities(mat &velocities, mat &forces, double dt)
{
//    cout << velocities.row(10) << endl;
//    cout << forces.row(10) << endl;

    velocities = velocities + (forces*dt/(2));

    return;
}
