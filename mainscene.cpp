#include "mainscene.h"
#include "config.h"
#include <QIcon>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    initScene();

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
}

