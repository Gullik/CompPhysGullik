#include <iostream>
#include <omp.h>
#include <armadillo>



using namespace std;

void testNeighbourCycling();

int main()
{
    cout << "Hello World" << endl;

    for(int i = 0 ; i < 10 ; i++)
    {
        cout << "At timestep: " << i << endl;

        testNeighbourCycling();

    }





}

void testNeighbourCycling()
{

//    cout << "Hello World" << endl;

    int noOfNeighbors = 3;
    int next_i,next_j,next_k;
    int prev_i, prev_j, prev_k;
    int i, j, k;
    int tid;

     arma::cube neighborVisits = arma::zeros( noOfNeighbors, noOfNeighbors, noOfNeighbors);


#pragma omp parallel private( i, j, k, next_i, next_j, next_k, prev_i, prev_j, prev_k, tid) shared(neighborVisits)
{

    #pragma omp for schedule(auto)
    for(i = 0 ; i < noOfNeighbors ; i ++)
    {
        for(j=0; j < noOfNeighbors ; j++)
        {
            for(k = 0; k < noOfNeighbors; k++)
            {
//                    tid = omp_get_thread_num();
//                    cout << " Thread # " << tid << " did " << i << " " << j << " " << k << endl;
//                    calculateForcesInsideCell(vec3(i,j,k),system);

                //Now atoms should be appended with the increasing neighboring cells
                //Could not find any neat way to do it, this is confusing and slow as is. Should work to do it a better way.
                next_i = i + 1;
                next_j = j + 1;
                next_k = k + 1;

                prev_i = i -1;
                prev_j = j -1;
                prev_k = k -1;

                if(i == noOfNeighbors - 1)
                    next_i = 0;

                if(j == noOfNeighbors - 1)
                    next_j = 0;

                if(k == noOfNeighbors - 1)
                    next_k = 0;

                if(i == 0)
                    prev_i = noOfNeighbors - 1;

                if(j == 0)
                    prev_j = noOfNeighbors - 1;

                if(k == 0)
                    prev_k = noOfNeighbors - 1;

//                #pragma omp critical
                {
                //With itself
                neighborVisits( i, j, k) += 1;

                //The top layer, so it cycles through i and j while k is constant

                neighborVisits(i,j,k) += 1;   neighborVisits(prev_i,   prev_j, next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(i,        prev_j, next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   prev_j, next_k) += 1;


                neighborVisits(i,j,k) += 1;   neighborVisits(prev_i,   j,      next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(i,        j,      next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   j,      next_k) += 1;

                neighborVisits(i,j,k) += 1;   neighborVisits(prev_i,   next_j, next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(i,        next_j, next_k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   next_j, next_k) += 1;


                //The front layer that is left


                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   prev_j,      k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   j,           k) += 1;
                neighborVisits(i,j,k) += 1;   neighborVisits(next_i,   next_j,      k) += 1;


                //The rest of the left side

                neighborVisits(i,j,k) += 1;   neighborVisits(i,        next_j,      k) += 1;
                }


            }
        }
    }
}

arma::cube testMatrix = 27 * arma::ones(noOfNeighbors,noOfNeighbors,noOfNeighbors);

//    cout << testMatrix << endl;

//    cout << neighborVisits << endl;

//    cout << neighborVisits - testMatrix << endl;

//    cout << arma::accu(testMatrix - neighborVisits) << endl;

if(arma::accu(testMatrix - neighborVisits) != 0)
{
    cout << "Test failed: wrong number of neighbourvisits" << endl;
    cout << neighborVisits << endl;
}

}

