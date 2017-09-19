/**
* MultiLocker (GPLv3)
* Support by CTBeta Team http://ctbeta.org/
* Created by Jason C.H Feb 2017
*/
#ifndef CONFIG_H
#define CONFIG_H

//HAL DEFINITION
//定义硬件层
#include "HAL_ArduProMini.h"
//#include "HAL_ArduMega2560.h"

//AUTHTYPE DEFINITION(ONLY ONE)
//定义启用的认证类型(唯一启用)
//#define USE_RC522
//#define USE_LB522
#define USE_R308

//DATALINK DEFINITION(ONLY ONE)
//定义启用的认证存储（唯一启用）
#define USE_LOCAL

//DISPLAY DEFINITION
//显示屏相关
#define USE_DISPLAY
//Flip the screen
//旋转显示屏
//#define SCREEN_FLIP

/**
* DISPLAY TYPE DEFINITION
* 显示类型定义
* 1-OLED12864_IIC
* 2-LCD12864_IIC
*/
#ifdef USE_DISPLAY
  #define DISPLAY_TYPE U8GLIB_SSD1306_128X64
#endif


//MYSQL DEFINITION
//启用MYSQL数据库(仅在网络存储启用时可定义)
//#define USE_MYSQL
#ifdef  USE_MYSQL
  #define MYSQL_ADDRESS MYADDRESS
  #define MYSQL_DATABASE MultiLockers
  #define MYSQL_PASSWOED MYPASSWORFD
  #define MYSQL_TABLE MultiLockers
#endif


#endif
