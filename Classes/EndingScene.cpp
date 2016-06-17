//
//  EndingScene.cpp
//  test
//
//  Created by 전해성 on 2016. 6. 16..
//
//

#include "EndingScene.h"
#include "HelloWorldScene.h"
USING_NS_CC;

Scene* EndingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = EndingScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool EndingScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(128,128,128,255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // 메뉴 그리기
    auto label_01 = Label::createWithTTF("Congraturation!",
                                         "fonts/Marker Felt.ttf", 60);
    label_01->setColor(Color3B::WHITE);
    auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(EndingScene::menuCallback, this));
    
    auto label_02 = Label::createWithTTF("Exit",
                                         "fonts/Marker Felt.ttf", 60);
    label_02->setColor(Color3B::WHITE);
    auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(EndingScene::menuCloseCallback, this));
    

    auto menu = Menu::create(item_01, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(menu, 1);
    
    
    // 엔딩 검사하는 메서드로부터
    // 어떤 엔딩 이미지를 그릴지 알아와서
    

    // 해당하는 엔딩 이미지 출력하기
    
    auto newLayer = Sprite::create("major_computer_introduction.jpg");
    //newLayer2->setContentSize(Size(visibleSize.width/4, visibleSize.height/4));
    newLayer->setAnchorPoint(Point(0.5, 0.5));
    //newLayer->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    newLayer->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
    this->addChild(newLayer, 0);
    
    
    
    
    return true;
}

void EndingScene::menuCallback(Ref* pSender)
{
    // 첫화면으로 이동
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}

void EndingScene::menuCloseCallback(Ref* pSender)
{

}
