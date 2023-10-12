#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include <QTimer>
#include "map.h"
#include "heroplane.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动     p7
    void playGame();

    //更新所有元素的坐标
    void updatePosition();

    //绘制到屏幕中
    void paintEvent(QPaintEvent *);

    //地图对象
    Map m_map;

    //飞机对象
    HeroPlane m_hero;


    //定时器
    QTimer m_Timer;

};
#endif // MAINSCENE_H
