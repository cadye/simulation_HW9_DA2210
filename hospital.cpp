#include <iostream>      /* IO */
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <cmath>


int simulateHospital() {

}

int main() {
    srand(time(NULL));  // initiate random seed


    
    // write output to file
    std::ofstream file;
    file.open("hospitalOutput.txt");
    file << "l" << std::endl;
    file.close();

    return 0;
}