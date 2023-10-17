#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"
#include "bullet.h"
#include "enemyplane.h"
#include <ctime>

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动
    void playGame();

    //更新所有元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //飞机移动事件
    void keyPressEvent(QKeyEvent* event);

    void enemyToScene();    //敌机出厂

    EnemyPlane m_enemys[ENEMY_NUM];   //敌机数组

    int m_recorder;    //敌机出场间隔记录

    //随机数种子
    srand((unsigned int) time(NULL));

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_hero;

    //定时器
    QTimer m_Timer;

    //测试子弹 子弹对象
    //Bullet temp_Bullet;

};
#endif // MAINSCENE_H
