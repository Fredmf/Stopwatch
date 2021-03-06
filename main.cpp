//Copyright © 2014 Fred Mariowitsch Flügge <fmfluegge@gmail.com>
//This program is free software. It comes without any warranty, to
//the extent permitted by applicable law. You can redistribute it
//and/or modify it under the terms of the Do What The Fuck You Want
//To Public License, Version 2, as published by Sam Hocevar. See 
//http://www.wtfpl.net/ for more details.

#include "stopwatch.h"
#include <iostream>
#include <cstdio> //for exit

using namespace std;

int main(){
    stopwatch printTest,total,empty;
    total.startClock();
    
    total.init("Total time");
    empty.init("empty overhead");
    printTest.init("Print time");
    
    empty.startClock();
    empty.stopClock();
    empty.printNS();
    
    printTest.startClock();
    cout << "\nRemember, 1 Second equals 1,000,000,000 Nanoseconds or 1,000 Milliseconds\n\n";
    cout << "From Wikipedia, the free encyclopedia\nA nanosecond (ns) is an SI unit of time equal to one billionth of a second (10−9 or 1/1,000,000,000 s). One nanosecond is to one second as one second is to 31.710 years.\n\n";
    printTest.stopClock();
    total.stopClock();
    
    cout << "Printing the information took" << endl;
    printTest.printNS();
    cout << "or " << printTest.getDurationInMS()<< " Milliseconds " << endl;
    
    total.printMS();
    exit(EXIT_SUCCESS);
}