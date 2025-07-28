#include <assert.h>
#include <stdio.h>
#include <string.h>

struct SensorReadings {
    int temperatureInC;
    int precipitation;
    int humidity;
    int windSpeedKMPH;
};

// This is a stub for a weather sensor. For the sake of testing 
// we create a stub that generates weather data and allows us to
// test the other parts of this application in isolation
// without needing the actual Sensor during development

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
    // precipitation < 20 is a sunny day
    snprintf(weather, sizeof(weather), "%s", "Sunny Day");
    if (readings.temperatureInC > 25) {
        if (readings.precipitation >= 20 && readings.precipitation < 60) {
            snprintf(weather, sizeof(weather), "%s", "Partly Cloudy");
        } else if (readings.windSpeedKMPH > 50) {
            snprintf(weather, sizeof(weather), "%s", "Alert, Stormy with heavy rain");
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
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    const char* weather = report(sensorStub);
    
    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    assert(strlen(weather) > 0);
}

int testWeatherReport() {
    printf("\nWeather report test\n");
    testRainy();
    testHighPrecipitation();
    printf("All is well (maybe!)\n");
    return 0;
}
