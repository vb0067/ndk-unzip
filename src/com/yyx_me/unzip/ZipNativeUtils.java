package com.yyx_me.unzip;

/**
 * Created by yu@yyx-me.com on 7/21/15.
 */
public class ZipNativeUtils {
    static {
        System.loadLibrary("libzipnativeutils");
    }
    public native int unzip(String zip, String dest, String passwd);

    public native int unzip1(String zip, String dest);
}
