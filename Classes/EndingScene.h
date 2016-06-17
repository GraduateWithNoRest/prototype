//
//  EndingScene.h
//  test
//
//  Created by 전해성 on 2016. 6. 16..
//
//

#ifndef EndingScene_h
#define EndingScene_h

#include "cocos2d.h"

class EndingScene : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // menu callback
    void menuCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(EndingScene);
};

#endif /* EndingScene_h */
