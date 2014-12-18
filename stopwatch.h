#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <string>

#include <chrono>
namespace ch = std::chrono;

/*
 formula and proof, revursive time average
 http://people.revoledu.com/kardi/tutorial/RecursiveStatistic/Time-Average.htm
 */

typedef struct{
    ch::nanoseconds duration;
    ch::high_resolution_clock::time_point start,stop;
    std::string name;
    
    void init(std::string n){
        name=n;
    }
    void startClock(void){
        start = ch::high_resolution_clock::now();
    }
    void stopClock(void){
        stop = ch::high_resolution_clock::now();
        duration=stop-start;
    }
    void printNS(void){
        std::cout << name << " : " << duration.count()<< " ns\n";
    }
    void printMS(void){
        std::cout << name << " : " << (double)duration.count()/1000000.0<< " ms\n";
    }
    double getDurationInMS(void){
        return (double)duration.count()/1000000.0;
    }
    double getDurationInNS(void){
        return duration.count();
    }
} stopwatch;

#endif // STOPWATCH_H