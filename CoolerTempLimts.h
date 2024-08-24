#define PASSIVE_COOLING_LIMTS {0,35}
#define HI_ACTIVE_COOLING_LIMTS {0,45}
#define MED_ACTIVE_COOLING_LIMTS {0,40}

#define ALLBATTERYPROPERTIES {  \
  PASSIVE_COOLING_LIMTS, \
  HI_ACTIVE_COOLING_LIMTS, \
  MED_ACTIVE_COOLING_LIMTS \
}

#define NUMOFCOOLINGTYPE 3
#define NUMOFLIMTS 2

#define TempLOW 0 
#define TempHIG 1

#define GET_PropertiesOfCoolingType(Typ,Limt) (PropertiesOfCoolingType[(Typ)][(Limt)])
#define GET_LOW_HIGH_TEMP(Typ) GET_PropertiesOfCoolingType((Typ),(TempLOW)) , GET_PropertiesOfCoolingType((Typ),(TempHIG))