package com.rwanda.hellojni;

import com.apress.swig.UnixJNI;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class HelloJni extends Activity {
	private String instanceField = "Instance Field";
	private UnixJNI jni;
	private static String staticField = "static Field";
    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.main);
        Log.i("rwanda","on Create");
        TextView $str = new TextView(this);
        $str.setText( stringFromJNI());
        setContentView($str);
        jni = new UnixJNI();
        int g = jni.gcd(42, 105);
        Log.i("rwanda", "42, 105 gcd is: " + g );
    }

    public native String  stringFromJNI();

    // using static, hello-jni will be loaded after class is loaded and initialized for the first time
    static {
        System.loadLibrary("hello-jni");
    }
}
