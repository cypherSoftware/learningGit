#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    char name[31];
    printf("Yo girl enter your name.\n");
    scanf("%s", name);

    printf("Hello %s\n",name);

    
    //single character, integer type
    char letter = 'A';  //ascii equivalent to 65.  65 is whats stored in mem.

    //string literal, ptr to string created without mallac and always 
    //stored as **read-only** data.
    char *name1 = "Engineer Aaron";

    //character array stored on the stack can be altered
    char name2[] = "Engineer Aaron";

    //Exact same as one above
    char name3[] = {'E','n','g','i','n','e','e','r',' ','A','a','r','o','n','\0'};

    //pointer to char type and holds up to 128 elements stored on stack
    char name4[128];

    //pointer to a char type and holds up to 128 elements stored on heap
    char *name5 = malloc(128);

    //copies contents from one string into another and adds null terminator.  
    //second parameter here is a string literal.
    //name4 wil have 12bytes copied +1 for null terminator.
    strcpy(name4, "Engineer Aaron");
    printf("%s\n", name4); //stops at \0 so only prints Engineer Aaron
    printf("\nlength of name4 (%d)\n", strlen(name4)); // will be 12 still doesn't count \0.
    
    
    //This part shouldn't work because name1 is readonly 
    //comment next line out to proceed. Uncomment to see proof.
    //strcpy(name1, name4);


    //working with malloced char* put on the heap
    strcpy(name5, "Engineer AA-ron");
    printf("\nname5 (%s)\n", name5);
    
    //accessing an element in a char string[]
    //When created as an array then can use name4[idx] to access
    //What's really going on is name4[idx] => *(arr + idx)
    //This means it goes to the array at 0 which is where
    //name4 is pointing to then jumps idx times size of array element
    //which was declared as char or one byte.
    //ex. [element1-1byte, element2-1byte element3-1byte] 
    //ex[2]                |
    //after the jump that spot in memory is dereffernced and whats stored
    //in memory is accessed.
    printf("\nname4[0] = (%c)\n",name4[0]); //Should be E
    printf("\n0[name4] = (%c)\n",0[name4]); //Should be E
    printf("\n*(name4 + 0) = (%c)\n", *(name4 + 0));//Should be E
    printf("\n*(0 + name4) = (%c)\n", *(0+ name4));//Should be E

    //Modifying char arrays
    //Engineer Aaron the space in between should be element 8 if E is 0
    //name4[8] 8[name4] *(name4 + 8) *(8 + name4) all of these should work
    name4[8] = '-'; //Should now be set to Engineer-Aaron

    printf("\nname4 is now: (%s)\n", name4);

    name4[8] = '\0';//adding null teminator to spot 8 to shorten string
    //Shoul now be just Engineer

    printf("\nAdded a null Terminator and now name4 is: (%s)\n",name4);
    
    //accessing name5 malloced on heap as char*
    printf("\nname5 can be accessed with array notation\n");
    printf("\nname5[2] shoud be 'g' and really is: (%c)\n", name5[2]);
    printf("\nname5 can be accessed by ptr arrithmatic\n");
    printf("\n*(name5 + 1) should be 'n' and is really: (%c)\n",*(name5 + 1));    
    return 0;

}

