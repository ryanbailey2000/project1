#include <stdio.h>
main()
{
  char string[1000];
  int index = 0;
  int key;
  int stringLength = 0;
printf("Please Enter the Text you want to encrypt: \n");
scanf("%s", string);
  while (string[index] != 0) // adds to length of string until null is reached
    {
        stringLength = index + 1;
        index++;
    }
index = 0;
printf("Please enter the rotation amount (key): \n");
scanf("%d", &key);
      while (index < stringLength)
        {
            
            if (string[index] < 65 || (string[index] > 90 && string[index] < 97))
                {
                    printf("%c = %d\n", string[index], string[index]);
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
                    printf("%c = %d\n", string[index], string[index]);
                }
            index++;
        }
}