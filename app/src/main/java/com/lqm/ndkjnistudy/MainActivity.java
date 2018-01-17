package com.lqm.ndkjnistudy;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("Hello");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

//        Hello.callStaticMethod(21);
        new  Hello().callInstanceMethod(2);

        TextView tv = (TextView) findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
        tv.setText(Hello.sayHello());


    }

    public native String stringFromJNI();
}
