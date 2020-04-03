/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "filter.h"


int16_t get_filtered_value(uint16_t raw, fir_filter_t *filter)
{
    int32_t result = 0;
    
    for(uint8_t i = filter->length - 1; i >= 1; --i)
    {
        filter->samples[i] = filter->samples[i - 1];
        result += filter->samples[i] * filter->taps[i];
    }
    
    filter->samples[0] = raw;
    result += filter->samples[0] * filter->taps[0];
    
    return (result / filter->gain);
}
/* [] END OF FILE */
