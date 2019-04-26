/* This program performs the encryption and decryption of a message using the substitution cipher and rotation cipher.
The  
*/


#include <stdio.h>
void rotCiphE(void);
void rotCiphD(void);
void subCiphE(void);
void subCiphD(void);

main()
{
    int taskNum;
    do{
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
        subCiphE();
        break;
      case 4: printf("You chose task 4\n");
        subCiphD();
        break;
      default: printf ("You did not enter a valid integer for a task");
    }
    } while (taskNum != 0);

      
}
/* The below function implements task 1 (rotation cipher encryption given text to encrypt and key). It has no arguments or return values.
The variables required for the function are declared within the function. The function asks the user for the message to encrypt 
and with what key. It then performs the rotation on each letter individually. Each letter is scanned and encrypted individually with the encrypted 
letter being printed to the console. The function also recognises any message characters that are not letters and thus does not perform
the encryption on that charater (e.g. a space). Any letters that are entered as lowercase are converted to uppercase to perform the encryption. The
function is limited in that the message to encrypt must have a length less than 1000 characters. Datatype restrictions include that
the key inputed by the user must be an integer. The string is of type char.  
*/
void rotCiphE(void)
    {
        char string[1000]; //Declaring the string array which the user will input to encrypt as a message of less than 1000 characters. 
        int index = 0; //declaring an index variable initialised as zero so the stringlength can be counted. 
        int key; // declaring the variable which will be used to represent the key that the user inputs. 
        int stringLength; //declaring a variable to represent the length of the string. 
        scanf("%c", string);
        printf("Please type the message to encrypt and press enter: \n");
        scanf("%[^\n]s", string); //scans each element of the message text until a newline character is reached. 
        while (string[index] != 0) //loop to count the length of message text string and does so until the the null element of the string is reached.
            {
                stringLength = index + 1; //line that periodically counts length of string. '+1' is needed as index is initialed as '0'. 
                index++; //incrementing so the next element in the message text can be counted. 
            }
        index = 0; //re-initialising index variable to '0' so encryption can be performed on first character (note index '0' is the first character in a string).
        printf("Please type the key number and press enter: \n");
        scanf("%d", &key); //reads the inputed key number typed by the user and stores it in the 'key' variable. 
        while (index < stringLength) //loop that performs encryption on each character. 'index < stringlength' is used as the index variable is initialised as '0'.
            { 
        //The following flow control involves checking if the character is a not a letter by observing its ASCII value. Else it performs an encryption on the character.     
                if (string[index] < 65 || (string[index] > 90 && string[index] < 97)) //assesses if character is not a letter. 
                    {
                        printf("%c", string[index]); //prints non-letter character unmodified. '%c' converts the stored ASCII number to the character it represents. 
                    }
                else //the following code runs if the character is a letter. 
                    {
                        if (string[index] >= 97 && string[index] <= 122) //statement that convertes lowercase to uppercase. 
                            {
                                string[index] = string[index] - 32; //'-32' converts teh ASCII lowercase number its corresponding ASCII uppercase number. 
                            }
                    string[index] = string[index] - 65; //assigns each letter to the number it represents in the alphabet (i.e. ASCII for 'A' = 65 which it then gets assigned as '0' as it is the first letter).
                        if (string[index] + key < 0) //if this equation is < 0, the modulus operator will not work later. 
                            {
                                string[index] + key == string[index] + key + 26; //converts the negative number to a positive number by adding 26, This will not affect equation. 
                            }
                    string[index] = (string[index] + key)%26; //performs the encryption on character.
                    string[index] = string[index] + 65; //the new letter is converted back to its corresponding ASCII number. 
                        if (string[index] < 65) //assesses if the produced cipher character is not a letter (i.e. if 'Z' (ASCII 90) is encrypted by a rotation of 1, The cipher character would be whatever is represented by the ASCII number 91)
                            {
                                string[index] = string[index] + 26; // '+ 26' to cipher character converts the ASCII number of the character back to within the alphabet range (ASCII 65-90).
                            }                        
                            printf("%c", string[index]); //the %c converts the ASCII number of the new character to the character it represents. The character is printed to the console.  
                    }
                index++; //increments index to then perform encryption on next character. 
            }
            printf("\n"); //begins a new line after the cipher text. 
    }
    
