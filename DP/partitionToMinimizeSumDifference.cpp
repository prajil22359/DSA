#include<iostream>
using namespace std;
#include<vector>

// how to solve: hera partitioning is not possible for every targetsum k. 
// subset with target sum qn ma gareko thyau -> returning if partitioning is possible for a targetSum k.
// tara tyasko lagi intermediary ma hamile sabai target 0 to k ko lagi nikaleko thyau. 
// k tyasobhae totalSum rakhda all possible s1 values aucha. as s1 ranges from 0 to totalSum.
// we will use that dp array. for all possible target sum subset partition, we get s1. we can easily
// find s2 as totalSum - s1. then abs(s1-s2) lai minimize garne.

