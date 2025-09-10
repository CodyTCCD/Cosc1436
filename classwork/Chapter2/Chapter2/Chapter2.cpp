/*
*Cody Price
* Lab #
* COSC 1436 fALL 2025
*/
#include <iostream>
#include <string>
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

    char letterGrade;
    letterGrade = 'A';

    bool isPassing;
    isPassing = true;
    area = length * width;
    //assignment is right associative (reads right to left)
    //length = 100;
    //width = 100;
    length = width = 100;

    //std::cout << length; //verify length is correct







    //arithmetic operators
    // arith_op :: + | - | * | /(divide is slash) | %
    length = length + 10;
    width = width - 20;

    //int divisuib ::= int / int produces an int, remainder is lost
    int result = 10 / 3; // = 3 (keeps it whole number. is called integer division)
   
    // modulus is remainder and ONLY works for integral types
    int remainder = 10 % 3; // = 1

    int negativelength = -length;

    //scope - lifetime of a variable 
    { //starting a new block
        int newVariable1 = 10;
        double newvariable2 = 45.7;
      //any variables decared in a block (the curly braces)
    };
    {
      //  char newVariable1 +'A';
    }
  //std::cout << newVariable1;

//strings C++ 
    // assign value using assignment operator
  std::string studentName;
  studentName = "Bob";

  studentName = studentName + " Wilson";

  //literal - great for static values
  //variables - great for writable values
//named constant - variable that has a constant value
  const double pi = 3.14159;

  // A = Pi *R^2
  double areaCircle = pi * (radius * radius);

  const int NumberOfLabGrades = 5;
  const int NumberOfExamGrades = 4;

  //cannot write to a constant
 // Pi = 140;



}
