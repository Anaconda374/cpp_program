#include<iostream>
#include<string>
#include<bitset> //A class emulates an array of bool elements.

/* 
   "Bitwise operators" are operators that operate on 'ints' and 'unsigned_ints'(or other types that can hold "int values") at the binary level. This means they look directly at the binary digits or bits of an integer.
 *
 NOTE:
   Because signed ints('int') have "the sign bit", performing bitwise operations may change the sign bit or not, this will cause undefined behaviors, so using "unsigned types" with the bitwise operators is recommended.
 */

int main()
{
/* "Bitwise Shift"-- e.g. intVal << numShiftBits.
    "the right operand" must not be nagetive and must be less than the number of bits in the result. Otherwise, the operation may cause overflow. 
 */
    unsigned char bits = 3; // type 'char' has 8 bits, binary( bits ) = 00000011 .
    
    unsigned char shifted_bits1 =bits << 2; 
    //inserts two 0_valued bits on the right, so the 'shifted_bits' is 00001100 .
    printf("%d\n",shifted_bits1);
    
   unsigned char shifted_bits2 =bits << 8; 
   //inserts eight 0_valued bits on the right, so the 'shifted_bits2' is 00000000 .
    printf("%d\n",shifted_bits2);
   
   
/* 
    "Type Promotion": promoting a short length type(e.g. char) to a long length type(e.g. int) will leave the value unchanged but adds 0 bits to the high order positons(fore bits).
 */
    unsigned int long_bits1 = bits << 8;// 'long_bits' = 0...01100000000 (32bits).
    
    //Shift Operators are left associative:
    unsigned int long_bits2 = bits << 8 >> 1; //initializer equals to " (bits << 8 ) >> 1 ".
    std::cout<< long_bits1 << std::endl; 
    std::cout<< long_bits2 << std::endl; 

    
// "NOT" operator -- e.g. ~intVal: generates a new value with the all bits of its operand inverted.  
    
    unsigned char notBits = ~bits;//"notBits" = 11111100 .
    printf("%d\n",notBits);
    
    
// "AND &" , "OR |", "XOR ^" operators:
// Say we want to store the results of a quiz(pass'1' / fail'0') of 30 students .
    unsigned long quiz = 0;//Object 'quiz' has 32 bits(0_valued) which is enough to store the results.
    
// The NO.27 student has passed,and we store the pass value--'1' at NO.27_bit of 'quiz'(start from NO.0).
    quiz |= 1UL << 27 ;
    // equivalent to " quiz = quiz | (1UL << 27) ", bitwise operations on int literals is valid.
    std::cout<< std::bitset<32>(quiz) << std::endl;
    
    
// "Update the Status": 
/* Say after reexamined the quiz, discovered the NO.27 student actually failed, there are 2 ways
 * to update the status of NO.27_bit:
 */ 
    //1. using AND& , NOT~ ,Left_shift<< :
    unsigned long quiz_updated1 = quiz & ~(1UL << 27);
    std::cout<< std::bitset<32>(quiz_updated1) << std::endl;
    
    //2. using XOR^, Left_shift<< :
    unsigned long quiz_updated2 = quiz ^ (1UL << 27);
    std::cout<< std::bitset<32>(quiz_updated2) << std::endl;



/* Using "bit mask" to check or undate the status of a bit(isolate the particular bits,and  mask others) by using logic gates:
   say after loading all results of the students, we want to check if one of the students passed :
 */  
  unsigned long total_quiz = 123567890; // assuming the results.
    std::cout<< std::bitset<32>(total_quiz) << std::endl;
    //Check the result of the student NO.9:
    bool no9Status = total_quiz & (1UL << 9); //only NO.9 bit remains 1, all other bits are 0s.
    std::cout<< no9Status << std::endl;


    return 0;
}