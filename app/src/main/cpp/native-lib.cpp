#include <jni.h>
#include <string>

#define IMG_WIDTH 512
#define IMG_HEIGHT 512
#define RGBA8(r, g, b, a) ((a << 24) | (r << 16) | (g << 8) | b)

extern "C" JNIEXPORT jintArray JNICALL Java_com_example_myapplication_MainActivity_buildImageUsingCPP(JNIEnv* env, jobject /* this */){
    jintArray imageArr;
    imageArr = env->NewIntArray(IMG_WIDTH * IMG_HEIGHT);
    jint imageDat[IMG_WIDTH * IMG_HEIGHT];

    for(int x = 0; x < IMG_WIDTH; x++){
        for(int y = 0; y < IMG_HEIGHT; y++){
            char r = (127 + (127 * sin(x * 0.008f))) * 0.2f;
            char g = 0x00;
            char b = (127 + (127 * cos(y * 0.008f))) * 0.2f;
            char a = 0xFF;
            imageDat[(y * IMG_WIDTH) + x] = RGBA8(r, g, b, a);
        }
    }

    for(int i = 0; i < 64; i++){
        int size = rand() % 10;
        int x = rand() % (IMG_WIDTH - size);
        int y = rand() % (IMG_HEIGHT - size);
        for(int j = 0; j < size; j++){
            for(int k = 0; k < size; k++){
                imageDat[((y + k) * IMG_WIDTH) + (x + j)] = RGBA8(255, 255, 255, 255);
            }
        }
    }

    env->SetIntArrayRegion(imageArr, 0, IMG_WIDTH * IMG_HEIGHT, imageDat);
    return imageArr;
}