# Arduino_Multiplexed-Displays
An Arduino library which provides an API for generic multiplexed display modules. Useful for driving salvaged dvd/vcr/vcd display modules. Currently supports only 7 segment digits and does not include functionality for buttons.
This library is particularly useful for display modules salvaged from old electronics. As configuration between Display driver IC and Display totally depends on manufacturer you need different library for different configuration of
display modules even if same display driver IC is used. This library is made to solve that problem. You need to provide a config file for your display module and this library will use that configuration to drive your display module.

# Installation
Just put the files on a M_Displays directory under "arduino/libraries" on your arduino IDE instalation.

# Usage 
Copy config template from src/display_configs in your sketch directory and edit it as per your display module. Examples of VM/HM display configs are also provided in src/display_configs.
Now Include HM_Display.h in your sketch if you have display which is multiplexed horizontally or include VM_Display.h if it is multiplexed vertically. Also include your config file (eg. VM_TM1628_config.h).
Currently this project does not have documentation so refer source code for usage. 
For more information contact me:- 
siddheshdharme18@gmail.com
