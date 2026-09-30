#include<iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    Image I("C:\\Users\\ASUS\\Downloads\\wallpaperflare.com_wallpaper (10).jpg") ;

    int choice = 0;

    while (choice !=3  ) {
        cout << "choose the frame type you want for your image " << endl;
        cout << "1- simple frame " << endl;
        cout << "2- decorized frame " << endl;
        cout << "3- exit" << endl;
        cin >> choice;
        if (choice == 1){
            unsigned int B = 25 ;
            for (int i =0 ; i<I.width ; i++) {
                for (int j =0 ; j<I.height ; j++) {
                    for (int k =0 ; k<I.channels ; k++) {
                        if (i== I.width-1 ) {
                            I(i,j,k) = 255;
                        }
                        else if (i== 0) {
                            I(i,j,k) = 255;
                        }
                        else if (j== 0) {
                            I(i,j,k) = 255;
                        }
                        else if (j== I.height-1 ) {
                            I(i,j,k) = 255;
                        }
                        else if ((i >=I.width-(B+1)) && (i<I.width-1 )){
                            I(i,j,k) = 0;
                        }
                        else if (j >=I.height-(B+1) && (j<I.height-1 )) {
                            I(i,j,k) = 0 ;
                        }
                        else if (i == I.width-(B+2)) {
                            I(i,j,k) = 255;
                        }
                        else if (j == I.height-(B+2)) {
                            I(i,j,k) = 255;
                        }
                        else if (i <= B) {
                            I(i,j,k) = 0;
                        }
                        else if (j <= B) {
                            I(i,j,k) = 0;
                        }
                        else if (i ==B+1 ) {
                            I(i,j,k) = 255;
                        }
                        else if (j ==B+1 ) {
                            I(i,j,k) = 255;
                        }
                    }
                }
            }
            I.saveImage("C:\\Users\\ASUS\\Downloads\\zzzzz.png");
            cout <<"simple frame applied" << endl;
        }
        else if (choice == 2) {
            int B = 20;
            int W = 3;
            int c = 35;
            int corner = 3;

            for (int i = 0; i < I.width; i++) {
                 for (int j = 0; j < I.height; j++) {
                    for (int k = 0; k < I.channels; k++) {
                        if (i < B + corner && j < B + c) {
                            I(i, j, k) = 255;
                        }
                        else if (i < B + c && j < B + corner) {
                            I(i, j, k) = 255;
                        }
                        else if (i >= I.width - B - corner && j < B + c) {
                            I(i, j, k) = 255;
                        }
                        else if (i >= I.width - B - c && j < B + corner) {
                            I(i, j, k) = 255;
                        }
                        else if (i < B + corner && j >= I.height - B - c) {
                            I(i, j, k) = 255;
                        }
                        else if (i < B + c && j >= I.height - B - corner) {
                            I(i, j, k) = 255;
                        }
                        else if (i >= I.width - B - corner&& j >= I.height - B - c) {
                            I(i, j, k) = 255;
                        }
                        else if (i >= I.width - B - c && j >= I.height - B - corner) {
                            I(i, j, k) = 255;
                        }

                        else if (i < B || i >= I.width - B || j < B || j >= I.height - B) {
                          I(i, j, k) = 0;
                        }

                        else if (i < B + W || i >= I.width - B - W || j < B + W || j >= I.height - B - W) {
                            I(i, j, k) = 255;
                        }
                    }
                }
            }
            I.saveImage("C:\\Users\\ASUS\\Downloads\\x.png");
           cout <<"decorated frame applied" << endl;

        }
        else if (choice == 3) {
            cout<<"exiting this filter" << endl;
            break ;
        }
        else {
            cout << "invalid choice try again" << endl ;
        }
    }




    return 0;
}
