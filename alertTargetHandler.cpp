
#include "typewise-alert.h"
#include "alertTargetHandler.h"
#include "ProdunctionPrinters.h"
#include "TesterPrinters.h"


PrinterForControllerPtr_t printerForControllerPtr = PrinterForController;
PrinterForEmailPtr_t printerForEmailPtr = PrinterForEmail;

const char * EmailContent[] = {"Hi, the temperature is too low\n","Hi, the temperature is too high\n"};

void sendToController(BreachType breachType)
{
  const unsigned short header = 0xfeed;
  printerForControllerPtr(header,breachType);
}

void sendToEmail(BreachType breachType)
{
  const char* recepient = "a.b@c.com";
  printerForEmailPtr(recepient,EmailContent[breachType-1]);
}