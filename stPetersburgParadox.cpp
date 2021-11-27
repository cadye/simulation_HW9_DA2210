#include <iostream>      /* IO */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <cmath>

const int maxPayoff = 10000000;
const int n = 1000; // maximum number of games to simulate

int main() {
    srand(time(NULL));  // initiate random seed
    std::vector<int> currentValues;
    std::vector<int> expectedPayOffs;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            // simulate a game
            int coinFlips = 0;
            while (true) {
                int coinToss = rand() % 2;
                if (coinToss == 1) {
                    int gamePayOff = pow(2, coinFlips);
                    currentValues.push_back(gamePayOff);
                    break;
                }
                else {
                    coinFlips++;
                }
            }
        }
        int sum = 0;
        for (int value : currentValues) {
            sum += value;
        }
        int thisExpectedPayOff = sum / currentValues.size();
        expectedPayOffs.push_back(thisExpectedPayOff);
        currentValues.clear();
    }

    for (int expectedPayOff : expectedPayOffs) {
        std::cout << expectedPayOff << std::endl;
    }
    

    return 0;
}