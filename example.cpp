//this source is wriiten with VC2013.

#include "Gray-Code/GrayCode.h"

int main(){
  GRAY_INT gNum1=2;//the internal value of gNum1 is 0x2. (it means 3 in Gray code expression)
  gNum1.Set(2);//the internal value of gNum1 is 0x2. (it means 3 in Gray code expression)
  gNum1.Int(2);//the internal value of gNum1 is 0x3. (it means 2 in Gray code expression)
  
  GRAY_INT gNum2=SetBit("0010");//the internal value of gNum2 is 0x2. (it means 3 in Gray code expression)
  
  gNum1+gNum2;//the internal value of gNum2 is 0x5. (it means 6 in Gray code expression)
  
  //in calculation, I translate the Gray codes into binary expression in default. 
  //You will be allowed to choose Gray code calculation in the future. 
  
  Addition2(gNum1,gNum2);//half translation (ten times slower)
  Addition6(gNum1,gNum2);//Gray code calculation (ten times slower)
  
  
  return 0;
}
