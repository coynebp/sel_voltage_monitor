/* ========================================
 *
 * SEL VOLTAGE MONITOR
 * TEAM REMBRANDT
 * 
 * filter.c
 *
 * Generalized FIR filter
 * 
 * ========================================
*/
#include "filter.h"

void initialize_filter(uint8_t length, int16_t * taps, int16_t gain, int32_t * samples, fir_filter_t * filter)
{
    filter->length = length;
    filter->taps = taps;
    filter->gain = gain;
    filter->samples = samples;
    filter->is_charged = false;
    filter->num_samples = 0;
}

void insert_filter_value(fir_filter_t *filter, int32_t value)
{
    // Move all samples along the array.
    for(uint8_t i = filter->length - 1; i >= 1; --i)
    {
        filter->samples[i] = filter->samples[i - 1];
    }
    // Add newest sample to the filter.
    filter->samples[0] = value;
    // If filter is not yet charged, count the sample.
    if (!filter->is_charged)
    {
        ++filter->num_samples;
        if (filter->num_samples == filter->length)
        {
            filter->is_charged = true;
        }
    }
}

int32_t get_filtered_value(fir_filter_t *filter)
{
    int32_t result = 0;
    for(uint8_t i = 0; i < filter->length; ++i)
    {
        result += (filter->samples[i] * filter->taps[i]);
    }
    return result / filter->gain;
}
/* [] END OF FILE */
