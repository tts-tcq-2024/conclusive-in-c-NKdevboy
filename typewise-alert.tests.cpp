#include <gtest/gtest.h>
#include "typewise-alert.h"
#include "TesterPrinters.h"

unsigned short header_Tester;
BreachType breachType_Tester;

char Srtrecepient_Tester[50] = {0};
char SrtbreachType_Tester[50]= {0};

extern PrinterForControllerPtr_t printerForControllerPtr;

void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

TEST(TypeWiseAlertTestSuite,InfersBreachAccordingToLimits) 
{
    printerForControllerPtr = PrinterForControllerMOCK;
    BatteryCharacter Test1 = {PASSIVE_COOLING,"BrandA"};
    checkAndAlert(TO_CONTROLLER,Test1,40);
    EXPECT_EQ(header_Tester,0xfeed);
    EXPECT_EQ(breachType_Tester,2);
}
