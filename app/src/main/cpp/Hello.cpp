//
// Created by Administrator on 2018/1/16.
//C++ 具体实现类

#include "com_lqm_ndkjnistudy_Hello.h"

#include <android/log.h>
#define TAG    "nate"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_lqm_ndkjnistudy_Hello_sayHello
        (JNIEnv * env, jclass jclass1){

    LOGD("from c log");

    return env ->NewStringUTF("from c");
}
