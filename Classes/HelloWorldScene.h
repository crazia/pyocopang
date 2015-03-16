#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameCoin.h"
#include <vector>

class HelloWorld : public cocos2d::Layer
{
public:
  // there's no 'id' in cpp, so we recommend returning the class instance pointer
  static cocos2d::Scene* createScene();


  // std::vector<auto> _gameCoins;
    
  enum {
    BOARDX = 7,
    BOARDY = 6,
    TOTALCOINTYPE = 4,
    TOTALADJCOIN = 6
  };


  int _lineDeadCoin[BOARDX];
  int _score;

  // for 프로그레스 바에 대한 체크 
  int _gameTime ;
  
  cocos2d::Label* _scoreFont;

  cocos2d::ProgressTimer * _progressTimeBar;

  void addNewCoin();
  void setNewCoin(GameCoin* coin);
  void addNewCoinAction();

  float scale_x , scale_y ; // 기기별로 확장할 수 있는 비율 저장 
  cocos2d::Size _visible ; // 기기별로 보이는 스크린 크기 
  cocos2d::Vector<cocos2d::Sprite*> _gameCoins;
  cocos2d::Vector<cocos2d::Sprite*> _selectMask;
  cocos2d::Vector<cocos2d::Sprite*> _selectCoins;
  int _lastCoin;
  int _selectedCoinCount ;

  static int _adjCoin[BOARDX * BOARDY] [TOTALADJCOIN];
    
  // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
  virtual bool init();

  bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
  void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
  void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
    
  // a selector callback
  void menuCloseCallback(cocos2d::Ref* pSender);
    
  // implement the "static create()" method manually
  CREATE_FUNC(HelloWorld);

  void initGameCoin();
  GameCoin * createGameCoin(const cocos2d::Vec2& pos, int type, int state);

  int checkPushGameCoin (cocos2d::Vec2& touchPos);
  int checkAdjacentCoin(cocos2d::Vec2& touchPos);
  bool inLastCoin(cocos2d::Vec2& touchPos);
  int addSelectCoins(int index);
  bool compareCoinType(int index1, int index2);

  // reset action
  void clearSelectCoin();
  void resetSelectMask();
  void resetGameInfo();


  void moveUpDeadCoin();
  void changeCoin(int index1, int index2);


  // animation 용 함수 추가
  void moveCoin(GameCoin* coin, cocos2d::Vec2& pos);
  void coinMoveDone(cocos2d::Node * pSender, GameCoin *pCoin);

  // 점수 저장 하는 부분 
  void addGameScore (int deadCoinNum);


  // time check 에 관해서
  void timeCount(float dt);
  void changeToOpeningScene();
};

#endif // __HELLOWORLD_SCENE_H__
