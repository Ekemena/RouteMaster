#include<stdio.h>
#include<string.h>
#include "signin.h"
#include "signup.h"
void login()
{
    printf("1. I don't have an account..Help me to create one.\n 2. I am an Existing user let me sign in.\n");
    int choice;
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        signup();
        break;
    case 2:
        signin();
        break;

    default:printf("Enter a valid input\n");
            break;
    }

}

void main()
{
    login();
}