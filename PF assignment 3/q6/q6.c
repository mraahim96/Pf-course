// M.Raahim 24k-0543 
// Assignment 3 q6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float temperature;
    float rainfall;
    float windSpeed;
} WeatherForecast;


typedef struct {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    WeatherForecast* weather; 
} Crop;


typedef struct {
    char equipmentType[50];
    int operationalStatus; 
    float fuelLevel;
    char activitySchedule[100];
} Equipment;


typedef struct {
    char sensorType[50];
    float value; 
} Sensor;


typedef struct {
    char gpsCoordinates[50];
    float soilHealth;   
    float moistureLevel;
    int numCrops;
    Crop* crops;        
    int numEquipment;
    Equipment* equipment;
    int numSensors;
    Sensor* sensors;    
} Field;

typedef struct {
    char regionName[50];
    int numFields;
    Field* fields;      
} RegionalHub;

Field initializeField(const char* gpsCoordinates, int numCrops, int numEquipment, int numSensors) {
    Field field;
    strcpy(field.gpsCoordinates, gpsCoordinates);
    field.soilHealth = 0.0;
    field.moistureLevel = 0.0;
    field.numCrops = numCrops;
    field.crops = (Crop*)malloc(numCrops * sizeof(Crop));
    field.numEquipment = numEquipment;
    field.equipment = (Equipment*)malloc(numEquipment * sizeof(Equipment));
    field.numSensors = numSensors;
    field.sensors = (Sensor*)malloc(numSensors * sizeof(Sensor));
    return field;
}

void addCropToField(Field* field, int cropIndex, const char* cropType, const char* growthStage, float expectedYield, WeatherForecast* weather) {
    if (cropIndex >= field->numCrops) {
        printf("Invalid crop index.\n");
        return;
    }
    strcpy(field->crops[cropIndex].cropType, cropType);
    strcpy(field->crops[cropIndex].growthStage, growthStage);
    field->crops[cropIndex].expectedYield = expectedYield;
    field->crops[cropIndex].weather = weather;
}

void addEquipmentToField(Field* field, int equipmentIndex, const char* equipmentType, int operationalStatus, float fuelLevel, const char* schedule) {
    if (equipmentIndex >= field->numEquipment) {
        printf("Invalid equipment index.\n");
        return;
    }
    strcpy(field->equipment[equipmentIndex].equipmentType, equipmentType);
    field->equipment[equipmentIndex].operationalStatus = operationalStatus;
    field->equipment[equipmentIndex].fuelLevel = fuelLevel;
    strcpy(field->equipment[equipmentIndex].activitySchedule, schedule);
}

void displayHub(RegionalHub* hub) {
    printf("Region: %s\n", hub->regionName);
    int i,j;
    for (i = 0; i < hub->numFields; i++) {
        Field* field = &hub->fields[i];
        printf("Field %d: GPS %s\n", i + 1, field->gpsCoordinates);
        printf("\nSoil Health: %.2f, \nMoisture Level: %.2f\n", field->soilHealth, field->moistureLevel);
        printf("\nCrops:\n");
        for ( j = 0; j < field->numCrops; j++) {
            printf("Crop %d: %s, Stage: %s, Yield: %.2f\n", j + 1, field->crops[j].cropType, field->crops[j].growthStage, field->crops[j].expectedYield);
        }
        printf("\nEquipment:\n");
        for (j = 0; j < field->numEquipment; j++) {
            printf("Equipment %d: %s, Status: %d, Fuel: %.2f\n", j + 1, field->equipment[j].equipmentType, field->equipment[j].operationalStatus, field->equipment[j].fuelLevel);
        }
    }
}

void freeField(Field* field) {
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}

void freeHub(RegionalHub* hub) {
	int i;
    for ( i = 0; i < hub->numFields; i++) {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
}

int main() {
    WeatherForecast weather = {23.5, 12.3, 5.0};

    Field field = initializeField("35.123N, 12.231E", 2, 1, 3);

    addCropToField(&field, 0, "Potato", "Vegetative", 1200.0, &weather);
    addCropToField(&field, 1, "Wheat", "Ripening", 800.0, &weather);

    addEquipmentToField(&field, 0, "Tractor", 1, 50.0, "Daily at 7AM");

    RegionalHub hub;
    strcpy(hub.regionName, "Northeast");
    hub.numFields = 1;
    hub.fields = (Field*)malloc(sizeof(Field));
    hub.fields[0] = field;

    displayHub(&hub);

    freeHub(&hub);

    return 0;
}
