#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <iostream>

using namespace std;

/*  Bitfield look up table
*   32 bits first 8 bits identify node. Other 28 bits can be a message
*   0000 0001 0000 0000 0000 0000 0000 0000 = Node 4
*   0000 1000 0000 0000 0000 0000 0000 0000 = Node 8
    00001000000000000000000000000000
*   0000 1100 0000 0000 0000 0000 0000 0000 = Node 12
*   0001 0000 0000 0000 0000 0000 0000 0000 = Node 16
*/

//plan 
//instead of char send uint32_t via client
//server grabs code and looks it up to identify which node sent it and what the message is.
void printBits(uint32_t bitField)
{
    int numBits = 31; //32 bits but only 31 shifts to get to end.
    uint32_t bitToTest = -1;
    char bitPrintArr [32]= {}; //zero out all bits

    //run through all 32 bits create string of 1's and 0's
    for (int i = 0; i < 32; i++)
    {
        //shift 1 to bit location wanted. AND with bitfield to get 1 or 0 add answer to bitPrintArr
        bitToTest = (bitField & (1 << numBits));
        if (bitToTest == 0)
        {
            bitPrintArr[i] = '0';
        } 
        else
        {
            bitPrintArr[i] = '1'; 
        }

        numBits --; //Resolved 1 bit move down to next bit. Working left to right starting at most significant bit.
    }//end for loop

    //print out bitField
    for(int k = 0; k < 32; k++ )
    {
        cout << bitPrintArr[k];

    }
        cout << endl;

    return;

}

int main () 
{
    //quick test
    uint32_t testVar = 1;
    uint32_t nodeId;
    
    //for (int i =0; i < 32; i++)
    //{
        //shift 1 bit 32 times and print result
        
      //  printBits(testVar<< i);
    //}
    testVar =1;
    testVar = testVar << 24;
    testVar = testVar | 25165825;
    nodeId = testVar; //nodeId has same message
  printf("Set testvar to 1 then shiffted <<23 then OR'd with 1 and now its (0x%x)\n", testVar);
  printf("Bitfield is:\n");
  printBits(testVar);  
  printf("Now shift left << 8 and back >> 8 to clear node id out and just leave message\n");
 
  testVar = testVar << 8;
  testVar = testVar >> 8;
  printBits(testVar);

  printf("\nShifted nodeId  >> 24 and bits are: ");
  nodeId = nodeId >> 24;
  printBits(nodeId);
  printf("\nThe decimal version of nodeId: %d\n", nodeId);

    //testVar = 4294967295;

   // if (testVar == 0xffffffff)
   // {
    //    cout << "4294967295 and 0xffffffff must be the same thing" << endl;

  //  }
    /*printBits(testVar);
    cout << "Before shift" << endl;
    cout << testVar << endl;

    cout << "\nShift 26" <<  endl;

    testVar = (testVar << 26);
    cout << testVar << endl;
    cout << "Expected: 67108864" << endl;
    cout << "Running printBits Expect:\n00000100000000000000000000000000" << endl; 
    printBits(testVar);*/
    return 0;
}
/*
bool xor_bit ( bool a , bool b ) {
// xor two bits, without using ^.


    if ( a == 1 && b == 0){
        return 1;
    }
    else if (a == 0 && b == 1){
        return 1;
    }
    else {
        return 0;
    }
}
uint32_t xor_word ( uint32_t a , uint32_t b) {
// xor two words , without using ^; instead call xor_bit for every bit.
int test;
uint32_t result; //Result to return
char theBits[33]; // Build a string of bits to later convert to uint32_t
int numShifts = 31; //32 bits so 31 shifts is Most Significant Bit

//loop through get 2 bits at a time and call xor_bit()
 for (int i = 0; i<32; i++){
     //a & (1 << numshifts) will shift the 1 to that position then AND it.  
     //ex: 1000 AND 1000 returns 1000 but 1000 AND 0100 returns 0000 (which is false or zero)
     //All other bits ANDed against zeros will return zeros
     if( xor_bit(a & (1<<numShifts), b & (1<<numShifts))){
         theBits[i] = '1';
        
     }
     else{
         theBits[i]= '0';
        
     }
     numShifts --; //decrement numshifts so next most significant bit is evaluated next round
     theBits[33] = '\0';   //set Null character to make strtol() work properly
     }
 

//change theBits to an int and cast it as uint32_t
result = (uint32_t)strtol(theBits, NULL, 2);
return result;
}

int main () {
uint32_t a = 0xaabbccdd;
uint32_t b = 0x11223344;
uint32_t result;

// xor a and b by calling xor_word
result = xor_word(a,b);

// Print out the result as a hexadecimal number
    printf("The values %X and %X xor'ed are: \n %X \n", a, b, result);
}*/




