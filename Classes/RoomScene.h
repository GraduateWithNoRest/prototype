//
//  RoomScene.h
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//

#ifndef RoomScene_h
#define RoomScene_h

#include "cocos2d.h"

class RoomScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onExit();
    void showNewLayer(cocos2d::Ref* pSender);
    void changeRegisterScene(cocos2d::Ref* pSender);
    void changeScheduleScene(cocos2d::Ref* pSender);
    void changeEndingScene(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(RoomScene);
    
    // Override methods
    // virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
private:
    cocos2d::EventListenerTouchOneByOne* myListener;
};

#endif /* RoomScene_h */
