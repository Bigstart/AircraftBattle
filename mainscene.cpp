#include "mainscene.h"
#include "config.h"
#include <QIcon>
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();

    //启动
    playGame();

}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //设置标题
    setWindowTitle(GAME_TITLE);

    //加载图标
    setWindowIcon(QIcon(GAME_ICON));

    //定时器
    m_Timer.setInterval(GAME_RATE);

    //敌机出场时间间隔 初始化
    m_recorder = 0;
}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //监听定时器发送的信号
    connect(&m_Timer,&QTimer::timeout,[=](){
        //敌机出厂
        enemyToScene();

        //更新游戏中元素的坐标
        updatePosition();

        //绘制到屏幕中
        update();

        //碰撞检测的调用
        collisionDetection();

    });

}

void MainScene::updatePosition()
{
    //更新地图的坐标
    m_map.mapPosition();
    //发射子弹
    m_hero.shoot();
    //计算所有非空闲子弹的当前坐标
    for(int i =0;i<BULLET_NUM;i++)
    {
        //如果非空闲，计算发射位置
        if(m_hero.m_bullets[i].m_Free==false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }
    //测试子弹
    //temp_Bullet.m_Free=false;
    //temp_Bullet.updatePosition();

    //敌机出厂
    for(int i =0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free == false)
        {
            m_enemys[i].updatePosition();
        }
    }

}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //绘制地图
    painter.drawPixmap(0,m_map.m_map1_posY,m_map.m_map1);
    painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

    //绘制英雄飞机
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_Plane);

    //绘制子弹
    for(int i =0;i<BULLET_NUM;i++)
    {
        if(m_hero.m_bullets[i].m_Free==false)
        {
            //如果非空闲，绘制
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }

    }

    //绘制敌机
    for(int i =0;i<ENEMY_NUM;i++)
    {
        if(m_enemys[i].m_Free==false)
        {
            //如果非空闲 绘制
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //测试子弹
    //painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);

}

void MainScene::keyPressEvent(QKeyEvent *event)
{
    // 按下上箭头键，y坐标减少
    if(event->key()==Qt::Key_Up)
    {
        m_hero.m_Y-=10;
    }

    // 按下下箭头键，y坐标增加
    else if(event->key()==Qt::Key_Down)
    {
        m_hero.m_Y+=10;
    }

    // 按下左箭头键，x坐标减少
    else if(event->key()==Qt::Key_Left)
    {
        m_hero.m_X-=10;
    }

    // 按下右箭头键，x坐标增加
    else if(event->key()==Qt::Key_Right)
    {
        m_hero.m_X+=10;
    }

    //边界检测
    if(m_hero.m_X<=-4)
    {
        m_hero.m_X=-4;
    }
    if(m_hero.m_X>=GAME_WIDTH-m_hero.m_Plane.width()+4)
    {
        m_hero.m_X=GAME_WIDTH-m_hero.m_Plane.width()+4;
    }
    if(m_hero.m_Y<=-3)
    {
        m_hero.m_Y=-3;
    }
    if(m_hero.m_Y>=GAME_HEIGHT-m_hero.m_Plane.height()+3)
    {
        m_hero.m_Y=GAME_HEIGHT-m_hero.m_Plane.height()+3;
    }



}

void MainScene::enemyToScene()
{
    m_recorder++;
    //未达到出场间隔直接return
    if(m_recorder<ENEMY_INTERVAL)
    {
        return;
    }
    m_recorder = 0;
    for(int i = 0;i<ENEMY_NUM;i++)
    {
        //如果是空闲敌机 出场
        if(m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free = false;

            //坐标
            m_enemys[i].m_X = rand()%(GAME_WIDTH-m_enemys[i].m_Rect.width());
            m_enemys[i].m_Y = -m_enemys[i].m_Rect.height();
            break;
        }
    }

}

void MainScene::collisionDetection()
{
    //遍历所有非空闲的敌机
    for(int i = 0;i<ENEMY_NUM;i++)
    {
        //如果是非空闲的飞机，执行下一次循环
        if(m_enemys[i].m_Free)
        {
            continue;
        }

        //遍历所有非空闲的子弹
        for(int j = 0;j<BULLET_NUM;j++)
        {
            if(m_hero.m_bullets[i].m_Free)
            {
                continue;
            }

            //如果子弹和飞机相交，发生碰撞。同时将飞机和子弹空闲状态设置为真
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free = true;
                m_hero.m_bullets[j].m_Free = true;
            }

        }
    }

}

