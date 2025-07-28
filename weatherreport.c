#include <assert.h>
#include <stdio.h>
#include <string.h>

struct SensorReadings {
    int temperatureInC;
    int precipitation;
    int humidity;
    int windSpeedKMPH;
};

struct SensorReadings sensorStub() {
    struct SensorReadings readings;
    readings.temperatureInC = 50;
    readings.precipitation = 70;
    readings.humidity = 26;
    readings.windSpeedKMPH = 52;
    return readings;
}

const char* report(struct SensorReadings (*sensorReader)()) {
    static char weather[50] = "Sunny Day";
    struct SensorReadings readings = sensorReader();
    strcpy(weather, "Sunny Day");
    if (readings.temperatureInC > 25) {
        if (readings.precipitation >= 20 && readings.precipitation < 60) {
            strcpy(weather, "Partly Cloudy");
        } else if (readings.windSpeedKMPH > 50) {
            strcpy(weather, "Alert, Stormy with heavy rain");
        }
    }
    return weather;
}

void testRainy() {
    const char* weather = report(sensorStub);
    printf("%s\n", weather);
    assert(strstr(weather, "rain") != NULL);
}

void testHighPrecipitation() {
    const char* weather = report(sensorStub);
    assert(strlen(weather) > 0);
}

int testWeatherReport() {
    printf("\nWeather report test\n");
    testRainy();
    testHighPrecipitation();
    printf("All is well (maybe!)\n");
    return 0;
}