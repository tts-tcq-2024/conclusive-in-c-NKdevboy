#include <stdio.h>
#include "typewise-alert.h"


void PrinterForController(const unsigned short header,BreachType breachType)
{
  printf("%x : %x\n", header, breachType);
}

void PrinterForEmail(const char * recepient,const char *breachType)
{
    printf("To: %s\n%s",recepient,breachType);
}