#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool verifyRegistration(char registration[]){
    if(strlen(registration)!=10){
        return false;
    }
    for(int i=0;i<2;i++){
        if(!isalpha(registration[i])){
            return false;
        }
    }
    for(int i=2;i<4;i++){
        if(!isdigit(registration[i])){
            return false;
        }
    }
    for(int i=4;i<6;i++){
        if(!isalpha(registration[i])){
            return false;
        }
    }

    for(int i=6;i<10;i++){
        if(!isdigit(registration[i])){
            return false;
        }
    }
}
int main() {
    char registration[11];
    printf("Enter registration number: ");
    scanf("%s", registration);
    if (verifyRegistration(registration)){
        printf("Accept: Vehicle registration number is valid.\n");
    }
    else{
        printf("Reject: Vehicle registration number is invalid.\n");
    }
    return 0;
}