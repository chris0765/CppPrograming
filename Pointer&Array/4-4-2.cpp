#include <iostream>
#include <cstring>

using namespace std;

void print_reversed(char* Str)
{
    char* word = strtok(Str, " ");
    while(word)
    {
        for(int i= strlen(word)-1; i>=0; i--)
            cout<<word[i];
        word = strtok(NULL, " ");
        if(word)
            cout<<" ";
        else
            cout<<"."<<endl;
    }
}

int main()
{
    char* arr_to_reverse = NULL;
    {
        char value;
        int size = 0;
        int maxSize = 1;

        arr_to_reverse = new char[maxSize + 1];
        while ((value = getchar()) != EOF) {
            if (value == '.')
                break;
            if (size == maxSize) {
                char* temp = new char[maxSize + 2];
                arr_to_reverse[size] = '\0';
                strcpy(temp, arr_to_reverse);
                delete[] arr_to_reverse;
                arr_to_reverse = temp;
                maxSize = maxSize + 1;
            }
            arr_to_reverse[size++] = value;
        }
        arr_to_reverse[size] = '\0';
    }
    print_reversed(arr_to_reverse);
    return 0;
}