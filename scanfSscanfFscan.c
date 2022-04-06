#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
//Basic IO. To open a file need a FILE *ptr also need #inlclude <stdlib.h>
FILE *afile;
//creates a var named text of 256 chars basically a long string
char *text = malloc(256); 

//creates a ptr to a char and alllocates 256 chars worth of memory. Basically a long string. 
//No \0 at end of string have to add it. Every Malloc needs a free()
char *text2 = malloc(256);

printf("\nTEST\n");

//fopen opens a file named IO.txt in read and write/append mode (a+) returns pointer.
// and it gets assigned to afile variable then if checks if it worked. 
//fopen is null if it doesn't work. 
if((afile = fopen("IO.txt", "a+")) == NULL)
{
    printf("Could not open file sorry...\n");
    exit(1); //kill program
}
printf("Sucessfully opened file for reading and writing mode.\n");
printf("\nType in your name then hit enter.\n");

//scanf reads from stdin and accepts whatever user types in as a string when they hit enter.
//%s read a string in up to first whitespace.
// if user types Aaron and hits enter Aaron is added to end of file.  if Aaron Posey then enter
// then Aaron should be added to end of file. If Aaron Posey needs to be appended use "%s %s".
//%*s means skip one string up to whitespace.  %*d would mean skip an int.
scanf("%*s %s %s", text, text2);


//works like printf but prints to a file named in first parameter in this case afile.
fprintf(afile,"%s Charles %s",text, text2);

text2 = "A New String!";
//sscanf doesn't use stdin but rather a string passed in, then does what scanf does 
//then places final product into third paramater passed into the function.
sscanf(text2, "%*s %s", text);
printf("\nAfter runnign sscanf the new val of text: %s\n", text);


//Every file opened needs to be closed!!!!!
fclose(afile);

//Every Malloc needs a free()!!!!
free(text);
free(text2);
    return 0;
}