//this source is wriiten with VC2013.

#include "Gray-Code/GrayCode.h"

int main(){
  GRAY_INT gNum1=2;//the internal value of gNum1 is 0x2. (it means 3 in Gray code expression)
  gNum1.Set(2);//the internal value of gNum1 is 0x2. (it means 3 in Gray code expression)
  gNum1.Int(2);//the internal value of gNum1 is 0x3. (it means 2 in Gray code expression)
  
  GRAY_INT gNum2=SetBit("0010");//the internal value of gNum2 is 0x2. (it means 3 in Gray code expression)
  
  gNum1+gNum2;//the internal value of the answer is 0x7. (it means 5 in Gray code expression)
  gNum1-gNum2;//the internal value of the answer is 0x1. (it means 1 in Gray code expression)
  gNum1&gNum2;//the internal value of the answer is 0x2. (it means 3 in Gray code expression)
  gNum1++;//the internal value of gNum1 is 0x6. (it means 4 in Gray code expression)
  
  //in calculation, I translated the Gray codes into binary expression before. 
  //However, you can use the Gray code calculation now. 
  //multiplication and devision are not implemented yet.
  
  
  return 0;
}
