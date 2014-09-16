package com.rwanda.hellojni;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class HelloJni extends Activity {
    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.main);
        Log.i("helloJni","on Create");
        TextView $str = new TextView(this);
        $str.setText( stringFromJNI());
        setContentView($str);
    }
//
//    public String stringFromJNI() {
//        return "Hello from javaadf";
//    }

    public native String  stringFromJNI();

    // using static, hello-jni will be loaded after class is loaded and initialized for the first time
    static {
        System.loadLibrary("hello-jni");
    }
}
