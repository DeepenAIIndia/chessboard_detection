#include <iostream>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Chessboard.h>
using namespace std;
using namespace cv;


cv::Size boardSize;

Result chessBoardCornersDetector(std::string image_path, int board_width, int board_height){
    
    // cout<<"function called"<<std::endl;
    cv::Mat image = cv::imread(image_path);
    // cout<<"Board Size:"<<boardSize<<std::endl;
    CornerDetection::Chessboard chessboard(boardSize, image);
    chessboard.findCorners(false);

    std::vector<cv::Point2f> corners_detected;
    Result result;

    bool ret = chessboard.cornersFound();
    // cout<<"Flag:"<<ret<<std::endl;
    result.flag = ret;
    
    if (ret)
    {
        corners_detected = chessboard.getCorners();
        result.corner = corners_detected;
        cout << "# INFO: Detected chessboard in image " << image_path << std::endl;

        cv::Mat sketch;
        chessboard.getSketch().copyTo(sketch);
        cv::imwrite(image_path.replace(image_path.end()-4, image_path.end(), "_sketch.jpg"), sketch);
    }
    else
    {
        cout << "# ERROR: Did not detect chessboard in image " << image_path << std::endl;
    }
    return result;

}



int main(int argc,char** argv){

    string image_path = argv[1];
    boardSize.width = stoi(argv[2]);
    boardSize.height = stoi(argv[3]);

    cout<<"MAIN function complied "<<boardSize.width<<" "<<boardSize.height<<" IMAGE PATH: "<<image_path<<std::endl;

    Result result = chessBoardCornersDetector(image_path,boardSize.width,boardSize.height);

    return 0;

}
