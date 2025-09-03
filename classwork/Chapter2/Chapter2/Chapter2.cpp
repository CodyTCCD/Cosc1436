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
}
