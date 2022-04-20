#pragma once
#include <sstream>
#include <time.h>
using namespace std;

struct Timer{
    clock_t begin;
    int timeout;//giay
 
    Timer(int timeout) : begin(clock()), timeout(timeout){}
 
    bool timeOut(){
        return getElapseTime() >= timeout;
    }
 
    int getElapseTime(){
        return (clock() - begin) / CLOCKS_PER_SEC;
    }
  
    template <typename T>
    std::string to_string(T value)
    {
      //create an output string stream
      std::ostringstream os ;
      //throw the value into the string stream
      os << value ;
      //convert the string stream into a string and return
      return os.str() ;
    }
    string getTimeLeft(){
        int left = timeout - getElapseTime();
        int h = left / 3600;
        int m =  (left - h * 3600) / 60;
        int s = left % 60;     
        string ch = to_string(h);
		if(ch.length() == 1) ch = '0' + ch;
		string cm = to_string(m);
		if(cm.length() == 1) cm = '0' + cm;
		string cs = to_string(s);
		if(cs.length() == 1) cs = '0' + cs;
		if(left < 60) SetColor(WHITE);
		return ch + ':' + cm + ':' + cs;

    }
};

