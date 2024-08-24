#include <gtest/gtest.h>
#include "typewise-alert.h"
#include "TesterPrinters.h"

unsigned short header_Tester = 0;
BreachType breachType_Tester = NORMAL;

char Srtrecepient_Tester[50] = {0};
char SrtbreachType_Tester[50]= {0};

extern PrinterForControllerPtr_t printerForControllerPtr;

void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

TEST(TypeWiseAlertTestSuite,PassiveCoolingForController) 
{
    printerForControllerPtr = PrinterForControllerMOCK;
    BatteryCharacter Test1 = {PASSIVE_COOLING,"BrandA"};
    checkAndAlert(TO_CONTROLLER,Test1,40);
    EXPECT_EQ(header_Tester,0xfeed);
    EXPECT_EQ(breachType_Tester,2);
}

TEST(TypeWiseAlertTestSuite,HiActiveCoolingForController) 
{
    printerForControllerPtr = PrinterForControllerMOCK;
    BatteryCharacter Test1 = {HI_ACTIVE_COOLING,"BrandA"};
    checkAndAlert(TO_CONTROLLER,Test1,-1);
    EXPECT_EQ(header_Tester,0xfeed);
    EXPECT_EQ(breachType_Tester,1);
}

TEST(TypeWiseAlertTestSuite,MedActiveCoolingForController) 
{
    printerForControllerPtr = PrinterForControllerMOCK;
    BatteryCharacter Test1 = {MED_ACTIVE_COOLING,"BrandA"};
    checkAndAlert(TO_CONTROLLER,Test1,1);
    EXPECT_EQ(header_Tester,0);
    EXPECT_EQ(breachType_Tester,0);
}
