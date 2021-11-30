#include <iostream>      /* IO */
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <cmath>

const int maxPayoff = 10000000;
const int n = 1000000; // number of games to simulate

int simulateGame() {
    int coinFlips = 0;
    while (true) {
        int coinToss = rand() % 2;
        // game is over if coinToss = 1, or if we have reached the maximum payoff.
        if (coinToss == 1 || coinFlips == (int) log2(maxPayoff)) {
            int gamePayOff = pow(2, coinFlips);
            return gamePayOff;
        }
        else {
            // coinToss = 0, continue game.
            coinFlips++;
        }
    }
}

int main() {
    srand(time(NULL));  // initiate random seed
    std::vector<double> expectedPayOffs;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // simulate a game
        int gamePayOff = simulateGame();
        // calculate expected payOff (average) for the i simulated games.
        sum += gamePayOff;
        double thisExpectedPayOff = (double) sum / i;
        expectedPayOffs.push_back(thisExpectedPayOff);
    }
    
    // write output to file
    std::ofstream file;
    file.open("stPetersburgOutput.txt");
    for (double expectedPayoff : expectedPayOffs) {
        file << expectedPayoff << std::endl;
    }
    file.close();

    return 0;
}