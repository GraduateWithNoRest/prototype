//
//  ScheduleScene.h
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//

#ifndef ScheduleScene_h
#define ScheduleScene_h

#include "cocos2d.h"

class ScheduleScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void onEnter();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // menu callback
    void nextSchedule(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(ScheduleScene);
    
private:
    // nextSchedule 메서드에서 touch 횟수 세는 변수.
    int sOrder;
};

#endif /* ScheduleScene_h */
