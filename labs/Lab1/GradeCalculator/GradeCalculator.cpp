/*
Cody Price
Lab 1
COSC 1436 FALL 2025
*/
#include <iostream>
#include <string>
// GradeCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



void main()
{
    double labGrade1 = 0, labGrade2 = 0;
    double labGrade3 = 0, labGrade4 = 0;
    double examGrade1 = 0, examGrade2 = 0;
    double examGrade3 = 0, participationGrade = 0;
    double finalExamGrade = 0;







    
    std::cout << "Please enter your name: ";
    std::string userName;
    std::getline(std::cin, userName);
    //user input for name and sets up showing name throughout the project

    std::cout << "Please enter lab 1: ";
    std::cin >> labGrade1;
    std::cout << "Please enter lab 2: ";
    std::cin >> labGrade2;
    std::cout << "Please enter lab 3: ";
    std::cin >> labGrade3;
    std::cout << "Please enter lab 4: ";
    std::cin >> labGrade4;
    //user inputs for lab grades

    std::cout << "Please enter exam 1: ";
    std::cin >> examGrade1;
    std::cout << "Please enter exam 2: ";
    std::cin >> examGrade2;
    std::cout << "Please enter exam 3: ";
    std::cin >> examGrade3;
    //user inputs for exam grades

    std::cout << "Please enter participation: ";
    std::cin >> participationGrade;
    //user input for participation grade

    std::cout << "Please enter final exam: ";
    std::cin >> finalExamGrade; 
    //user input for final exam grade

    std::cout << "\n";
    std::cout << userName << ", your lab grades are: \n";
 
    std::cout << "Lab 1 = " << labGrade1 << std::endl;
    std::cout << "Lab 2 = " << labGrade2 << std::endl; 
    std::cout << "Lab 3 = " << labGrade3 << std::endl;
    std::cout << "Lab 4 = " << labGrade4 << std::endl;
    //shows the user their lab grades before calculation
  
    std::cout << "\n";
    std::cout << userName << ", your exam grades are: \n";
    std::cout << "Exam 1 = " << examGrade1 << std::endl;
    std::cout << "Exam 2 = " << examGrade2 << std::endl;
    std::cout << "Exam 3 = " << examGrade3 << std::endl;
    //shows the user their exam grades before calculation

    std::cout << "\n";
    std::cout << userName << ", your other grades are: \n";

    std::cout << "Participation = \n";
    std::cout << "Final Exam = \n";
    //shows the user their participation and final exam before calculation

    std::cout << std::endl;
    std::cout << userName << ", your class grade is: \n";

    std::cout << "Lab Average (65%) = \n";
    std::cout << "Exam Average (20%) = \n";
    std::cout << "Participation (5%) = \n";
    std::cout << "Final Exam (10%) = \n";
    std::cout << "Class Average = \n";
    //shows the user all of their caclulated grades
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
