/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.2
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.apress.swig;

public class Unix {
  public static int gcd(int x, int y) {
    return UnixJNI.gcd(x, y);
  }

  public static void setFoo(double value) {
    UnixJNI.Foo_set(value);
  }

  public static double getFoo() {
    return UnixJNI.Foo_get();
  }

}
