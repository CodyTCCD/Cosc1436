/*
*Cody Price
* Lab #
* COSC 1436 fALL 2025
*/
#include <iostream>
//#=preprocessor directive
int main()
{
    //Every statement in C++ must end with a semicolon (;)
    //Statement - anything that does something in the language
    //std::cout << "Hello World!" << " " << "Your Name";
    //std::cout <<"Hello World!"<<" "<<"Your Name";
    //std::cout << "Hello World!" 
    //    << " " 
    //    << "Your Name";
    //std::cout << "Hello World";
    //std::cout << "Your Name";
    std::cout << "Hello World " << "Your Name" << std::endl;
    std::cout << "You are " << 20 << " years old" << std::endl;

    //identical to <<endl (\n)
    std::cout << "Hello World " << "Your Name\n";

    std::cout << "Hello World\nYour Name";
    std::cout << "Hello World\tYour Name";
    std::cout << "Hello World \"Your Name\"";
    std::cout << "C:\\Windows";
    //string Literals ("...")
    //"Whatever"
    // Escape sequence - special meaning to the compiler
    //  - starts with \ followed by a character
    //  /n -new line
    //  /t -tab
    //  \" -Double quote
    //  \\ -slash    

    //integer literals - one or more digits (f.e 20, 30, 450, 123 etc)

    //Floating Point Literals - one or more digits + fraction
    //3.14159 or 3E10 -3E10 3E-10

    //Variable - Named memory location where data is stored
    std::string name;
    name = "Cody";
    std::cout << "Hello World " << name;

    //var-decl ::=T id;
    //type = defines what can be stored in the variable and in what format
    int age;
    age = 20;
    std::cout << "you are " << age << " years old";


    // area of rectangle calculator (length x width)
    // A = lw
    std::string firstname;
    //int length; 
    //int width;
    int length = 10, width = 20;

    //length = 10; 
    //width = 20; 

    //uninitilized variable - YOU MUST assign a value to a variable before you read it   
    //int area;
    //area = 0;
    int area = 0;
    //area = length * width;

    std::cout << "Area of rectangle is " << area << std::endl;

    //2 different approches of variable declaration
    //Block - all variables together
    //int radius, diameter;
    //std::string circlename;

    //now i can use the variables
    int radius, diameter;
    //use radius, diameter

    std::string circlename;
    //use circlename



    double pi; 
    pi = 3.1459;

    char LetterGrade;
    letterGrade = 'A';

    bool isPassing;
    isPassing = true;

    //assignment is right associative (reads right to left)
    //length = 100;
    //width = 100;
    length=width=100


}
