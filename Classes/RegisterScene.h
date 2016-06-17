//
//  RegisterScene.h
//  test
//
//  Created by 전해성 on 2016. 6. 15..
//
//

#ifndef RegisterScene_h
#define RegisterScene_h

#include "cocos2d.h"

class RegisterScene : public cocos2d::Layer
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
    
    void menuItemCallback(cocos2d::CCObject* sender);

    
    // implement the "static create()" method manually
    CREATE_FUNC(RegisterScene);
};


#endif /* RegisterScene_h */
