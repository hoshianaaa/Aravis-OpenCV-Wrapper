#include "arv.h"
#include <iostream>
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[]){

  ArvCamera *camera;
  ArvStream *stream;
  GError *error = NULL;

  camera = arv_camera_new (NULL, &error);

  if (ARV_IS_CAMERA (camera)) {
    arv_camera_set_frame_rate (camera, 10.0, NULL);

    gint payload;
    payload = arv_camera_get_payload (camera, NULL);

    stream = arv_camera_create_stream (camera, NULL, NULL, &error);

    if (ARV_IS_STREAM (stream)) {

    for (int i=0;i<1000;i++)
    {
      arv_stream_push_buffer (stream, arv_buffer_new (payload, NULL));
    }

    arv_camera_start_acquisition (camera, NULL);

    int count = 0;

      while (true)
      {
        ArvBuffer *_buffer = NULL;
         _buffer = arv_stream_pop_buffer(stream);

         std::cout << count << ":";

         if (_buffer != NULL){
             size_t buffer_size;
             void* framebuffer = NULL;

            framebuffer = (void*)arv_buffer_get_data(_buffer, &buffer_size);

            cv::Mat src;
            src = cv::Mat (512, 512, CV_8UC1, (uchar*)framebuffer);
            cv::imshow("frame", src);
            int keypress = cv::waitKey(20) & 0xFF;

            std::cout  << buffer_size << std::endl;
         }
         else
         {
           std::cout << "buffer null!!!" << std::endl;
         }

         count++;

      }
    }
  }


return 0;
}
