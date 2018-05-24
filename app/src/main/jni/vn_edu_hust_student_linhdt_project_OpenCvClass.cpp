#include "vn_edu_hust_student_linhdt_project_OpenCvClass.h"
JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_catDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectCat(frame);
  };

JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_dogDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectDog(frame);
  };

JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_buffaloDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectBuffalo(frame);
  };

JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_peopleDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectPeople(frame);
  };

JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_pigDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectPig(frame);
  };

JNIEXPORT void JNICALL Java_vn_edu_hust_student_linhdt_project_OpenCvClass_chickenDetection
  (JNIEnv *, jclass, jlong addrRgba){
    Mat& frame = *(Mat *)addrRgba;
    DetectChicken(frame);
  };

void DetectCat(Mat& frame) {
     String cat_cascade_name = "/storage/emulated/0/data/cat_detect.xml";
         CascadeClassifier cat_cascade;
     if( !cat_cascade.load( cat_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> cats;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect cats
     cat_cascade.detectMultiScale( frame_gray, cats, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<cats.size(); i++) {
         rectangle(frame, Point(cats[i].x, cats[i].y), Point(cats[i].x + cats[i].width, cats[i].y + cats[i].height), Scalar(0,255,0));
         cv::putText(frame, "con meo", cv::Point(cats[i].x, cats[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 255, 0), 2);
     }
}

void DetectDog(Mat& frame) {
     String dog_cascade_name = "/storage/emulated/0/data/dog_detect.xml";
     CascadeClassifier dog_cascade;
     if( !dog_cascade.load( dog_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> dogs;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect dogs
     dog_cascade.detectMultiScale( frame_gray, dogs, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<dogs.size(); i++) {
         rectangle(frame, Point(dogs[i].x, dogs[i].y), Point(dogs[i].x + dogs[i].width, dogs[i].y + dogs[i].height), Scalar(255,0,0));
         cv::putText(frame, "con cho", cv::Point(dogs[i].x, dogs[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 0), 2);
     }
}

void DetectBuffalo(Mat& frame) {
     String buffalo_cascade_name = "/storage/emulated/0/data/buffalo_detect.xml";
         CascadeClassifier buffalo_cascade;
     if( !buffalo_cascade.load( buffalo_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> buffalo;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect buffalo
     buffalo_cascade.detectMultiScale( frame_gray, buffalo, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<buffalo.size(); i++) {
         rectangle(frame, Point(buffalo[i].x, buffalo[i].y), Point(buffalo[i].x + buffalo[i].width, buffalo[i].y + buffalo[i].height), Scalar(0,0,255));
         cv::putText(frame, "con trau", cv::Point(buffalo[i].x, buffalo[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 0, 255), 2);
     }
}

void DetectPeople(Mat& frame) {
     String people_cascade_name = "/storage/emulated/0/data/face_people.xml";
         CascadeClassifier people_cascade;
     if( !people_cascade.load( people_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> peoples;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect peoples
     people_cascade.detectMultiScale( frame_gray, peoples, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<peoples.size(); i++) {
         rectangle(frame, Point(peoples[i].x, peoples[i].y), Point(peoples[i].x + peoples[i].width, peoples[i].y + peoples[i].height), Scalar(255,0,255));
         cv::putText(frame, "con nguoi", cv::Point(peoples[i].x, peoples[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 255), 2);
     }
}

void DetectPig(Mat& frame) {
     String pig_cascade_name = "/storage/emulated/0/data/pig_detect.xml";
         CascadeClassifier pig_cascade;
     if( !pig_cascade.load( pig_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> pigs;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect pigs
     pig_cascade.detectMultiScale( frame_gray, pigs, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<pigs.size(); i++) {
         rectangle(frame, Point(pigs[i].x, pigs[i].y), Point(pigs[i].x + pigs[i].width, pigs[i].y + pigs[i].height), Scalar(255,0,255));
         cv::putText(frame, "con lon", cv::Point(pigs[i].x, pigs[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 255), 2);
     }
}

void DetectChicken(Mat& frame) {
     String chicken_cascade_name = "/storage/emulated/0/data/chicken_detect.xml";
         CascadeClassifier chicken_cascade;
     if( !chicken_cascade.load( chicken_cascade_name ) ) {
         printf("--(!)Error loading face cascade\n");
         return;
     };

     std::vector<Rect> chickens;
     Mat frame_gray;
     cvtColor( frame, frame_gray, CV_BGR2GRAY );
     equalizeHist( frame_gray, frame_gray );
     //-- Detect chickens
     chicken_cascade.detectMultiScale( frame_gray, chickens, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
     for (int i=0; i<chickens.size(); i++) {
         rectangle(frame, Point(chickens[i].x, chickens[i].y), Point(chickens[i].x + chickens[i].width, chickens[i].y + chickens[i].height), Scalar(255,192,203));
         cv::putText(frame, "con ga", cv::Point(chickens[i].x, chickens[i].y - 2), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255,192,203), 2);
     }
}


