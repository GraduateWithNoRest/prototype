//
//  RegisterScene.cpp
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//
#include "RegisterScene.h"
#include "RoomScene.h"

USING_NS_CC;

Scene* RegisterScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = RegisterScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool RegisterScene::init()
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
    
    auto label_01 = Label::createWithTTF("RegisterScene",
                                         "fonts/Marker Felt.ttf", 60);
    label_01->setColor(Color3B::WHITE);
    auto item_01 = MenuItemLabel::create(label_01, CC_CALLBACK_1(RegisterScene::menuCallback, this));
    
    auto label_02 = Label::createWithTTF("Back",
                                         "fonts/Marker Felt.ttf", 60);
    label_02->setColor(Color3B::WHITE);
    auto item_02 = MenuItemLabel::create(label_02, CC_CALLBACK_1(RegisterScene::menuCloseCallback, this));
    
    
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
    
    
    // 전공, 교양 과목 선택하는 그림
    
    // 수강신청 확인창?
    
    // 스크롤뷰 구현하면 좋음
    
    return true;
}

// menu callback
void RegisterScene::menuCallback(cocos2d::Ref* pSender)
{
    
}

// a selector callback
void RegisterScene::menuCloseCallback(cocos2d::Ref* pSender)
{
    //Director::getInstance()->popScene();
    Director::getInstance()->replaceScene(RoomScene::createScene());
}
