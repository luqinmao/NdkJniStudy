//
// Created by Administrator on 2018/1/16.
//C++ 具体实现类

#include "com_lqm_ndkjnistudy_Hello.h"
JNIEXPORT jstring JNICALL Java_com_lqm_ndkjnistudy_Hello_sayHello
        (JNIEnv * env, jclass jclass1){
    return env ->NewStringUTF("from c");
}
