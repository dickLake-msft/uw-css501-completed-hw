/*
 * File:   main.cpp - driver for HW4
 * Author: PNewland
 * HW4
 * Created on October 25, 2018
 */

#include <cstdlib>
#include <iostream>
#include "CompressedString.h"

using namespace std;

int main(){
  CompressedString longtest("wwwwwwwwwwhaaaaaabbbatttt");
  cout<<"original is:"<<longtest<<endl;
  cout<<"..."<<endl;
  CompressedString shortest("wut");
  cout<<"original is:"<<shortest<<endl;
  return 0;
}
