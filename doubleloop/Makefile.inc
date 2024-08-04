mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
util.o \
MotorControl.o \
ColorSensorControl.o \
Motion.o \
MotionSpin.o \
MotionLineTrace.o \
Detection.o \
Color.o \
Angle.o \
Area.o \
AreaControl.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += \
	$(mkfile_path)device \
	$(mkfile_path)motion \
	$(mkfile_path)detection \
	$(mkfile_path)aggregate \
	$(mkfile_path)areaManager \
	$(mkfile_path)unit

INCLUDES += \
	-I$(mkfile_path)device \
	-I$(mkfile_path)motion \
	-I$(mkfile_path)detection \
	-I$(mkfile_path)aggregate \
	-I$(mkfile_path)areaManager \
	-I$(mkfile_path)unit

# COPTS += -fno-use-cxa-atexit
