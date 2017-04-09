#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "Definitions.h"
#include <iostream>

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        std::cout << "fout MainMenuScene.cpp" << std::endl;
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("Background.png");
    if (!backgroundSprite)
    {
        std::cerr << "Kan Background.png niet vinden" << std::endl;
        return false;
    }
    backgroundSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(backgroundSprite);

    std::cout << "Background is succes full printed" << std::endl;
    
    auto titleSprite = Sprite::create("Title.png");
    titleSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height - titleSprite->getContentSize().height));

    this->addChild(titleSprite);

    auto playItem = MenuItemImage::create("Play Button.png" , "Play Button Clicked.png", CC_CALLBACK_1(MainMenuScene::GoToGameScene, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    auto menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);

    return true;
}

void MainMenuScene::GoToGameScene(cocos2d::Ref *sender)
{
    std::cout << "Function MainMenuScene::GoToGameScene is active" << std::endl;
    auto scene = GameScene::createScene();

    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
