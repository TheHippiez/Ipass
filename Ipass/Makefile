#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := sonarSensor.cpp guardObject.cpp lcdScreen.cpp distanceMeter.cpp distanceSensors.cpp Radar.cpp

# header files in this project
HEADERS := sonarSensor.hpp guardObject.hpp lcdScreen.hpp distanceMeter.hpp distanceSensors.hpp Radar.hpp

# other places to look for files for this project
SEARCH  := C:\TCTI-V1OOPC-15-BASE-master\HCSR04 C:\TCTI-V1OOPC-15-BASE-master\NOKIA5510

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
