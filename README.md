# Cyberblaster
Because light isn't just light

# Materialien
- 4mm Sperrholz für die Spanten
- 6mm Sperrholz für die beiden Ringe
- CPU Kühler (> 100 Watt TDP, ansonsten muss der Lüfter ständig wühlen)
- LED Treiber, z.B. http://de.aliexpress.com/item/Brand-new-100W-LED-Power-Supply-Driver-For-100-Watt-High-Power-LED-Light-Lamp-Bulb/32412210627.html
- 100 Watt LED, die gibt es auch in warmweiß
- MOSFET, IRF7413 funktioniert gut
- WeMos, siehe wemos.cc (Zur Not habe ich auch welche vorrätig)
- Hühnerfutter zum MOSFET treiben

# Anleitung
- Bauteile lasercutten und zusammenkleben
- LED mit Wärmeleitpaste auf dem Kühler anbringen und den Kühler am Lampenschirm anbringen
- MOSFET zwischen Treiber(-) und LED(-) hängen. WeMos über Transistoren mit dem MOSFET verdrahten (D0). Schaltplan folgt.
