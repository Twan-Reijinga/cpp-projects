#include <iostream>
#include <chrono>
#include <math.h>
#include <iomanip>
#include "exponent_log.h"

class StopWatch{
    public:
        void start(){
            startTime = std::chrono::system_clock::now();
        }
        double elapsedTimeSinceStart(){
            endTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedTime = endTime-startTime;
            return elapsedTime.count();
        }
    private:
        std::chrono::system_clock::time_point startTime, endTime;
};

double linearPower(double base, int exp){
    if ( exp < 0 ) return 1.0 / linearPower(base, -exp);
    double result = 1.0;
    for ( int i=0; i<exp; i++){
        result *= base;
    }
    return result;
}

int checkCorrectness(){
    const int TEST_LIMIT = 15;
    for (int i = -TEST_LIMIT; i <= TEST_LIMIT; i++){
        if ( linearPower(1.23, i) != logPower(1.23,i) ){
            std::cout << std::setprecision(30) << linearPower(1.23, i) << "   " << logPower(1.23,i);
            std::cout << "not the same for i = " << i << std::endl;
            return 1;
        }
    }
    return 0;
}

void checkTiming(){
    StopWatch s;

    int times = 10000;
    int exponent = 10;
    for (int i=0; i<5; i++){
        double timeLinear, timeLogarithmic;
        s.start();
        for (int i=0; i<times; i++){
            double dummy = linearPower(1.23,exponent);
        }
        timeLinear = s.elapsedTimeSinceStart();
        s.start();
        for (int i=0; i<times; i++){
            double dummy = logPower(1.23,exponent);
        }
        timeLogarithmic = s.elapsedTimeSinceStart();
    
        std::cout << timeLinear << "\t" << timeLogarithmic << std::endl;
        exponent *= 10;
    }
}

int main(){

    if ( checkCorrectness() == 1) return 1; // report error
    // checkTiming();
    return 0;
}