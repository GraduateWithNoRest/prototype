//
//  ScheduleScene.cpp
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//

#include "ScheduleScene.h"
#include "RoomScene.h"

USING_NS_CC;



Scene* ScheduleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ScheduleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ScheduleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /*
     /////////////////////////////
     // 2. add a menu item with "X" image, which is clicked to quit the program
     //    you may modify it.
     
     // add a "close" icon to exit the progress. it's an autorelease object
     auto closeItem = MenuItemImage::create(
     "CloseNormal.png",
     "CloseSelected.png",
     CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
     
     closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
     origin.y + closeItem->getContentSize().height/2));
     
     // create menu, it's an autorelease object
     auto menu = Menu::create(closeItem, NULL);
     menu->setPosition(Vec2::ZERO);
     this->addChild(menu, 1);
     */
    /*
     /////////////////////////////
     // 3. add your codes below...
     
     // add a label shows "Hello World"
     // create and initialize a label
     
     auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
     
     // position the label on the center of the screen
     label->setPosition(Vec2(origin.x + visibleSize.width/2,
     origin.y + visibleSize.height - label->getContentSize().height));
     
     // add the label as a child to this layer
     this->addChild(label, 1);
     
     // add "HelloWorld" splash screen"
     auto sprite = Sprite::create("HelloWorld.png");
     
     // position the sprite on the center of the screen
     sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
     
     // add the sprite as a child to this layer
     this->addChild(sprite, 0);
     */
    
    auto label_01 = Label::createWithTTF("Next Schedule",
                                         "fonts/Marker Felt.ttf", 60);
    label_01->setColor(Color3B::WHITE);
    auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(ScheduleScene::nextSchedule, this));
    
    auto label_02 = Label::createWithTTF("Back",
                                         "fonts/Marker Felt.ttf", 60);
    label_02->setColor(Color3B::WHITE);
    auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(ScheduleScene::menuCloseCallback, this));
    
    auto menu = Menu::create(item_01, item_02, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/6 + origin.y));
    this->addChild(menu, 1);
    
    // background image
    //auto bgSprite = Sprite::create("background.png");
    auto bgSprite = Sprite::create("background.png", Rect::Rect(0,0,450,175));
    bgSprite->setPosition(Point(0, visibleSize.height));
    bgSprite->setAnchorPoint(Point(0,1));
    bgSprite->setScale((double)750/450);
    this->addChild(bgSprite, 0);
    
    
    return true;
}

void ScheduleScene::onEnter()
{
    Layer::onEnter();
    
    // your code goes here.
    sOrder = 0;
}

// 다음 스케줄을 보여줍니다.
void ScheduleScene::nextSchedule(cocos2d::Ref* pSender)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // 존재한다면, 전에 그렸던 그림 지우기
    if(auto sprite = getChildByName("Sprite_Schedule"))
        this->removeChild(sprite);
    
    // 날짜 하나 진행시키는 코드.
    
    
    
    // 만약 방에 돌아갈 시간이라면
    // 방(RoomScene)으로 화면 전환.
    
    
    
    // 방에 가지 않고 일정을 진행하는 시간이라면
    // 그 날짜에 해당하는 이벤트를 알아와서, 맞는 그림을 그리기.
    
    switch(sOrder) {
        case 0: {
            // 컴퓨터공학개론.
            auto sprite = Sprite::create("major_computer_introduction.jpg");
            sprite->setName("Sprite_Schedule");
            sprite->setPosition(Vec2(origin.x + visibleSize.width/2,
                                     origin.y + visibleSize.height/2));
            sprite->setAnchorPoint(Point(0.5,0.5));
            sprite->setScale(1.8);
            this->addChild(sprite);
            break;
        }
        case 1: {
            // 남성과여성.
            auto sprite = Sprite::create("culture_male_and_female.jpg");
            sprite->setName("Sprite_Schedule");
            sprite->setPosition(Vec2(origin.x + visibleSize.width/2,
                                     origin.y + visibleSize.height/2));
            sprite->setAnchorPoint(Point(0.5,0.5));
            sprite->setScale(1.6);
            this->addChild(sprite);
            break;
        }
        case 2: {
            // RoomScene 으로 이동.
            //Director::getInstance()->popScene();
            Director::getInstance()->replaceScene(RoomScene::createScene());
            break;
        }
        default:
            break;
    }
    /*
    // Sprite 그리는 코드
    auto sprite = Sprite::create("major_computer_introduction.jpg");
    sprite->setPosition(Vec2(origin.x + visibleSize.width/2,
                             origin.y + visibleSize.height/2));
    sprite->setAnchorPoint(Point(0.5,0.5));
    sprite->setScale(2.0);
    this->addChild(sprite);
    */
    
    // switch문에 썼던 변수 1증가
    sOrder += 1;
}

// a selector callback
void ScheduleScene::menuCloseCallback(cocos2d::Ref* pSender)
{
    // 뒤로 버튼.
    // Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(RoomScene::createScene());
}