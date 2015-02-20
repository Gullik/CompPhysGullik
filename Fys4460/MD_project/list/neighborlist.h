#ifndef NEIGHBORLIST_H
#define NEIGHBORLIST_H

#include <vector>
#include <armadillo>

#include "list.h"



using namespace std;
using namespace arma;

class NeighborList
{
private:
    vector< vector <vector < vector < int > > > >  m_neighborList;
    double m_noOfNeighbors;
    double m_cutOffLength;
public:
    NeighborList(double cutOffLength, rowvec systemSize);
    void sortAtoms(mat &atoms, rowvec systemSize);
    void clear();


//    vector<vector<vector<vector<Atom*> > > >  &neigborList() {return m_neighborList;}
//    double &noOfNeighbors() {return m_noOfNeighbors;};
//    double cutOffLength() {return m_cutOffLength;}
//    void ghostCells(System *system); //Not implemented yet, not sure if I will.


};

#endif // NEIGHBORLIST_H
