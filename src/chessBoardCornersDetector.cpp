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



list<list<tuple<float,float>>> getChessBoardCorners(list<std::string> images_path, int board_width, int board_height,const bool verbose){
    list<list<tuple<float,float>>> corners_detected_list;
    cv::Size boardSize;
    for(auto it1=images_path.begin();it1!=images_path.end();it1++){
        cv::Mat image = cv::imread(*it1);
        boardSize.width = board_width;
        boardSize.height = board_height;
        CornerDetection::Chessboard chessboard(boardSize, image);
        chessboard.findCorners(false);

        std::vector<cv::Point2f> corners_detected;
        list<tuple<float,float>> corners_list(board_height*board_width,make_tuple(0,0));

        bool ret = chessboard.cornersFound();

        if(ret){
                corners_detected = chessboard.getCorners();
                if(verbose){
                    cout << "# INFO: Detected chessboard in image " << *it1 << std::endl;
                }
                
            int i=0;
            auto it = corners_list.begin();
            for(it = corners_list.begin();it!=corners_list.end();it++){
                get<0>(*it)= corners_detected[i].x;
                get<1>(*it)= corners_detected[i].y;
                i++;
            }

            corners_detected_list.push_back(corners_list);
        }
        else
        {
            if(verbose){
                cout << "# ERROR: Did not detect chessboard in image " << *it1 << std::endl;
            }
        }
    }
    return ans;
}
