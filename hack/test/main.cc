 #include "buffoon.h"
 #include <string>
 #include <iostream>
 
 int main() {
   std::string str = "{\"payload\": \"value\"}";
   
   const auto payload = Buffoon::Buffoon::findValueByKey(str, "payload");
   if(payload.empty()) {
       std::cout << "payload not found\n";
   }
   else {
       std::cout << payload << std::endl;
   }
   
   return 0;   
 }