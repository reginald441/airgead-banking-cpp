/*
 * Developer: Reginald Kargbo
 * Date: 04/01/2026
 * Course: CS-210 Programming Languages
 * Project: Airgead Banking Investment Application
 */

#include "AirgeadBanking.h"

#include <iostream>
#include <exception>

using namespace std;

int main() {
    try {
        AirgeadBanking app;

        app.getUserInput();
        app.displayInput();
        app.displayReportWithoutMonthlyDeposits();
        app.displayReportWithMonthlyDeposits();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cout << "Unknown error occurred." << endl;
        return 1;
    }

    return 0;
}
