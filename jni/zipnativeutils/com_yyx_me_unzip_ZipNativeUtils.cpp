#ifndef  _COM_YYX_ME_UNZIP_ZIPNATIVEUTILS_H
#include "com_yyx_me_unzip_ZipNativeUtils.h"
#endif




char* jstringTostring(JNIEnv* env,jstring jstr)
{
    char* rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr= (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0)
    {
        rtn = (char*)malloc(alen + 1);

        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}


/*
 * Class:     com_yyx_me_unzip_ZipNativeUtils
 * Method:    unzip
 * Signature: (Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_yyx_1me_unzip_ZipNativeUtils_unzip(JNIEnv *env,
jobject obj,
jstring zipStr,
jstring dest,
jstring passwd)

{

char *zip_char = jstringTostring(env,zipStr);
char *dest_char = jstringTostring(env,dest);
char *passwd_char = jstringTostring(env,passwd);

   return unzip(zip_char,dest_char,passwd_char);
}

/*
 * Class:     com_yyx_me_unzip_ZipNativeUtils
 * Method:    unzip1
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_com_yyx_1me_unzip_ZipNativeUtils_unzip1(JNIEnv *env, jobject obj, jstring zipStr, jstring dest){
char* zip_char = jstringTostring(env,zipStr);
char* dest_char = jstringTostring(env,dest);
return unzip1(zip_char,dest_char);
}




