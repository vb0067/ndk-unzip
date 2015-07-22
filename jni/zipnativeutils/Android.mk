LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

#LOCAL_C_INCLUDES := $(LOCAL_PATH)/../miniunz

#LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

LOCAL_SRC_FILES:= com_yyx_me_unzip_ZipNativeUtils.cpp

LOCAL_MODULE:= zipnativeutils
LOCAL_MODULE_FILENAME:= libzipnativeutils


LOCAL_STATIC_LIBRARIES := miniunz

LOCAL_LDLIBS := -lz -llog
include $(BUILD_SHARED_LIBRARY)







#LOCAL_PATH := $(call my-dir)
##获取当前目录
#include $(CLEAR_VARS)
##清除一些变量

#LOCAL_MODULE    := tutorial
##要生成的库名

#LOCAL_SRC_FILES := tutorial01.c tutorial02.c
##库对应的源文件

#include $(BUILD_SHARED_LIBRARY)
##生成动态库libtutorial.so

#include $(CLEAR_VARS)
##清除一些变量

#LOCAL_MODULE    := test
##定义另外一个库的名

#LOCAL_SRC_FILES := test01.c
##定义库对应的源文件

#LOCAL_LDLIBS := -ldl -llog
##libtest.so需要引用的库libdl.so:加载动态函数需要，liblog.so 日志打印需要，默认是system/lib目录下

#LOCAL_STATIC_LIBRARIES := libivp20

#include $(BUILD_SHARED_LIBRARY)
##生成共享库
