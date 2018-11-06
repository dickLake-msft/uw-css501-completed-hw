/*
* File:   CompressedString.cpp
* Author: PNewland
*
* Created on October 25, 2018
*/

#include "CompressedString.h"

CompressedString::CompressedString(string input){
  //assumes string of only letters
  //need to handle invariants probably
  //compress it
  compress(input);

  //display the compression percentage
  double basecomp = (double)this->mashed.size()/(double)input.size();
  int pcomp = (1.0-basecomp)*100;
  cout<<"percentage compressed:"<<pcomp<<"%"<<endl;
}

//compresion is O(n) as we loop through once
void CompressedString::compress(const string &pass){
  //compress it to size,letter if size>1
  //store it in local mashed
  int count=0;
  char let=' ';
  vector<char>temp(pass.begin(), pass.end());
  vector<char>::iterator pit;
  for(pit=temp.begin(); pit<=temp.end(); pit++){
    //look at printf calls
    //cout<<*pit<<endl;
    if(let!=*pit){
      //store last in compression
      if(count>=1)
      {
        //need to do this count/9 times to store really long sets of chars
        while(count>9){
            count -=9;
            this->mashed.push_back('9');
            this->mashed.push_back(let);
        }
        if(count>1){
          this->mashed.push_back('0'+count);
        }
        this->mashed.push_back(let);
        //cout<<count<<endl;
      }
      //put the new letter in the buffer
      //try handling digits by adding 100 before storing?
      count=1;
      let=*pit;
    }
    else{
      count+=1;
    }
  }
  //quicktest for what is going into mashed
  cout<<"compressed to:";
  for(pit=this->mashed.begin(); pit!=this->mashed.end(); pit++){
    cout<<*pit;
  }
  cout<<endl;

}

//decompression is O(n)as we loop through once
string CompressedString::decompress() const {
  //unwind the compression
  vector<char> relaxed;
  vector<char>::const_iterator pit;
  for(pit=this->mashed.begin(); pit<this->mashed.end(); pit++){
    int val = *pit-'0';
    if(val>1 && val<10){
      char let = *(++pit);
      for(int i=0; i<val; i++){
        relaxed.push_back(let);
      }
    }
    else{
      relaxed.push_back(*pit);
    }
  }
  string temp(relaxed.begin(), relaxed.end());
  return temp;
}


ostream& operator<<(ostream &outStr, const CompressedString &store){
  outStr<<(store.decompress());
  return outStr;
}
