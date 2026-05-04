import machine, neopixel
# GPIO 38, 1 світлодіод
led = neopixel.NeoPixel(machine.Pin(38), 1)
led[0] = (1, 1, 1)
led.write()

import time
while True:
    led[0] = (255, 255, 0) 
    led.write()
    time.sleep(1)
    led[0] = (0, 255, 255) 
    led.write()
    time.sleep(1)
    led[0] = (255, 0, 255) 
    led.write()
    time.sleep(1)