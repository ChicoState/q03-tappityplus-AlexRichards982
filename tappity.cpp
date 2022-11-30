#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference){
  ref_str = reference;
  ref_len = reference.length();
}

//Provide the input to be compared to the reference. Before this 
//function is called, the input should be considered an empty string
void tappity::entry(std::string input){
  in_str = input;
  in_len = input.length();
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference(){
  if(ref_len >= in_len){
    return ref_len - in_len;
  }
  return in_len - ref_len;
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each 
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function 
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy(){
  double max_len = ref_len;
  int min_len = in_len;
  int num_correct = 0;
  if(in_len > ref_len){
    max_len = in_len;
    min_len = ref_len;
  }
  for(auto i=0; i<min_len; i++){
    if(ref_str[i] == in_str[i]){
      num_correct++;
    }
  }
  
  return num_correct / max_len * 100;
}
