#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include <armadillo>
#include <fstream>

using namespace std;
using namespace arma;

//ofstream* open(const char *statefile);

void save(mat *atoms, mat *velocities, ofstream &file);



#endif // SAVE_LOAD_H
