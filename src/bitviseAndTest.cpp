#include <iostream>
using namespace std;
/**/
/*Bitwise And :
    color  : 100110111001010110110101
    mask   : 111111110000000000000000
    result : 100110110000000000000000 
    
    && : logical and, 
    & : bitwise and
*/
/**/
int main(){
    /**/
    int color =  0x123456;
    /**/
    int redMask = 0xFF0000;
    int greenMask = 0x00FF00;
    int blueMask = 0x0000FF;
    /**/
    int red = (color & redMask) >> 16;  //red = 12
    int green = (color & greenMask) >> 8; //green=34
    int blue = (color & blueMask); //blue=56
    /**/
    cout << "Red : " << red << endl;
    cout << "Blue : " << blue << endl;
    cout << "Green : " << green << endl;
    /**/
    /*---------Method  2 */
    /**/
    unsigned char red2 = (color & redMask) >> 16;  //red = 12
    unsigned char green2 = (color & greenMask) >> 8; //green=34
    unsigned char blue2 = (color & blueMask); //blue=56
    /**/
    cout << "Red : " << hex <<red2 << endl;
    cout << "Blue : " << hex <<blue2 << endl;
    cout << "Green : " << hex <<green2 << endl;
    return 0;
}