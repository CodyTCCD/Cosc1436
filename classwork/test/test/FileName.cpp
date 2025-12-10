
//Cody Price
//Lab 1
//COSC 1436 FALL 2025
*
#include <iostream>
#include <string>
#include <iomanip> 
//Needed for fixed and setprecision



int main()
{
    int labGrade1 = 0, labGrade2 = 0;
    int labGrade3 = 0, labGrade4 = 0;
    int examGrade1 = 0, examGrade2 = 0;
    int examGrade3 = 0, participationGrade = 0;
    int finalExamGrade = 0;
    double calcLabGrade = 0, calcExamGrade = 0;
    double calcClassAverage = 0;
    //last 3 are double for weighted results (97.88)

    std::cout << "Lab 1 - Grade Calculator" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl;
    std::cout << std::endl;
    //Program for the header


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
    std::cout << "Please enter final exam: ";
    std::cin >> finalExamGrade;
    //user input for participation and final exam grade

    std::cout << std::endl;
    std::cout << userName << ", your lab grades are: " << std::endl;

    std::cout << "Lab 1 = " << labGrade1 << std::endl;
    std::cout << "Lab 2 = " << labGrade2 << std::endl;
    std::cout << "Lab 3 = " << labGrade3 << std::endl;
    std::cout << "Lab 4 = " << labGrade4 << std::endl;
    //shows the user their lab grades before calculation

    std::cout << std::endl;
    std::cout << userName << ", your exam grades are: \n";
    std::cout << "Exam 1 = " << examGrade1 << std::endl;
    std::cout << "Exam 2 = " << examGrade2 << std::endl;
    std::cout << "Exam 3 = " << examGrade3 << std::endl;
    //shows the user their exam grades before calculation

    std::cout << std::endl;
    std::cout << userName << ", your other grades are: " << std::endl;

    std::cout << "Participation = " << participationGrade << std::endl;
    std::cout << "Final Exam = " << finalExamGrade << std::endl;
    //shows the user their participation and final exam

    std::cout << std::endl;
    std::cout << userName << ", your class grade is: " << std::endl;

     //set output to be fixed to 2 decimal points
    std::cout << std::fixed << std::setprecision(2);

    //calculate lab average
    calcLabGrade = (labGrade1 + labGrade2 + labGrade3 + labGrade4) / 4.0;

    std::cout << "Lab Average (65%) = " << calcLabGrade << " %" << std::endl;

    //calculate exam average
    calcExamGrade = (examGrade1 + examGrade2 + examGrade3) / 3.0;

    std::cout << "Exam Average (20%) = " << calcExamGrade << " %" << std::endl;

    std::cout << "Participation (5%) = " << participationGrade << " %" << std::endl;
    std::cout << "Final Exam (10%) = " << finalExamGrade << " %" << std::endl;
    //shows the participation and final exam again for clarification to user

    //calculate Class Average
    calcClassAverage = (calcLabGrade * .65) + (calcExamGrade * .2) + (participationGrade * .05) + (finalExamGrade * .1);

    std::cout << "Class Average = " << calcClassAverage << " %" << std::endl;
    //shows the user their overall class average
    //shows the user all of their caclulated grades
}