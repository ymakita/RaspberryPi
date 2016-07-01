/*******************************************************************************
Raspberry Pi用 I2C液晶 表示プログラム  raspi_lcd

本ソースリストおよびソフトウェアは、ライセンスフリーです。(詳細は別記)
利用、編集、再配布等が自由に行えますが、著作権表示の改変は禁止します。

I2C接続の小型液晶に文字を表示する

                                        Copyright (c) 2014-2016 Wataru KUNINO
                                        http://www.geocities.jp/bokunimowakaru/
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/soft_i2c.h"

typedef unsigned char byte;
extern int ERROR_CHECK;

int main(int argc,char **argv){
    int i=1;
    char s[49];
    s[0]='\0';
    if(argc >=2 && argv[1][0]=='-'){
        if(argc==2) strncat(s,"ｴﾗｰ ｦ ﾑｼ ｼﾃ ｿｳｼﾝ",47);
        ERROR_CHECK=0;
        i++;
    }
    if(argc==1) strncat(s,"ﾎﾞｸﾆﾓﾜｶﾙ Rasp.Pi",47);
    else while(i<argc && strlen(s)<16){
        strncat(s,argv[i],47);
        utf_del_uni(s);
        strncat(s," ",16);
        i++;
    }
    i2c_init();
    i2c_lcd_init();
    i2c_lcd_print(s);
    i2c_close();
    return 0;
}
