import machine, neopixel
# GPIO 38, 1 світлодіод
led = neopixel.NeoPixel(machine.Pin(38), 1)
led[0] = (1, 1, 1)
led.write()