/* The below function implements task 2 (rotation cipher decryption given text to decrypt and key). It has no arguments or return values.
The variables required for the function are declared within the function. The function asks the user for the message to decrypt 
and with what key. It then performs the reverse rotation on each letter individually. Each letter is scanned and decrypted individually with the decrypted 
letter being printed to the console. The function also recognises any message characters that are not letters and thus does not perform
the encryption on that charater (e.g. a 'space'). Any letters that are entered as lowercase are converted to uppercase to perform the decryption. The
function is limited in that the message to decrypt must have a length less than 1000 characters. Datatype restrictions include that
the key inputed by the user must be an integer. The string is of type char.  
*/
void rotCiphD(void)
    {
        char string[1000]; //Declaring the string array which will be the cipher the user wants to decrypt. 
        int index = 0; //declaring an index variable initialised as zero so the stringlength can be counted.
        int key; // declaring the variable which will be used to store the key that the user inputs. 
        int stringLength; //declaring a variable to represent the length of the cipher tex string. 
        scanf("%c", string);
        printf("Please type the message to decrypt and press enter: \n");
        scanf("%[^\n]s", string); //scans each element of the cipher text until a newline character is reached. 
        while (string[index] != 0) //loop to count the length of a cipher text string and does so until the the null element of the string is reached.
            {
                stringLength = index + 1; //line that periodically counts length of string. '+1' is needed as index is initialed as '0'.
                index++; //incrementing index so each element in the cipher text is counted. 
            }
        index = 0; //re-initialising index variable to 0 so decryption can be performed on all string cipher text letters. 
        printf("Please type the key number and press enter: \n");
        scanf("%d", &key); //reads the inputed key number typed by the user and stores it in the 'key' variable. 
        
        //The following flow control involves checking if the character is a not a letter by observing its ASCII value. Else it performs a decryption og the character. 
        while (index < stringLength) //loop that performs dencryption on each character. 'index < stringlength' is used as the index variable is initialised as '0'.
            {
            
                if (string[index] < 65 || (string[index] > 90 && string[index] < 97)) //assesses if character is not a letter.
                    {
                        printf("%c", string[index]); //prints non-letter character unmodified. '%c' converts the stored ASCII number to the character it represents.
                    }
                else //the following code runs if the character is a letter. 
                    {
                        if (string[index] >= 97 && string[index] <= 122) //assess if cipher letter is lowercase
                            {
                                string[index] = string[index] - 32; //converts lowercase to uppercase. 
                            }
                        string[index] = string[index] - 65; //assigns each letter to the number it represents in the alphabet (i.e. ASCII for 'A' = 65 which it then gets assigned as '0' as it is the first letter).
                        if (string[index] - key < 0) //if this equation is < 0, the modulus operator will not work later. 
                            {
                                string[index] - key == string[index] - key + 26; //converts the negative number to a positive number by adding 26, This will not affect equation. 
                            }
                        string[index] = (string[index] - key)%26; //equation tha performs decryption of cipher letter
                        string[index] = string[index] + 65; //the new letter is converted back to its corresponding ASCII number.
                        if (string[index] < 65)
                            {
                                string[index] = string[index] + 26;
                            }
                        printf("%c", string[index]); //the %c converts the ASCII number of the new character to the character it represents. The character is printed to the console.  
                }
            index++; //increments index so decryption can be performed on next cipher character. 
            }
            printf("\n"); //begins a new line after the cipher text. 
    }
    
/* The below function implements task 3 (substitution cipher encryption given message text and alphabet substitution). It has no arguments or return values.
The variables required for the function are declared within the function. The function asks the user for the message to encrypt. 
It then assesses each message letter individually and subs in the corresponding cipher letter it is assigned according to the given substitution alphabet. 
The cipher letter is then printed to the console. The function also recognises any message characters that are not letters and thus does not perform
the encryption on that charater (e.g. a 'space'). Any letters that are entered as lowercase are converted to uppercase to perform the encryption. The
function is limited in that the message to encrypt must have a length less than 1000 characters. The substitution alphabet and normal alphabet are of type char.  
*/    
void subCiphE(void)
    {
                char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //declaring the alphabet as a string so that letters can be assigned their coresponding cipher letters. 
                char sub[1000]; // declaring cipher substituion alphabet so alphabetic letters can be assigned their cipher letter. 
                int index = 0; // this variable is delcared so that it can be used to access elements in the alph string. 
                
                char message[1000]; //Declaring the message array which will be the message the user wants to encrypt. 
                int stringLength; //declaring variable which will be used to count the length of the message string. 
                int indexm = 0; //declaring an index variable initialised as zero so the stringlength can be counted.It will also be used to access elements of the message text. 
                scanf("%c", message);
                printf("Please enter sub alphabet: \n");
                scanf("%[^\n]s", sub);
                printf("Please type message to encrypt and press enter: \n");
                scanf("%[^\n]s", message); //continues to scan characters until a newline character is reached. 
                while (message[indexm] != 0) // adds to length of string until null is reached
                    {
                        stringLength = indexm + 1; //line that periodically counts length of the message string. '+1' is needed as index is initialed as '0'. 
                        indexm++; //incrementing indexm before loop runs again so each index is counted. 
                    }
                indexm = 0; //re-initialising indexm variable to 0 so encryption can be performed on all message characters. 
    
                //The following flow control involves checking if the message character is a not a letter by observing its ASCII value. Else it performs an encryption on the character. 
                for (indexm = 0; indexm < stringLength; indexm++) //loop that performs encryption on each character. 'indexm < stringlength' is used as the index variable is initialised as '0'. indexm is incremented after each loop so each character is executed on. 
                    {
                      if (message[indexm] < 65 || (message[indexm] > 90 && message[indexm] < 97)) //assess if message character is not a letter. 
                        {
                            printf("%c", message[indexm]); //prints non-letter character unmodified. '%c' converts the stored ASCII number to the character it represents.
                        }
    
                      else //the following code runs if the character is a letter. 
                        {
                            if (message[indexm] >= 97 && message[indexm] <= 122) //assesses whether the message character us lowercase. 
                                        {
                                            message[indexm] = message[indexm] - 32; //converts message character to uppercase.
                                        }
                            for (index = 0; index < 26; index++) //loop runs through each letter of the alph string and assesses if the message character matches. 
                                {
                                    if (message[indexm] == alph[index]) //the message character is found to match the alph character. 
                                        {
                                           printf("%c", sub[index]); //the message character is substituted with coressponding cipher character found at the same index to the message character in the alph string. The cipher character is printed to the console. 
                                        }   
                                }
                         }
            
                    }
                    printf("\n"); //begins a new line after the cipher text.
            
    }
    
