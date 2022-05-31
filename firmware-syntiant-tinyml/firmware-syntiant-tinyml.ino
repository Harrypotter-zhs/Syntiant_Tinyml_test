


/* Edge Impulse ingestion SDK
 * Copyright (c) 2021 EdgeImpulse Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "src/syntiant.h"
#include <NDP.h>
#include <NDP_utils.h>
#include <Arduino.h>

/**
 * @brief      Called when a inference matches 1 of the features
 *
 * @param[in]  event          The event
 * @param[in]  confidence     The confidence
 * @param[in]  anomaly_score  The anomaly score
 */

void on_classification_changed(const char *event, float confidence, float anomaly_score) 
{
    static int8_t count = 0;
    // here you can write application code, e.g. to toggle LEDs based on keywords
    //您可以在此处编写应用程序代码，例如根据关键字切换LED
    if (strcmp(event, "open_blue") == 0) 
    { 
        if (count != 1)
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_BLUE, HIGH);
        count = 1;
        Serial.println("open_green:open blue led");
    }
    else if (strcmp(event, "open_green") == 0) 
    {
        if (count != 2)
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_GREEN, HIGH);
        count = 2;
        Serial.println("led status:open green led");
    }
    else if (strcmp(event, "open_red") == 0)
    {
        if (count != 3)
        {
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, LOW);
        }
        digitalWrite(LED_RED, HIGH);
        count = 3;
        Serial.println("led status:open red led");
    }
    else if (strcmp(event, "close_led") == 0)
    {
        
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_BLUE, LOW);
      count = 4;
      Serial.println("led status:close all led!");
    }
    
    
    


}

void setup(void)
{
    syntiant_setup();
}

void loop(void)
{
    syntiant_loop();
}
