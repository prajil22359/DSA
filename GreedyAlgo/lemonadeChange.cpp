// track five and 10 rupee notes, and try to give 10 and 5 first when given 20 rupee notes, only then
// three five rupee notes. See if ever you get the notes count in negative, that means you dont have 
// enough, so return false.

#include <iostream>
using namespace std;
#include <vector>

class Solution {
    public:
    bool lemonadeChange(vector<int> &bills) {
        int billsOfFive = 0, billsOfTen = 0;

        for(int i : bills){

            if(i == 5){
                billsOfFive++;
            }
            else if (i == 10) {
                billsOfFive--;
                billsOfTen++;
            }
            else if(i == 20){
                if(billsOfTen >= 1 && billsOfFive >= 1) {
                    billsOfTen--;
                    billsOfFive--;
                } else {
                    billsOfFive -= 3;
                }
            }
        
            if(billsOfFive < 0 || billsOfTen < 0) {
                    return false;
            }
        }
        return true;
    }
};