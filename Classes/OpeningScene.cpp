#include "OpeningScene.h"

USING_NS_CC;

Scene* Opening::createScene() {

  auto scene = Scene::create();
  auto layer = Opening::create();

  scene->addChild(layer);

  return scene;
}


bool Opening::init() {

  //////////////////////////////
  // 1. super init first
  if ( !Layer::init() ) {
    return false;
  }
  
  Size visibleSize = Director::getInstance()->getVisibleSize();
  _visible = visibleSize ; // 저장 
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  auto openingImage = Sprite::create("startbg.jpg");
  Size contentsSize = openingImage->getContentSize();

  auto scale_x = visibleSize.width / contentsSize.width;
  auto scale_y = visibleSize.height / contentsSize.height;

  openingImage->setScaleX(scale_x);
  openingImage->setScaleY(scale_y);  

  openingImage->setPosition(Vec2(_visible.width * 0.5f,
                                 _visible.height * 0.5f));

  this->addChild(openingImage);

  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(Opening::onTouchBegan, this);
  _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

  return true;
}

void Opening::changeScene(void) {
  auto scene = HelloWorld::createScene();
  Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 255, 255)));
}

bool Opening::onTouchBegan(Touch *touch, Event *event) {

  changeScene();
  return true;
}
