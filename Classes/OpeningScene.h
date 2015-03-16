#ifndef _OPENINGSCENE_H_
#define _OPENINGSCENE_H_

#include "cocos2d.h"
#include "HelloWorldScene.h"

class Opening : public cocos2d::Layer {

  cocos2d::Size _visible;
  
public:

  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();


  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();
  bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);

  void changeScene(void);
  
  CREATE_FUNC(Opening);

};


#endif /* _OPENINGSCENE_H_ */


