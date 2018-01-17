#include <jni.h>
#include <string>

#include <android/log.h>
#define TAG    "nate"
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_lqm_ndkjnistudy_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    LOGD("from native-lib log");

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
