/*
Cody Price
Lab 2
COSC 1436 FALL 2025
*/
#include <iostream>
#include <iomanip> 

int main()
{
    // Program introduction
    std::cout << "Monthly Loan Interest Calculator" << std::endl;
    std::cout << "Cody Price" << std::endl;
    std::cout << "COSC 1436 Fall 2025" << std::endl << std::endl;

    // Variables
    int loanAmount = 0;
    double interestRate = 0.0; double monthlyPayment = 0.0;
    double totalPayments = 0.0; double totalInterest = 0.0;
    double interest = 0.0; double paymentThisMonth = 0.0; 
    double newBalance = 0.0;

    // Loan Amount Prompt
    do
    {
        std::cout << "Please enter loan amount ($1 - $1000): ";
        std::cin >> loanAmount;
        if (loanAmount < 1 || loanAmount > 1000)
        {
            std::cout << "That value is invalid." << std::endl;
        }
    } while (loanAmount < 1 || loanAmount > 1000);

    // Interest Rate Prompt
    do
    {
        std::cout << "Please enter the interest rate (%): ";
        std::cin >> interestRate;
        if (interestRate < 1.0 || interestRate > 100.0)
        {
            std::cout << "That value is invalid." << std::endl;
        }
    } while (interestRate < 1.0 || interestRate > 100.0);

    interestRate = interestRate / 100;

    // Monthly Payment Prompt
    do
    {
        std::cout << "How much do you want to pay each month? ";
        std::cin >> monthlyPayment;
        if (monthlyPayment < 0 || monthlyPayment > loanAmount)
        {
            std::cout << "That value is invalid." << std::endl;
        }
    } while (monthlyPayment < 0 || monthlyPayment > loanAmount);

    // Display Header
    std::cout << std::endl;
    std::cout << "Month     Balance     Payment     Interest        New Balance" << std::endl;
    std::cout << "_________________________________________________________________" << std::endl;

    // Set decimal places to 2
    double currentBalance = loanAmount;
    std::cout << std::fixed << std::setprecision(2);

    // 12 Month payment plan
    for (int month = 0; month < 12; month = month + 1)
    {
        // Determine per month payment
        if (monthlyPayment > currentBalance)
        {
            paymentThisMonth = currentBalance;
        } else
        {
            paymentThisMonth = monthlyPayment;
        }

        // Subtract completed payment from full balance
        currentBalance = currentBalance - paymentThisMonth;

        // Calculate interest 
        if (currentBalance > 0)
        {
            interest = currentBalance * interestRate;
        } else
        {
            interest = 0.0;
        }

        // New balance calculation
        newBalance = currentBalance + interest;

        // Display monthly information
        std::cout << (month + 1) << "       $" << currentBalance
            << "       $" << paymentThisMonth
            << "       $" << interest
            << "       $" << newBalance << std::endl;

  // Update totals
        totalPayments = totalPayments + paymentThisMonth;
        totalInterest = totalInterest + interest;

        // Updated current balance for next month
        if (newBalance > 0)
        {
            currentBalance = newBalance;
        } else
        {
            currentBalance = 0.0;
        }
    }

    // Display totals to user
    std::cout << "Total                  $" << totalPayments
        << "       $" << totalInterest << std::endl;

}