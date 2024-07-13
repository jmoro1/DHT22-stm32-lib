#ifndef DHT22_H
#define DHT22_H

#include "stm32f1xx_hal.h"


typedef struct {
    uint8_t data[5];
    uint8_t pin;
    uint8_t count;
    uint32_t lastReadTime;
    uint32_t maxCycles;
    bool lastResult;
    uint8_t pullTime; // Tiempo (en usec) para tirar de la línea de datos antes de leer
} DHT;

/*
HAL_StatusTypeDef DHT22_Init(void);
HAL_StatusTypeDef DHT22_ReadData();
*/

void DHT_Init(DHT *dht, uint8_t pin,uint8_t count);
void DHT_Begin(DHT *dht, uint8_t usec);
float DHT_ReadTemperature(DHT *dht, bool S, bool force);
float DHT_ReadHumidity(DHT *dht, bool force);
bool DHT_Read(DHT *dht, bool force);
uint32_t expectPulse(bool level);


#ifndef microsecondsToClockCycles
#define microsecondsToClockCycles(a) ((a) * (SystemCoreClock / 1000000L))
#endif


#endif /* DHT22_H */

