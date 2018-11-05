#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
char delimiters[] = " \".,;:!?)("; // Prose delimiters
char buf[100]; // Buffer for a line of keyboard input
char str[1000]; // Stores the prose to be tokenized
str[0] = '\0'; // Set 1st character to null

size_t str_len = sizeof(str);
size_t buf_len = sizeof(buf);
printf("Enter some prose that is less than %d characters.\n Terminate input by entering an empty line:\n", str_len);
// Read multiple lines of prose from the keyboard
while(true){
      if(!fgets(buf, buf_len, stdin)) // Read a line of input
      {
        printf("Error reading string.\n");
        return 1;
      }
      if(buf[0] == '\n') // An empty line ends input
        break;

      if(strcat_s(str, str_len, buf)) // Concatenate the line with str
        {
        printf("Maximum permitted input length exceeded.\n");
        return 1;
        }
}

//printf("The words in the prose that you entered are:\n", str);
// Find and list all the words in the prose
unsigned int word_count = 0;
char * pWord = strtok(str, delimiters); // Find 1st word
  if(pWord)
    {
      do
      {
        printf("%-18s", pWord);
        if(++word_count % 5 == 0)
          printf("\n");
        pWord = strtok(NULL, delimiters); // Find subsequent words
      }
  while(pWord); // NULL ends tokenizing
    printf("\n%u words found.\n", word_count);
  }
  else
  printf("No words found.\n");
  return 0;
  }
