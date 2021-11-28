#include <iostream>      /* IO */
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <cmath>

// 300 visitors per day. a time unit is a second.
const int dayInSeconds = 24 * 60 * 60;
const double arrivalProbability = (double) 300 / dayInSeconds;
const int totalDays = 365 * 5;

int simulateHospitalDay() {
    int totalVisitors = 0;
    for (int i = 0; i < dayInSeconds; i++) {
        double random = (double) rand() / RAND_MAX;
        if (random < arrivalProbability) totalVisitors++;
    }
    return totalVisitors;
}

int main() {
    srand(time(NULL));  // initiate random seed
    std::vector<int> visitorsEachDay;

    for (int i = 0; i < totalDays; i++) {
        int visitors = simulateHospitalDay();
        visitorsEachDay.push_back(visitors);
    }
    
    // write output to file
    std::ofstream file;
    file.open("hospitalOutput.txt");
    for (int visitors : visitorsEachDay) {
        file << visitors << std::endl;
    }
    file.close();

    return 0;
}