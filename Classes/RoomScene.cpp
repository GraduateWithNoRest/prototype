//
//  RoomScene.cpp
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//

#include "RoomScene.h"
#include "RegisterScene.h"
#include "ScheduleScene.h"
#include "EndingScene.h"

USING_NS_CC;

Scene* RoomScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RoomScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RoomScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0,0,255,255)) )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto label_01 = Label::createWithTTF("Show Status",
                                         "fonts/Marker Felt.ttf", 60);
    label_01->setColor(Color3B::WHITE);
    auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(RoomScene::showNewLayer, this));
    
    auto label_02 = Label::createWithTTF("Go to Register Scene",
                                         "fonts/Marker Felt.ttf", 60);
    label_02->setColor(Color3B::WHITE);
    auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(RoomScene::changeRegisterScene, this));
    
    auto label_03 = Label::createWithTTF("Go to Schedule Scene",
                                         "fonts/Marker Felt.ttf", 60);
    label_03->setColor(Color3B::WHITE);
    auto item_03 = MenuItemLabel::create(label_03, CC_CALLBACK_1(RoomScene::changeScheduleScene, this));
    
    auto label_04 = Label::createWithTTF("Go to Ending Scene",
                                         "fonts/Marker Felt.ttf", 60);
    label_04->setColor(Color3B::WHITE);
    auto item_04 = MenuItemLabel::create(label_04, CC_CALLBACK_1(RoomScene::changeEndingScene, this));
    
    
    auto menu = Menu::create(item_01, item_02, item_03, item_04, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/5 + origin.y));
    this->addChild(menu, 1);
    
    
    // add listener for onTouchBegan
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(RoomScene::onTouchBegan, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
    myListener = listener;
    //listener->setEnabled(false);
    //Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
    
    // background image
    auto bgSprite = Sprite::create("background.png");
    bgSprite->setAnchorPoint(Point(0,0));
    bgSprite->setScale((double)750/450);
    this->addChild(bgSprite, 0);
    
    return true;
}

void RoomScene::onExit()
{
    LayerColor::onExit();
    
    myListener->setEnabled(false);
}

void RoomScene::showNewLayer(cocos2d::Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    
    if (auto layer = this->getChildByName("myLayer") ) {
        // layer->setVisible(true);
    }
    else {
        auto newLayer = LayerColor::create(Color4B::WHITE);
        
        newLayer->setContentSize(Size(visibleSize.width, visibleSize.height/4));
        newLayer->setAnchorPoint(Point(0, 0));
        newLayer->setPosition(Point(0, visibleSize.height*3/4));
        newLayer->setName("myLayer");
        /*
        auto s1 = Sprite::create("HelloWorld.png", Rect(0, 0, 100, 100));
        s1->setPosition(0, 0);
        s1->setAnchorPoint(Point(0, 0));
        newLayer->addChild(s1);
        
        auto s2 = Sprite::create("HelloWorld.png", Rect(0, 0, 100, 100));
        s1->setPosition(200, 0);
        s2->setAnchorPoint(Point(0, 0));
        newLayer->addChild(s2);
        */
        
        auto label_01 = Label::createWithSystemFont("label : 01", "Arial", 30);
        label_01->setPosition(Point(100,50));
        label_01->setColor(Color3B::BLACK);
        newLayer->addChild(label_01);
        
        auto label_02 = Label::createWithSystemFont("label : 02", "Arial", 30);
        label_02->setPosition(Point(100,100));
        label_02->setColor(Color3B::BLACK);
        newLayer->addChild(label_02);
        
        auto label_03 = Label::createWithSystemFont("label : 03", "Arial", 30);
        label_03->setPosition(Point(100,150));
        label_03->setColor(Color3B::BLACK);
        newLayer->addChild(label_03);
        
        auto label_04 = Label::createWithSystemFont("label : 04", "Arial", 30);
        label_04->setPosition(Point(100,200));
        label_04->setColor(Color3B::BLACK);
        newLayer->addChild(label_04);
        
        auto label_05 = Label::createWithSystemFont("label : 05", "Arial", 30);
        label_05->setPosition(Point(100,250));
        label_05->setColor(Color3B::BLACK);
        newLayer->addChild(label_05);
        
        auto label_06 = Label::createWithSystemFont("label : 06", "Arial", 30);
        label_06->setPosition(Point(100,300));
        label_06->setColor(Color3B::BLACK);
        newLayer->addChild(label_06);
        
        this->addChild(newLayer);
    }
}

bool RoomScene::onTouchBegan(Touch* touch, Event *unused_event)
{
    Point location = touch->getLocation();
    
    if (auto layer = this->getChildByName("myLayer")) {
        Rect rect = layer->getBoundingBox();
        
        if (rect.containsPoint(location))
            CCLOG("onTouchBegan");
        else {
            //layer->setVisible(false);
            this->removeChild(layer);
        }
    }
    return false;
}

void RoomScene::changeRegisterScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(RegisterScene::createScene());
    //Director::getInstance()->pushScene(RegisterScene::createScene());
}

void RoomScene::changeScheduleScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(ScheduleScene::createScene());
    //Director::getInstance()->pushScene(ScheduleScene::createScene());
}

void RoomScene::changeEndingScene(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(EndingScene::createScene());
}