#include <stdio.h>
void rotCiphE(void);
void rotCiphD(void);
void subCiphE(void);
void subCiphD(void);
main()
{
    int taskNum;
    do
        {
             printf("Please enter an integer for task choice and press enter key (i.e. type '1' for Task 1).\nIf you want to exit the program Please enter '0'\n");
                scanf("%d", &taskNum);
                switch (taskNum)
                    { case 1: printf("You chose task 1\n");
                        rotCiphE();
                        break;
                      case 2: printf("You chose task 2\n");
                        rotCiphD();
                        break;
                      case 3: printf("You chose task 3\n");
                        subCiphE();
                        break;
                      case 4: printf("You chose task 4\n");
                        subCiphD();
                        break;
                      default: printf("The integer entered was either not valid or you exited the program");
                        break;
                    }
        } while(taskNum != 0);


      
}
// Rotation Cipher Encryption Function
void rotCiphE(void)
    {
        char string[1000]; //limiting string length of type char to 1000 characters
        int index = 0;
        int key;
        int stringLength = 0;
        printf("Please type the Message you would like to encrypt: \n");
        scanf("%[^\n]s", string); //continues to scan characters until a newline character is reached
        while (string[index] != 0) // adds to length of string until null is reached
            {
                stringLength = index + 1;
                index++;
            }
        index = 0; //re-initialising index variable to 0 so encryption can be performed on all string indexex
        printf("Please type your rotation cipher key to encrypt the message: \n");
        scanf("%d", &key);
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
        int key;
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
                        printf("%c", string[index]);
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
                        printf("%c", string[index]);
                }
            index++;
        }
    }
void subCiphE(void)
    {
                char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                char sub[] =  "QWERTYUIOPASDFGHJKLZXCVBNM";
                int index = 0;
    
                char message[] = "PLEASE get milk AT THE SHOPS";
                int stringLength;
                int indexm = 0;
                scanf("%[^\n]s", message); //continues to scan characters until a newline character is reached
                while (message[indexm] != 0) // adds to length of string until null is reached
                    {
                        stringLength = indexm + 1;
                        indexm++;
                    }
                indexm = 0;
    
                for (indexm = 0; indexm < stringLength; indexm++)
                    {
                      if (message[indexm] < 65 || (message[indexm] > 90 && message[indexm] < 97))
                        {
                            printf("%c", message[indexm]);
                        }
    
                      else 
                        {
                            if (message[indexm] >= 97 && message[indexm] <= 122)
                                        {
                                            message[indexm] = message[indexm] - 32;
                                        }
                            for (index = 0; index < 26; index++)
                                {
                                    if (message[indexm] == alph[index])
                                        {
                                           printf("%c", sub[index]);
                                        }   
                                }
                         }
            
                    }
            
    } 

void subCiphD(void)
    {
        char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                char sub[] =  "QWERTYUIOPASDFGHJKLZXCVBNM";
                int index = 0;
    
                char message[] = "HSTQLT utz DOSA QZ ZIT LIGHL";
                int stringLength;
                int indexm = 0;
                scanf("%[^\n]s", message); //continues to scan characters until a newline character is reached
                while (message[indexm] != 0) // adds to length of string until null is reached
                    {
                        stringLength = indexm + 1;
                        indexm++;
                    }
                indexm = 0;
    
                for (indexm = 0; indexm < stringLength; indexm++)
                    {
                      if (message[indexm] < 65 || (message[indexm] > 90 && message[indexm] < 97))
                        {
                            printf("%c", message[indexm]);
                        }
    
                      else 
                        {
                            if (message[indexm] >= 97 && message[indexm] <= 122)
                                        {
                                            message[indexm] = message[indexm] - 32;
                                        }
                            for (index = 0; index < 26; index++)
                                {
                                    if (message[indexm] == sub[index])
                                        {
                                           printf("%c", alph[index]);
                                        }   
                                }
                         }
            
                    }

    }