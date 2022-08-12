# Arduino_Multiplexed-Displays
A Arduino library which provides an api for generic multiplexed display modules. Useful for driving salvaged dvd/vcr/vcd display modules. Currently supports only 7 segment digits and does not include buttons functionality.
This library is particularly useful for display modules salvaged from old electronics. As configuration between Display driver IC and Display totally depends on manufacturer you will need different library for different
display modules. This library is made to solve that problem. You need to provide a config file for your display module and this library will use that configuration to drive your display module.

# Installation
Just put the files on a M_Displays directory under "arduino/libraries" on your arduino IDE instalation.

# Usage 
Create config file for your display module in src/display_configs directory. Examples of config files are provided along with templates for VM and HM display modules. Edit the config file for your display module accordingly.
Now Include HM_Display.h if you have display which is multiplexed horizontally or include VM_Display.h if it is multiplexed vertically.
Currently this project does not have documentation so refer source code for usage. 
For more information contact me:- 
siddheshdharme18@gmail.com
