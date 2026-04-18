/*
 * Developer: Reginald Kargbo
 * Date: 04/01/2026
 * Course: CS-210 Programming Languages
 * Project: Airgead Banking Investment Application
 */

#ifndef AIRGEADBANKING_H_
#define AIRGEADBANKING_H_

class AirgeadBanking {
public:
    AirgeadBanking();

    void getUserInput();
    void displayInput() const;
    void displayReportWithoutMonthlyDeposits() const;
    void displayReportWithMonthlyDeposits() const;

private:
    double m_initialInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;

    double calculateMonthlyInterest(double t_openingAmount, double t_depositedAmount) const;
};

#endif  // AIRGEADBANKING_H_
