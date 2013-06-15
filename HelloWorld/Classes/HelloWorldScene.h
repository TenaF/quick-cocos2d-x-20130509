#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

class HelloWorld : public cocos2d::CCLayer, public cocos2d::extension::CCEditBoxDelegate
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
    static HelloWorld* curHelloWorld();
	
	// a selector callback
	virtual void menuCloseCallback(CCObject* pSender);

	// implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);

    void addSpriteRamdon(float dt);
    void addSpriteRamdon2(float dt);

    void addEditBox(float dt);
    virtual void editBoxEditingDidBegin(cocos2d::extension::CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::CCEditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::CCEditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::CCEditBox* editBox);

    void didAccelerate(cocos2d::CCAcceleration* pAccelerationValue);
private:
    cocos2d::CCLabelTTF *m_label;
    cocos2d::CCSprite *m_pBall;
};

#endif // __HELLOWORLD_SCENE_H__
