#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include<fstream>
#include<iostream>

using namespace std;
using namespace cv;

/// Global Variables
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int delay = 20000;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Filter Demo 1";

/// Function headers
int display_caption( char* caption );
int display_dst( int delay );

/**
 * function main
 */
 
 int main( int argc, char** argv)
 {
   namedWindow( window_name, CV_WINDOW_AUTOSIZE );

   /// Load the source image
   src = imread(argv[1], 1 );

   //if( display_caption( "Original Image" ) != 0 ) { return 0; }

   dst = src.clone();
   //if( display_dst( DELAY_CAPTION ) != 0 ) { return 0; }

   /// Applying Homogeneous blur
   //if( display_caption( "Homogeneous Blur" ) != 0 ) { return 0; }
   
   int i;
   cout << "Enter i: " << endl;
   cin >> i; 
   switch(i){

   case 1:{

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
        { blur( src, dst, Size( i, i ), Point(-1,-1) );
           //if( display_dst( DELAY_BLUR ) != 0 ) { return 0; } }
            int display_caption( char* caption );
            int display_dst( int delay );
        }
   
   break;
   }
   }

 } 
    /// Applying Gaussian blur
    
 int display_caption( char* caption )
 {
   dst = Mat::zeros( src.size(), src.type() );
   putText( dst, caption,
            Point( src.cols/4, src.rows/2),
            CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

   imshow( window_name, dst );
   int c = waitKey( DELAY_CAPTION );
   if( c >= 0 ) { return -1; }
   return 0;
  }

  int display_dst( int delay )
  {
    imshow( window_name, dst );
    int c = waitKey ( delay );
    if( c >= 0 ) { return -1; }
    return 0;
  }
