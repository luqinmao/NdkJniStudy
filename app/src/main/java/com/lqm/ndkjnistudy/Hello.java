package com.lqm.ndkjnistudy;

import android.util.Log;

/**
 * user：lqm
 * desc：jni文件
 */

public class Hello {

    private static String name = "nate";  //将在C代码中修改参数值

    public static native String sayHello();

    //


    public static void staticMethod(String data){
        logMessage(data);
        logMessage(name);
    }

    public static void logMessage(String data){
        Log.d("nate",data);
    }

    public static native void callStaticMethod(int i);

    public static native void callStaticMethod(long i,String str);

    public native void callInstanceMethod(int i);

    public native void callInstanceMethod(String str, long i);

    //实例方法

    private String address = "beijing";

    public void method(String data){
        logMessage(data);
        logMessage(address);
    }

}
