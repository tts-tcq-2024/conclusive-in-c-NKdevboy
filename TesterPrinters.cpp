
#include <string.h>
#include "typewise-alert.h"
extern short header_Tester;
extern BreachType breachType_Tester;

extern char Srtrecepient_Tester[50];
extern char SrtbreachType_Tester[50];

void PrinterForControllerMOCK(const unsigned short header,BreachType breachType)
{
  header_Tester = header;
  breachType_Tester = breachType;
}

void PrinterForEmailMOCK(const char * recepient,const char *breachType)
{
  strcpy(Srtrecepient_Tester, recepient);
  strcpy(SrtbreachType_Tester, breachType);
}