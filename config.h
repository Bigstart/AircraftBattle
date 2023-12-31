#ifndef CONFIG_H
#define CONFIG_H

//------------配置数据-----------------------
#define GAME_WIDTH  512    //宽度
#define GAME_HEIGHT 768    //高度
#define GAME_TITLE  "飞机大战 v0.0.1"      //标题
#define GAME_RES_PATH "./plane.rcc"       //rcc文件路径
#define GAME_ICON  ":/res/app.ico"       //图标
#define GAME_RATE  10     //定时器刷新时间间隔  单位毫秒

//------------地图配置数据-----------------------
#define MAP_PATH  ":/res/img_bg_level_1.jpg"   //地图路径
#define MAP_SCROLL_SPEED  1                    //地图滚动速度

//------------飞机配置数据-----------------------
#define HERO_PATH ":/res/hero2.png"

//------------子弹配置数据-----------------------
#define BULLET_PATH ":/res/bullet_11.png"   //子弹图片路径
#define BULLET_SPEED 5    //子弹移动速度
#define BULLET_NUM 30    //弹匣中子弹总数
#define BULLET_INTERVAL 25  //发射子弹时间间隔

//------------敌机配置数据-----------------------
#define ENEMY_PATH ":/res/img-plane_5.png"   //敌机资源图片
#define ENEMY_SPEED 2   //敌机移动速度
#define ENEMY_NUM  20   //敌机总数量
#define ENEMY_INTERVAL 140 //敌机出场时间间隔

#endif // CONFIG_H
