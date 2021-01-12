#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
    Mat image = imread("flower.jpg", IMREAD_UNCHANGED);
    if (image.empty())
    {
        cout << "error!!! No image exixts..." << endl;
        cin.get();
        return -1;
    }
    string windowname = "My Image";
    namedWindow(windowname, WINDOW_NORMAL);
    imshow(windowname, image);
    waitKey(0);
    destroyWindow(windowname);
    Mat src = imread("flower.jpg", IMREAD_UNCHANGED);
    Mat dst;
    Point2f pc(src.cols / 2., src.rows / 2.);
    int angle_rotation;
    cout<< "enter angle of rotation : \n";
    cin>>angle_rotation;
    Mat r = getRotationMatrix2D(pc,angle_rotation, 1.0);
    warpAffine(src, dst, r, src.size());
    imshow("rotated_im.jpg", dst);
    waitKey(0);

    return 0;
}
