//
// Created by Administrator on 2018/1/16.
//C++ 具体实现类

#include "com_lqm_ndkjnistudy_Hello.h"
#include <stdlib.h>
#include <stdio.h>

#include <android/log.h>
#define TAG    "nate"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

JNIEXPORT jstring JNICALL Java_com_lqm_ndkjnistudy_Hello_sayHello
        (JNIEnv * env, jclass jclass1){

    LOGD("from c log");

    return env ->NewStringUTF("from c");
}

/*
 * Class:     com_lqm_ndkjnistudy_Hello
 * Method:    callStaticMethod
 * Signature: (I)V
 *  调用java类的static静态方法
 */
JNIEXPORT void JNICALL Java_com_lqm_ndkjnistudy_Hello_callStaticMethod__I
        (JNIEnv * env, jclass jclass1, jint i){
    //找到对应的类
    jclass cls_hello = env ->FindClass("com/lqm/ndkjnistudy/Hello");
    if(cls_hello == NULL){
        return;
    }
    //找到对应的方法
    jmethodID mtd_static_method = env->GetStaticMethodID(cls_hello,"staticMethod","(Ljava/lang/String;)V");
    if( mtd_static_method == NULL){
        return;
    }
    //创建字符串
    jstring data = env->NewStringUTF("call static method");
    if(data == NULL){
        return;
    }

    //修改Java中的static参数值
    jfieldID fld_name= env ->GetStaticFieldID(cls_hello,"name","Ljava/lang/String;");
    if (fld_name == NULL){
        return;
    }
    jstring name  = env ->NewStringUTF("tom");
    env -> SetStaticObjectField(cls_hello,fld_name,name);


    //调用java层的代码
    env ->CallStaticVoidMethod(cls_hello,mtd_static_method,data);
    //删除引用
    env ->DeleteLocalRef(cls_hello); //DeleteLocalRef
    env->DeleteLocalRef(data);
    env ->DeleteLocalRef(name);

}

/*
 * Class:     com_lqm_ndkjnistudy_Hello
 * Method:    callInstanceMethod
 * Signature: (I)V
*              实例方法
 */
JNIEXPORT void JNICALL Java_com_lqm_ndkjnistudy_Hello_callInstanceMethod__I
        (JNIEnv * env, jobject jobject1, jint i){
    jclass cls_hello = env ->FindClass("com/lqm/ndkjnistudy/Hello");
    if(cls_hello == NULL){
        return;
    }
    jmethodID mtd_method = env->GetMethodID(cls_hello,"method","(Ljava/lang/String;)V");
    if( mtd_method == NULL){
        return;
    }
    //找到对应的构造方法
    jmethodID mtd_construct = env ->GetMethodID(cls_hello,"<init>","()V");
    if (mtd_construct == NULL){
        return;
    }

    //修改成员变量
    jfieldID fld_address = env ->GetFieldID(cls_hello,"address","Ljava/lang/String;");
    if (fld_address == NULL){
        return;
    }
    jstring address = env ->NewStringUTF("shanghai");
    if (address ==NULL){
        return;
    }

    //创建相应的对象
    jobject hello = env ->NewObject(cls_hello,mtd_construct,NULL);
    if (hello == NULL){
        return;
    }

    //修改成员变量,hello:要对对象进行操作，而不是class
    env ->SetObjectField(hello,fld_address,address);

    jstring message = env ->NewStringUTF("call instance method");
    env ->CallVoidMethod(hello,mtd_method,message);
    env ->DeleteLocalRef(message);
    env ->DeleteLocalRef(cls_hello);
    env ->DeleteLocalRef(hello);

    env ->DeleteLocalRef(address);


}
