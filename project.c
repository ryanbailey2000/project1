#include <stdio.h>
void rotCiphE(void);
void rotCiphD(void);
main()
{
    int taskNum;
    printf("Please enter an integer for task choice and press enter key (i.e. type '1' for Task 1)\n");
    scanf("%d", &taskNum);
    switch (taskNum)
    { case 1: printf("You chose task 1\n");
        rotCiphE();
        break;
      case 2: printf("You chose task 2\n");
        rotCiphD();
        break;
      case 3: printf("You chose task 3\n");
        break;
      case 4: printf("You chose task 4\n");
        break;
      default: printf ("You did not enter a valid integer for a task");
    }
      
}
// Rotation Cipher Encryption Function
void rotCiphE(void)
    {
        char string[] = "ATTACK AT SUNRISE"; //limiting string length of type char to 1000 characters
        int index = 0;
        int key = 1;
        int stringLength;
        scanf("%[^\n]s", string); //continues to scan characters until a newline character is reached
        while (string[index] != 0) // adds to length of string until null is reached
            {
                stringLength = index + 1;
                index++;
            }
        index = 0; //re-initialising index variable to 0 so encryption can be performed on all string indexex
        while (index < stringLength)
            { 
            
                if (string[index] < 65 || (string[index] > 90 && string[index] < 97))
                    {
                        printf("%c", string[index]);
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
                        printf("%c", string[index]);
                    }
                index++;
            }
    }
void rotCiphD(void)
    {
        char string[] = "BUUBDL BU TVOSJTF"; //limiting string length of type char to 1000 characters
        int index = 0;
        int key = 1;
        int stringLength;

        scanf("%[^\n]s", string); //continues to scan characters until a newline character is reached
        while (string[index] != 0) // adds to length of string until null is reached
            {
                stringLength = index + 1;
                index++;
            }
        index = 0; //re-initialising index variable to 0 so encryption can be performed on all string indexes
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
                        if (string[index] - key < 0)
                            {
                                string[index] - key == string[index] - key + 26;
                            }
                        string[index] = (string[index] - key)%26;
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
