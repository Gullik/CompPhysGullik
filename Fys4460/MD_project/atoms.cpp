#include <atoms.h>
#include <lib.h>

extern double mass;
extern double boltzmann;


void createFCCLattice(mat *atoms, double cellLength, int nUnitCells)
{

    //Creating the vectors that specifies the single atoms position in the cell lattice
    rowvec r1 = zeros <rowvec> (atoms->n_cols);
    rowvec r2 = zeros <rowvec> (atoms->n_cols);
    rowvec r3 = zeros <rowvec> (atoms->n_cols);
    rowvec r4 = zeros <rowvec> (atoms->n_cols);



    rowvec R = zeros<rowvec>(atoms->n_cols);

    r1 << 0             << 0             << 0            ;
    r2 << cellLength/2  << cellLength/2  << 0            ;
    r3 << 0             << cellLength/2  << cellLength/2 ;
    r4 << cellLength/2  << 0             << cellLength/2 ;

    int latticeNumber = 0;

    for(int i = 0; i < nUnitCells ; i++)
    {
        for(int j = 0; j < nUnitCells ; j++)
        {
            for(int k = 0; k < nUnitCells ; k++)
            {
                //Four atoms need to be put in each lattice cell, they have the position:R_ij = R_i + r_j;
                //where R_ij are their position, R_i is the lattice position and r_j is the position in the lattice

                R << i << j << k ;

                atoms->row(latticeNumber    ) = R*cellLength + r1;
                atoms->row(latticeNumber + 1) = R*cellLength + r2;
                atoms->row(latticeNumber + 2) = R*cellLength + r3;
                atoms->row(latticeNumber + 3) = R*cellLength + r4;

                latticeNumber += 4;

            }
        }
    }

    return;
}

void setBoltzmannVelocity(mat *velocities, double temperature)
{
    //temperature is is in Kelvin, should change

    double mean = 0.;
    double standardDeviation = sqrt(temperature);

    long int idum = -1;

    for(int i = 0; i < velocities->n_rows; i++)
    {
        velocities->at(i,0) = randomGaussian(mean, standardDeviation, &idum);
        velocities->at(i,1) = randomGaussian(mean, standardDeviation, &idum);
        velocities->at(i,2) = randomGaussian(mean, standardDeviation, &idum);
    }

    return;
}

void removeMomentum(mat &velocities)
{
    rowvec momentum = zeros <rowvec> (3);

    momentum << accu(velocities.col(0)) << accu(velocities.col(1)) << accu(velocities.col(2));

    momentum = momentum/velocities.n_rows;

    velocities.each_row() -= momentum;
}



