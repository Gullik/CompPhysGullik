#include "neighborlist.h"
#include "list.h"





NeighborList::NeighborList(double cutOffLength, rowvec systemSize)
{


//    This should only contain atoms? and it needs a function to add and delete atoms as they leave the box territory,
//    or enter it
//    It also need an identification vector, like neighbor (i,j,k)

    //Setting up lists

    int noOfNeighbors = int(systemSize(0)/cutOffLength);

//    //Create the list

//    list_t *atomList = list_create();
//    list_iterator_t *iterator= list_createiterator(atomList);

//    //////////////////////////////////////
//    // Testing stuff
//    void *atomPointer1, *atomPointer2;

//    int test = 5;
//    int test2 = 2;

//    atomPointer1 = &test;
//    atomPointer2 = &test2;

//    list_addfirst(atomList, atomPointer1);
//    list_addfirst(atomList, atomPointer2);
//    list_addfirst(atomList, atomPointer1);

//    list_resetiterator(iterator);

////    int* t = static_cast <int*> (atomPointer1);
////    cout << *t << endl;
////    cout << atomPointer1 << endl;
////    cout << atomPointer2 << endl;

////    cout << static_cast <int*> (list_next(iterator)) << endl;
////    cout << static_cast <int*> (list_next(iterator)) << endl;

//    /////////////////////////////////////

    vector < int >  atomList;

    vector < vector < int > > rowList;

    vector< vector < vector < int >  > > gridList;

    vector< vector< vector< vector < int > > > > cubeList;

    for(int i = 0; i < noOfNeighbors ; i++)
    {
        rowList.push_back(atomList);
    }


    for(int j = 0; j < noOfNeighbors; j++ )
    {
        gridList.push_back(rowList);
    }

    for(int j = 0; j < noOfNeighbors; j++ )
    {
        cubeList.push_back(gridList);
    }

    m_neighborList = cubeList;

    m_noOfNeighbors = noOfNeighbors;          //Storing it in the class for convenience


}

void NeighborList::sortAtoms(mat &atoms, rowvec systemSize)
{
    //This function clears the neighbor lists of atoms, and the assigns the atoms again in the correct neighborhoods

    clear();      //Clears the nighborLists of atoms

    int i,j,k;

//    cout << "Is the atoms sorted?" << endl;

//    cout << "systemsize = " << system->systemSize().x << "; #Nabolag = " << m_noOfNeighbors << "; neighborLength = "
//         << system->systemSize().x/m_noOfNeighbors << endl;

    for(int n = 0; n < atoms.n_rows ; n++ )
    {

//        //Each atom needs to be placed in it's neighborhood


        i = int (atoms.row(n)(0)/ systemSize(0) * m_noOfNeighbors );
        j = int (atoms.row(n)(1)/ systemSize(1) * m_noOfNeighbors );
        k = int (atoms.row(n)(2)/ systemSize(2) * m_noOfNeighbors );

//        cout << "Atom " << n << endl;
//        cout << "Har position " <<  atoms.row(n) << " og er i box " << i << j << k << endl;


        m_neighborList[i][j][k].push_back(n);


    }

//    cout << m_neighborList[0][0][0].size() << endl;

}

void NeighborList::clear()
{
  //Clear all neighborhoods for atoms, to be used at the start of assigning them

    for(int i = 0 ; i < int( m_neighborList.size() ); i++)
    {
        for(int j = 0 ; j < int( m_neighborList[0].size() ); j++)
        {
            for(int k = 0 ; k < int( m_neighborList[0][0].size() ); k++)
                m_neighborList[i][j][k].clear();
        }
    }

}
