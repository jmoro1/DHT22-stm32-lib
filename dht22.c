#include "dht22.h"

// htim typedef tbd

void DHT_Delay_us(uint32_t us){

    __HAL_TIM_SET_COUNTER(&htim1,0); //htim pointer tbd
    while(__HAL_TIM_GET_COUNTER(&htim1) < us){};

}

void DHT_Init(DHT *dht, uint8_t pin, uint8_t count){

    dht->pin = pin;
    dht->count = count;
    dht->lastReadTime = 0;
    dht->maxCycles = microsecondsToClockCycles(1000); //1ms timeout for reading pulses from the sensor
    dht->lastResult = false;
    dht->pullTime = 55; //us (microseconds) before the sensor reading starts
}

void DHT_Begin(DHT *dht, uint8_t usec){

    
}

