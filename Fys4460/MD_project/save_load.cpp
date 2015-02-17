#include "save_load.h"


#include <cstdlib>



void save(mat *atoms, mat *velocities, ofstream &file)
{

//    cout << "saving state" << endl;

    file << atoms->n_rows << endl;
    file << "The is an optional comment line that can be empty." << endl;


    for(int i = 0; i < atoms->n_rows; i++)
        file << "Ar " << atoms->at(i,0) << " " <<  atoms->at(i,1) << " " <<  atoms->at(i,2) << " " <<
                velocities->at(i,0) << " " <<  velocities->at(i,1) << " " <<  velocities->at(i,2) << endl;


    return;
}

