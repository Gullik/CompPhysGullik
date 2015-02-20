#include "potential.h"

extern vec systemSize;
extern double epsilon;
extern double potentialEnergy;


void calculateForces(mat &atoms, mat &forces)
{
    rowvec rij = zeros < rowvec > (3);

    double distanceNeg2 = 0;
    double distanceNeg6 = 0;
    double distanceNeg12 = 0;

    double forceMagnitude = 0;

    //Resetting the force
    forces = zeros <mat> (forces.n_rows,3);
    potentialEnergy = 0;

    for(int i = 0; i < atoms.n_rows; i++)
    {
        for(int j = i + 1; j < atoms.n_rows; j++)
        {
            rij = atoms.row(j) - atoms.row(i);

            if( rij(0) > systemSize(0)/2. )
                rij(0) -= systemSize(0);
            if( rij(0) < -systemSize(0)/2. )
                rij(0) += systemSize(0);

            if( rij(1) > systemSize(1)/2. )
                rij(1) -= systemSize(1);
            if( rij(1) < -systemSize(1)/2. )
                rij(1) += systemSize(1);

            if( rij(2) > systemSize(2)/2. )
                rij(2) -= systemSize(2);
            if( rij(2) < -systemSize(2)/2. )
                rij(2) += systemSize(2);

//         cout <<  " vs " << rij(0) << endl;

            distanceNeg2 = pow(norm(rij), -2);
            distanceNeg6 = pow(distanceNeg2, 3);
            distanceNeg12 = pow(distanceNeg6, 2);

            forceMagnitude =  24 * ( 2*distanceNeg12 - distanceNeg6  ) * distanceNeg2;

            forces.row(i) -= forceMagnitude * rij;
            forces.row(j) += forceMagnitude * rij;

            //Calculating the potential energy since we already know the length beetween the atoms
            potentialEnergy +=  4*(distanceNeg12 - distanceNeg6);
        }
    }

    return;
}
