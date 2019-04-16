#include <stdio.h>
main()
{
  char string[1000]; //limiting string length of type char to 1000 characters
  int index = 0;
  int key;
  int stringLength = 0;
printf("Please Enter the Text you want to encrypt: \n");
scanf("%[^\n]s", string); //continues to scan characters until a newline character is reached
  while (string[index] != 0) // adds to length of string until null is reached
    {
        stringLength = index + 1;
        index++;
    }
index = 0; //re-initialising index variable to 0 so encryption can be performed on all string indexes
printf("Please enter the rotation amount (key): \n");
scanf("%d", &key); //the inputed key will be how much the input letter is 'shifted'
      while (index < stringLength)
        {
            
            if (string[index] < 65 || (string[index] > 90 && string[index] < 97))
                {
                    printf("%c", string[index], string[index]);
                }
            else
                {
                    if (string[index] >= 97 && string[index] <= 122)
                        {
                            string[index] = string[index] - 32;
                        }
                    string[index] = string[index] - 65;
                    if (string[index] + key < 0)
                        {
                            string[index] + key == string[index] + key + 26;
                        }
                    string[index] = (string[index] + key)%26;
                    string[index] = string[index] + 65;
                    if (string[index] < 65)
                        {
                            string[index] = string[index] + 26;
                        }
                    printf("%c", string[index], string[index]);
                }
            index++;
        }
}