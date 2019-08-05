#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong    
    int count = 4;
    string numbers = "0123456789";
    string lowerCase = "abcdefghijklmnopqrstuvwxyz";
    string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string specialChar = "!@#$%^&*()-+";
    bool ContainsNumber = true;
    bool ContainsLowerCase = true;
    bool ContainsUpperCase = true;
    bool ContainsSpecialChar = true;

    for(int i = 0; i < password.length(); i++) {

        char temp = password.at(i);

        if(ContainsNumber == false 
        && ContainsLowerCase == false 
        && ContainsUpperCase ==false 
        && ContainsSpecialChar == false) {
            break;
        }
        
        if(ContainsNumber == true) {
            size_t found = numbers.find(temp);
            if(found != string::npos) {
                count--;
                ContainsNumber = false;
                // cout << "Numbers = " << temp << endl;
            }
        }  
        if(ContainsLowerCase == true) {
            size_t found = lowerCase.find(temp);
            if(found != string::npos) {
                count--;
                ContainsLowerCase = false;
                // cout << "Lower Case = " << temp << endl;
            }
        }   
        if(ContainsUpperCase == true) {
            size_t found = upperCase.find(temp);
            if(found != string::npos) {
                count--;
                ContainsUpperCase = false;
                // cout << "Upper Case = " << temp << endl;
            }
        }
        if(ContainsSpecialChar == true) {
            size_t found = specialChar.find(temp);
            if(found != string::npos) {
                count--;
                ContainsSpecialChar = false;
                // cout << "Special Character = " << temp << endl;
            }
        }
        
        
    }

    if(count + password.length() < 6) {
        count += 6 - (count + password.length());
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
