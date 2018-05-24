LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
#opencv
OPENCVROOT:= C:\opencv-2.4.13.6-android-sdk\OpenCV-android-sdk
OPENCV_CAMERA_MODULES:=on
OPENCV_INSTALL_MODULES:=on
OPENCV_LIB_TYPE:=SHARED
include ${OPENCVROOT}/sdk/native/jni/OpenCV.mk
LOCAL_SRC_FILES := vn_edu_hust_student_linhdt_project_OpencvClass.cpp
LOCAL_LDLIBS += -llog
LOCAL_MODULE := MyLibs
include $(BUILD_SHARED_LIBRARY)