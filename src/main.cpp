#include <iostream>
#include "file1.h"
#include "printer.h"
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    std::cout << "Enter two numbers\n";
    int number1;
    int number2;
    std::cin >> number1 >> number2;

    file1 calculator;
    printer p;
    p.printNumbers(number1, number2);
    int addition = calculator.add(number1, number2);
    p.printResult(addition);

    Mat image;
    image = imread("sample.jpeg");
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);

    return 0;

}


