#include "mainscene.h"
#include "config.h"
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //调用初始化场景
    initScene();
}

MainScene::~MainScene()
{
}

void MainScene::initScene()  //初始化场景
{
    //设置窗口固定尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);
    //设置标题
    setWindowTitle(GAME_TITLE);
}

