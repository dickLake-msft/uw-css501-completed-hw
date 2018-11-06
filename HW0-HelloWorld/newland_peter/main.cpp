/* 
 * File:   main.cpp
 * Author: Peter Newland
 * Assignment: HW0
 * Created on September 29, 2018
 */

#include <cstdlib>
#include <iostream>

using namespace std;

double PowerUp(float, int);
void PowerCalc();


int main() {
    /*
    * In the future I would like technology to reduce our travel times
    * while somehow reducing the waste caused by advances in technology.
    */
    
    PowerCalc(); //run the PowerCalc method
    
    return 0;
}



double PowerUp(float base, int power)
{
    //store the base
    double total=base;
    if(power>99)
        power=99;
    if(power<-99)
        power=-99;
    
    //store the power sign
    bool negPower=false;
    if(power<0)
    {
        negPower=true;
        power*=-1;
    }
    
    for(int i=1; i<power; i++)
    {
      total*=base;  
    }
    
    if(negPower)
        return 1/total;
    else
        return total;
}


void PowerCalc(){
    float workBase;
    float workPower;
    
    //initial prompt
    cout<<"Welcome to the PowerCalc\n";
    cout<<"This little program will return the value of a given number to the given power.\n";
    cout<<"(power limits are +/-99 due to value limits)\n\n";
    //while loop to run until the input is the exit command
    while(true){
        workBase=0;
        workPower=0;
        //prompt for base
        cout<<"Please enter a base number (Enter '0' to exit the program):  ";
        cin>>workBase;
        cout<<"the base number is "<<workBase<<"\n";
        if((int)workBase==0)
            break;
        //prompt for power, reject nonintegers (for now)
        cout<<"Please enter a power for the base:  ";
        cin>>workPower;
        cout<<"the power number is "<<workPower<<"\n";

        //run PowerUp
        cout<<"calculating "<<workBase<<"^"<<workPower<<"yields: "<<PowerUp(workBase,(int)workPower)<<"\n";
    }
}

