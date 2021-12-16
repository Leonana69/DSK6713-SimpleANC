#include <stdio.h>
#include "dsk6713.h"
#include "dsk6713_led.h"
#include "dsk6713_aic23.h"
#include "dsk6713_dip.h"
#include <math.h>

typedef union {
    Uint32 val;
    short channel[2];
} AIC_data;

void writeOutput(DSK6713_AIC23_CodecHandle hCodec, AIC_data val) {
    // left channel
    while (!DSK6713_AIC23_write(hCodec, val.channel[0]));
    // right channel
    while (!DSK6713_AIC23_write(hCodec, val.channel[1]));
}

void readInput(DSK6713_AIC23_CodecHandle hCodec, AIC_data *val) {
    Uint32 dataIn;
    // left channel
    while(!DSK6713_AIC23_read(hCodec, &dataIn));
    val->channel[0] = dataIn;
    // right channel
    while(!DSK6713_AIC23_read(hCodec, &dataIn));
    val->channel[1] = dataIn;
}

/**
 * main.c
 */

#define f_len 24
#define f_mu 0.01

int main(void) {
    DSK6713_init();
    DSK6713_LED_init();
    DSK6713_DIP_init();
    DSK6713_AIC23_Config config = DSK6713_AIC23_DEFAULTCONFIG;
    DSK6713_AIC23_CodecHandle hCodec = DSK6713_AIC23_openCodec(0, &config);
    DSK6713_AIC23_setFreq(hCodec, DSK6713_AIC23_FREQ_8KHZ);
    AIC_data input, output;
    int i = 0;
    float samples[f_len] = { 0 };
    float filter[f_len] = { 0 };
    float result;
    float sum;

    while (1) {
        if (DSK6713_DIP_get(0) == 0) {
            DSK6713_LED_on(0);
            // read input
            readInput(hCodec, &input);

            // update input
            for (i = f_len - 1; i > 0; i--)
                samples[i] = samples[i - 1];
            samples[0] = input.channel[1];

            // normalization
            sum = 0.0;
            for (i = 0; i < f_len; i++)
                sum += samples[i] * samples[i];
            if (sum == 0) sum = 1;

            // lms update
            for (i = 0; i < f_len; i++)
                filter[i] = filter[i] + f_mu * samples[i] * input.channel[0] / sum;

            // output update
            result = 0.0;
            for (i = 0; i < f_len; i++)
                result += samples[i] * filter[i];

            // write output
            output.channel[0] = -result; // anti noise
            output.channel[1] = samples[0]; // for debug
            writeOutput(hCodec, output);
        } else {
            DSK6713_LED_off(0);
        }
    }
}
