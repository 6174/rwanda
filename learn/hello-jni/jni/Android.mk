# android.mk is a fragment of makefile , and it's syntax is the same as makefile 

# my-dir is a macro function
LOCAL_PATH := $(call my-dir)

# include clear-vars.mk
# in order to reset variables such as LOCAL_SRC_FILES
include $(CLEAR_VARS)

# set the name of this module to hello-jni
LOCAL_MODULE    := hello-jni

# list of source files that will be built and assembled 
LOCAL_SRC_FILES := hello-jni.c

# contains the necessary build procedure to build and assemble source files as a shared library
include $(BUILD_SHARED_LIBRARY)
