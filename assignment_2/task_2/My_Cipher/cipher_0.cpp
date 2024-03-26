#include <bits/stdc++.h>
using namespace std;
void affine_cipher_0(string word, bool isDecipher){
    // If decipher bool is false then we need to cipher else we need to decipher
    if(!isDecipher){
        int a, b, c;
        cout << "Please Enter 3 positive integers 'a, b, c' to use them as keys in the encryption.\n";
        cout << "Make sure that (a * c) mod 26 = 1\n";
        cout << "Fact \"You can use the standard formula {a = 5, b = 8, c = 21} by entering -1 -1 -1.\"\n";
        cin >> a >> b >> c;
        // I made the standard like what the prof. did in the sample to help people with bad math to start faster.
        if(a == -1 && b == -1 && c == -1){
            a = 5;
            b = 8;
            c = 21;
        }
        // Handling cin fail errors and other logical errors.
        while(cin.fail() || (a * c) % 26 != 1 || a < 0 || b < 0 || c < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 3 positive integers when (a * c) mod 26 = 1.\n";
            cout << "You can enter -1 -1 -1 for the standard formula {a = 5, b = 8, c = 21}\n";
            cin >> a >> b >> c;
            if(a == -1 && b == -1 && c == -1) {
                a = 5;
                b = 8;
                c = 21;
                break;
            }
        }
        string word_encrypted;
        int key;
        for(char &k : word){
            if(isalpha(k)){
                // Making the key first before doing the mod 26
                // to check if it is negative then we got another operation to do with.
                // using (toupper(k) - 'A') to get the value from it.
                // 'A' here is equal to its integer value of the ascii table 65.
                key = a * (toupper(k) - 'A') + b;
                if(key < 0){
                    key = -1 * key;
                    key %= 26;
                    key = 26 - key;
                }
                else{
                    key %= 26;
                }
                // Now adding the char to the word_encrypted.
                // char(key + 'a') is using the ascii code to get the character it is more like char(key + 65).
                word_encrypted += char(key + 'A');
            }
            else{
                word_encrypted += k;
            }
        }
        // I made the encryption print uppercase words because that is what I saw in the sample from the prof.
        cout << " the word \"" << word << "\" after encryption is: " << word_encrypted << '\n';
    }
    else{
        int a, b, c;
        cout << "Please Enter 3 positive integers 'a, b, c' to use them as keys in the decryption process.\n";
        cout << "Make sure that (a * c) mod 26 = 1\n";
        cout << "Fact \"You can use the standard formula {a = 5, b = 8, c = 21} by entering -1 -1 -1.\"\n";
        cin >> a >> b >> c;
        // I made the standard like what the prof. did in the sample to help people with bad math to start faster.
        if(a == -1 && b == -1 && c == -1){
            a = 5;
            b = 8;
            c = 21;
        }
        // Handling cin fail errors and other logical errors.
        while(cin.fail() || (a * c) % 26 != 1 || a < 0 || b < 0 || c < 0){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter 3 positive integers when (a * c) mod 26 = 1.\n";
            cout << "You can enter -1 -1 -1 for the standard formula {a = 5, b = 8, c = 21}\n";
            cin >> a >> b >> c;
            if(a == -1 && b == -1 && c == -1) {
                a = 5;
                b = 8;
                c = 21;
                break;
            }
        }
        string word_decrypted;
        int key;
        for(char &k : word){
            // If the current char is an alpha letter then we add it after encrypting it.
            if(isalpha(k)){
                // Making the key first before doing the mod 26
                // to check if it is negative then we got another operation to do with.
                // using (toupper(k) - 'a') to get the value from it.
                // 'a' here is equal to its integer value of the ascii table 97.
                key = c * ((tolower(k) - 'a') - b);
                // If the key is negative then we calculate the mod by another way as shown in the if condition.
                if(key < 0){
                    key = -1 * key;
                    key %= 26;
                    key = 26 - key;
                }
                // Else we just take the mod normally.
                else{
                    key %= 26;
                }
                // Now adding the char to the word_decrypted.
                // char(key + 'a') is using the ascii code to get the character it is more like char(key + 97).
                word_decrypted += char(key + 'a');
            }
            // Else we add it directly.
            else{
                word_decrypted += k;
            }
        }
        // I made the decryption print lowercase words because that is what I saw in the sample from the prof.
        cout << " the word \"" << word << "\" after decryption is: " << word_decrypted << '\n';
    }
}
int main(){
    while(true){
        bool isDecipher = false;
        string word;
        cout << "Ahlan ya user ya habibi.\nWhat do you like to do today?\n";
        cout << "1) Cipher a message\n2) Decipher a message\n3) End\n";
        string choice;
        cin >> choice;
        // Making the choice lowercase to handle any upper case problems.
        for(char &k : choice){
            k = tolower(k);
        }
        // Next conditions trying to handle user input as much as possible.
        // If the user chose to cipher then decipher is false.
        if(choice == "1" || choice == "1)" || choice == "cipher"){
            isDecipher = false;
        }
        // If the user chose to decipher then decipher is true.
        else if(choice == "2" || choice == "2)" || choice == "decipher"){
            isDecipher = true;
        }
        else if(choice == "exit" || choice == "3" || choice == "end" || choice == "3)" ){
            break;
        }
        else{
            cout << "\"" << choice <<"\" Is and invalid choice.\nRestarting the program.\n";
            continue;
        }
        // If decipher is false then we cipher.
        if(!isDecipher){
            cout << "Please enter the word that you want to cipher.\n";
            // I'm using cin.ignore() because we are using cin before it which cause problems with getline().
            cin.ignore();
            getline(cin,word);
            while(true){
                cout << "Which Cipher do you like to choose?\n";
                cout << "1) Affine cipher.\n2)cipher.\n3)cipher." << endl;
                string cipher_name;
                cin >> cipher_name;
                // Making the cipher_name lowercase to handle any upper case problems.
                for(char &k : cipher_name){
                    k = tolower(k);
                }
                if(cipher_name == "1" || cipher_name == "1)" || cipher_name == "Affine"){
                    affine_cipher_0(word,isDecipher);
                    break;
                }
                else if(cipher_name == "2" || cipher_name == "2)" /*|| cipher_name == ""*/){
                    break;
                }
                else if(cipher_name == "3" || cipher_name == "3)" /*|| cipher_name == ""*/){
                    break;
                }
                else{
                    cout << "\"" << choice <<"\" Is and invalid choice.\n";
                    continue;
                }
            }

        }
        // If decipher is true then we decipher.
        else{
            cout << "Please enter the word that you want to decipher.\n";
            // I'm using cin.ignore() because we are using cin before it which cause problems with getline().
            cin.ignore();
            getline(cin,word);
            while(true){
                cout << "Which Cipher do you like to choose?\n";
                cout << "1) Affine cipher.\n2)cipher.\n3)cipher." << endl;
                string cipher_name;
                cin >> cipher_name;
                // Making the cipher_name lowercase to handle any upper case problems.
                for(char &k : cipher_name){
                    k = tolower(k);
                }
                if(cipher_name == "1" || cipher_name == "1)" || cipher_name == "affine"){
                    // Sending string and bool to use them in the function.
                    affine_cipher_0(word, isDecipher);
                    break;
                }
                else if(cipher_name == "2" || cipher_name == "2)" /*|| cipher_name == ""*/){
                    break;
                }
                else if(cipher_name == "3" || cipher_name == "3)" /*|| cipher_name == ""*/){
                    break;
                }
                else{
                    cout << "\"" << choice <<"\" Is and invalid choice." << endl;
                    continue;
                }
            }
        }
    }
    return 0;
}
