/*
 * Developer: Reginald Kargbo
 * Date: 04/01/2026
 * Course: CS-210 Programming Languages
 * Project: Airgead Banking Investment Application
 */

#include "AirgeadBanking.h"

#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

AirgeadBanking::AirgeadBanking() {
    m_initialInvestmentAmount = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterestRate = 0.0;
    m_numberOfYears = 0;
}

double AirgeadBanking::calculateMonthlyInterest(double t_openingAmount, double t_depositedAmount) const {
    return (t_openingAmount + t_depositedAmount) * ((m_annualInterestRate / 100.0) / 12.0);
}

void AirgeadBanking::getUserInput() {
    cout << "**********************************" << endl;
    cout << "************ Data Input **********" << endl;

    while (true) {
        cout << "Initial Investment Amount: ";
        cin >> m_initialInvestmentAmount;

        if (cin.fail() || m_initialInvestmentAmount < 0) {
            cout << "Please enter a valid non-negative amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Monthly Deposit: ";
        cin >> m_monthlyDeposit;

        if (cin.fail() || m_monthlyDeposit < 0) {
            cout << "Please enter a valid non-negative amount." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Annual Interest: ";
        cin >> m_annualInterestRate;

        if (cin.fail() || m_annualInterestRate < 0) {
            cout << "Please enter a valid non-negative rate." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Number of Years: ";
        cin >> m_numberOfYears;

        if (cin.fail() || m_numberOfYears <= 0) {
            cout << "Please enter a valid positive whole number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void AirgeadBanking::displayInput() const {
    cout << endl;
    cout << "**********************************" << endl;
    cout << "************ Data Input **********" << endl;
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << m_initialInvestmentAmount << endl;
    cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
    cout << "Annual Interest: " << m_annualInterestRate << "%" << endl;
    cout << "Number of Years: " << m_numberOfYears << endl;
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

void AirgeadBanking::displayReportWithoutMonthlyDeposits() const {
    double currentBalance = m_initialInvestmentAmount;

    cout << endl;
    cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << left << setw(8) << "Year"
        << setw(22) << "Year End Balance"
        << setw(26) << "Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyEarnedInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double openingAmount = currentBalance;
            double depositedAmount = 0.0;
            double monthlyInterest = calculateMonthlyInterest(openingAmount, depositedAmount);

            yearlyEarnedInterest += monthlyInterest;
            currentBalance = openingAmount + depositedAmount + monthlyInterest;
        }

        cout << left << setw(8) << year
            << "$" << setw(21) << fixed << setprecision(2) << currentBalance
            << "$" << fixed << setprecision(2) << yearlyEarnedInterest << endl;
    }
}

void AirgeadBanking::displayReportWithMonthlyDeposits() const {
    double currentBalance = m_initialInvestmentAmount;

    cout << endl;
    cout << "      Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << left << setw(8) << "Year"
        << setw(22) << "Year End Balance"
        << setw(26) << "Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (int year = 1; year <= m_numberOfYears; ++year) {
        double yearlyEarnedInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double openingAmount = currentBalance;
            double depositedAmount = m_monthlyDeposit;
            double monthlyInterest = calculateMonthlyInterest(openingAmount, depositedAmount);

            yearlyEarnedInterest += monthlyInterest;
            currentBalance = openingAmount + depositedAmount + monthlyInterest;
        }

        cout << left << setw(8) << year
            << "$" << setw(21) << fixed << setprecision(2) << currentBalance
            << "$" << fixed << setprecision(2) << yearlyEarnedInterest << endl;
    }
}

