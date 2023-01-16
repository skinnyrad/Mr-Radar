# Mr Radar
Mr. Radar is a port security evading, discovery device used to detect network switches connected to lone network ports. In addition, it has the ability to detect if Power over Ethernet (PoE) is present and whether the PoE being provide is Mode A or Mode B in nature. An understanding of the functionality of Mr. Radar can be found here: https://skinnyrd.com/mr-radar-layer-1-recon/
![Mr Radar Photo](https://user-images.githubusercontent.com/20311289/212752046-b7969797-d6ee-4c6b-bb99-d615fbe3a9d1.png)

## Mr. Radar Github File Structure
The hardware folder contains the KiCad project files for Mr. Radar. The MrRadar_firmware folder contains the .ino file for the Arduino IDE. These files will be used to program the Trinket M0 which controls Mr. Radar.

## Mr. Radar Bill of Materials
- J1: RJ-45 Connector (https://www.digikey.com/short/mw80n14h)
- R1: 100kΩ 1/4W
- R2: 100kΩ 1/4W
- R3: 10kΩ 1/4W
- R4: 10kΩ 1/4W
- R5: 10kΩ 1/4W
- R6: 3.3kΩ 1/4W
- R7: 10kΩ 1/4W
- R8: 100kΩ 1/4W
- R9: 100kΩ 1/4W
- U1: Trinket M0 (https://www.adafruit.com/product/3500)
- SW1: SPST Switch (https://www.digikey.com/short/q5dbrt7p)
- BT1: Battery Pack (https://www.digikey.com/short/m8dprrz4)
- Machine Screw: #2-56 Thread Size, 1/4 in Lg, 18-8 (https://www.grainger.com/product/GRAINGER-APPROVED-Machine-Screw-2-56-Thread-1ZB23?searchQuery=1ZB23&searchBar=true&tier=Not+Applicable)
- Hex Nut: Plain, 18-8, Stainless Steel, #2-56 Thread (https://www.grainger.com/product/GRAINGER-APPROVED-Hex-Nut-Plain-1WA81?searchQuery=1WA81&searchBar=true&tier=Not+Applicable)

## Tips for construction
- When loading the code for the Trinket M0, ensure you have setup the Trinket according to the Adafruit tutorial (https://learn.adafruit.com/adafruit-trinket-m0-circuitpython-arduino). Use the Arduino IDE setup procedures.
- The battery pack goes on the bottom of the board. You'll need to solder everything on top first and then clip all the excess wire pieces before affixing the battery pack.