/* The below function implements task 4 (substitution cipher decryption given cipher text and alphabet substitution). It has no arguments or return values.
The variables required for the function are declared within the function. The function asks the user for the cipher text to encrypt. 
It then assesses each cipher letter individually and subs in the corresponding message letter it is assigned according to the given substitution alphabet. 
The message letter is then printed to the console. The function also recognises any cipher characters that are not letters and thus does not perform
the decryption on that charater (e.g. a 'space'). Any letters that are entered as lowercase are converted to uppercase to perform the decryption. The
function is limited in that the message to encrypt must have a length less than 1000 characters. The substitution alphabet and normal alphabet are of type char.  
*/ 
void subCiphD(void)
    {
        char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //declaring the alphabet as a string so that letters can be assigned their coresponding cipher letters. 
                char sub[] =  "QWERTYUIOPASDFGHJKLZXCVBNM"; // declaring cipher substituion alphabet so alphabetic letters can be assigned their cipher letter. 
                int index = 0; // this variable is delcared so that it can be used to access elements in the alph string. 
    
                char message[1000];
                int stringLength;
                int indexm = 0;
                
                scanf("%c", message);
                printf("Please type message to encrypt and press enter: \n");
                scanf("%[^\n]s", message); //continues to scan characters until a newline character is reached. 
                
                while (message[indexm] != 0) // adds to length of string until null is reached
                    {
                        stringLength = indexm + 1; //line that periodically counts length of the cipher text string. '+1' is needed as index is initialed as '0'. 
                        indexm++; //incrementing indexm before loop runs again so each index is counted. 
                    }
                indexm = 0; //re-initialising indexm variable to 0 so decryption can be performed on all cipher characters. 
    
                //The following flow control involves checking if the cipher character is a not a letter by observing its ASCII value. Else it performs a decryption on the character. 
                for (indexm = 0; indexm < stringLength; indexm++) //loop that performs decryption on each character. 'indexm < stringlength' is used as the index variable is initialised as '0'. indexm is incremented after each loop so each character is executed on.
                    {
                      if (message[indexm] < 65 || (message[indexm] > 90 && message[indexm] < 97)) //assess if cipher character is not a letter
                        {
                            printf("%c", message[indexm]); //prints the non-letter character unmodified
                        }
    
                      else //the following code runs if the character is a letter
                        {
                            if (message[indexm] >= 97 && message[indexm] <= 122) //assesses if cipher character is lowercase
                                        {
                                            message[indexm] = message[indexm] - 32; //converts the lowercase letter to uppercase. 
                                        }
                            for (index = 0; index < 26; index++) //loop runs through each letter of the substitution alphabet string and assesses if the cipher character matches. 
                                {
                                    if (message[indexm] == sub[index]) //the cipher character is found to match the substitution alphabet character.
                                        {
                                           printf("%c", alph[index]); //the cipher character is substituted with coressponding alphabetic character found at the same index to the message character in the substitution alphabet string. The message character is printed to the console. 
                                        }   
                                }
                         }
            
                    }
                    printf("\n"); //begins a new line after the cipher text.

    }

