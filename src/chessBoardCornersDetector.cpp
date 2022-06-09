#include <iostream>
#include <string>
#include <list>
#include <tuple>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Chessboard.h>
using namespace std;
using namespace cv;


list<tuple<float,float>> getChessBoardCorners(std::string image_path, int board_width, int board_height,const bool verbose){
    
    cv::Size boardSize;
    cv::Mat image = cv::imread(image_path);
    boardSize.width = board_width;
    boardSize.height = board_height;
    CornerDetection::Chessboard chessboard(boardSize, image);
    chessboard.findCorners(false);

    std::vector<cv::Point2f> corners_detected;
    list<tuple<float,float>> corners_list(board_height*board_width,make_tuple(0,0));

    bool ret = chessboard.cornersFound();

    if (ret)
    {
        corners_detected = chessboard.getCorners();
        cout << "# INFO: Detected chessboard in image " << image_path << std::endl;

        int i=0;
        for(auto it = corners_list.begin();it!=corners_list.end();it++){
            get<0>(*it)= corners_detected[i].x;
            get<1>(*it)= corners_detected[i].y;
            i++;
        }

    }
    else
    {
        cout << "# ERROR: Did not detect chessboard in image " << image_path << std::endl;
    }
    return corners_list;

}
