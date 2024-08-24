#include "typewise-alert.h"
#include "CoolerTempLimts.h"
#include "alertTargetHandler.h"

//Internal Functions
static BreachType inferBreach(double value, double lowerLimit, double upperLimit);


// Temperatue Limts based on Cooler type
int PropertiesOfCoolingType[NUMOFCOOLINGTYPE][NUMOFLIMTS] = ALLBATTERYPROPERTIES;

// Function pointer array
const alertTargetPtr_t alertTargetPtr[NumOfalertTarget] = {sendToController , sendToEmail};

void checkAndAlert( AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) 
{
  BreachType breachType = inferBreach(temperatureInC, GET_LOW_HIGH_TEMP(batteryChar.coolingType));

  if(breachType)
  {
    alertTargetPtr[alertTarget](breachType);
  }
}

static BreachType inferBreach(double value, double lowerLimit, double upperLimit)
{
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}