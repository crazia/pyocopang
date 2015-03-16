#include "HelloWorldScene.h"
#include "OpeningScene.h"
USING_NS_CC;

int HelloWorld::_adjCoin[BOARDX * BOARDY][TOTALADJCOIN] = { 
    {-1, -1,  1,  7,  6, -1},   // 0, line 1
    {-1, -1,  2,  8,  7,  0}, 
    {-1, -1,  3,  9,  8,  1}, 
    {-1, -1,  4, 10,  9,  2}, 
    {-1, -1,  5, 11, 10,  3}, 
    {-1, -1, -1, -1, 11,  4}, 
    {-1,  0,  7, 12, -1, -1},   // 6, line 2
    { 0,  1,  8, 13, 12,  6}, 
    { 1,  2,  9, 14, 13,  7}, 
    { 2,  3, 10, 15, 14,  8}, 
    { 3,  4, 11, 16, 15,  9}, 
    { 4,  5, -1, 17, 16, 10},
    { 6,  7, 13, 19, 18, -1},   // 12, line 3
    { 7,  8, 14, 20, 19, 12},
    { 8,  9, 15, 21, 20, 13},
    { 9, 10, 16, 22, 21, 14},
    {10, 11, 17, 23, 22, 15},
    {11, -1, -1, -1, 23, 16},
    {-1, 12, 19, 24, -1, -1},   // 18, line 4
    {12, 13, 20, 25, 24, 18},
    {13, 14, 21, 26, 25, 19},
    {14, 15, 22, 27, 26, 20},
    {15, 16, 23, 28, 27, 21},
    {16, 17, -1, 29, 28, 22},
    {18, 19, 25, 31, 30, -1},   // 24, line 5
    {19, 20, 26, 32, 31, 24},
    {20, 21, 27, 33, 32, 25},
    {21, 22, 28, 34, 33, 26},
    {22, 23, 29, 35, 34, 27},
    {23, -1, -1, -1, 35, 28},
    {-1, 24, 31, 36, -1, -1},   // 30, line 6
    {24, 25, 32, 37, 36, 30},
    {25, 26, 33, 38, 37, 31},
    {26, 27, 34, 39, 38, 32},
    {27, 28, 35, 40, 39, 33},
    {28, 29, -1, 41, 40, 34},
    {30, 31, 37, -1, -1, -1},   // 36, line 7
    {31, 32, 38, -1, -1, 36},
    {32, 33, 39, -1, -1, 37},
    {33, 34, 40, -1, -1, 38},
    {34, 35, 41, -1, -1, 39},
    {35, -1, -1, -1, -1, 40},
};


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    _visible = visibleSize ; // 저장 
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    // auto closeItem = MenuItemImage::create(
    //                                        "CloseNormal.png",
    //                                        "CloseSelected.png",
    //                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    // closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
    // origin.y + closeItem->getContentSize().height/2));

    // closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width ,
    //                             origin.y + closeItem->getContentSize().height));    
    // closeItem->setScale(2.0);

    // create menu, it's an autorelease object
    // auto menu = Menu::create(closeItem, NULL);
    // menu->setPosition(Vec2::ZERO);
    // this->addChild(menu, 1);

    auto background = Sprite::create("game_back.png");
    Size contentsSize = background->getContentSize();

    scale_x = visibleSize.width / contentsSize.width;
    scale_y = visibleSize.height / contentsSize.height;

    
    background->setPosition(Vec2(visibleSize.width * 0.5f , visibleSize.height * 0.5f));
    //background->setScale(1.3f);
    background->setScaleX(scale_x);
    background->setScaleY(scale_y);
    this->addChild(background);

    auto tree1 = Sprite::create("tree_01.png");
    tree1->setPosition(Vec2(visibleSize.width * 0.2f, visibleSize.height * 0.75f));
    tree1->setScaleX(scale_x);
    tree1->setScaleY(scale_y);
    // tree1->setScale(1.3f);
    tree1->setAnchorPoint(Vec2(0.5, 0.0));
    this->addChild(tree1, 1);

    auto tree2 = Sprite::create("tree_02.png");
    tree2->setPosition(Vec2(visibleSize.width * 0.35f, visibleSize.height * 0.75f));
    tree2->setAnchorPoint(Vec2(0.5, 0.0));
    tree2->setScaleX(scale_x);
    tree2->setScaleY(scale_y);
    //tree2->setScale(1.3f);    
    this->addChild(tree2, 1);

    auto tree3 = Sprite::create("tree_03.png");
    tree3->setPosition(Vec2(visibleSize.width * 0.75f, visibleSize.height * 0.75f));
    // tree3->setScale(1.3f);
    tree3->setScaleX(scale_x);
    tree3->setScaleY(scale_y);
    tree3->setAnchorPoint(Vec2(0.5, 0.0));
    this->addChild(tree3, 1);
    
    auto enemy = Sprite::create("enemy_01.png");
    enemy->setPosition(Vec2(visibleSize.width * 0.6f, visibleSize.height * 0.75f));
    enemy->setAnchorPoint(Vec2(0.5, 0.0));
    enemy->setScaleX(scale_x);
    enemy->setScaleY(scale_y);
    // enemy->setScale(1.3f);
    this->addChild(enemy, 1);

    // action

    auto rotateTo1 = RotateTo::create(1.2f, -10.0f);
    auto rotateTo2 = RotateTo::create(1.2f, 10.0f);

    auto easeInOut1 = EaseInOut::create(rotateTo1->clone(), 2);
    auto easeInOut2 = EaseInOut::create(rotateTo2->clone(), 2);

    auto seq1 = Sequence::create(easeInOut1 , easeInOut2, nullptr);

    enemy->runAction(RepeatForever::create(seq1));

    auto rotateTo3 = RotateTo::create(2.0f, -5.0f);
    auto rotateTo4 = RotateTo::create(2.0f, 5.0f);

    auto easeInOut3 = EaseInOut::create(rotateTo3, 2);
    auto easeInOut4 = EaseInOut::create(rotateTo4, 2);

    auto seq2 = Sequence::create(easeInOut3, easeInOut4, nullptr);

    tree1->runAction(RepeatForever::create(seq2->clone()));
    tree2->runAction(RepeatForever::create(seq2->clone()));
    tree3->runAction(RepeatForever::create(seq2->clone()));

    // font 설정 
    
    _scoreFont = Label::createWithBMFont("fonts/font.fnt", "0");
    _scoreFont->setAnchorPoint(Vec2(1, 0.5));
    _scoreFont->setPosition(Vec2(_visible.width * 0.55f, _visible.height * 0.95f));
    _scoreFont->setScale(1.5f);
    this->addChild(_scoreFont);


    // progess Time Bar
    auto timeBar = Sprite::create("timebar.png");
    _progressTimeBar = ProgressTimer::create(timeBar);
    _progressTimeBar->setPosition(Vec2(_visible.width* 0.5f, 27));
    _progressTimeBar->setPercentage(100.0f);
    _progressTimeBar->setMidpoint(Vec2(0, 0.5f));
    _progressTimeBar->setBarChangeRate(Vec2(1, 0));
    _progressTimeBar->setType(ProgressTimer::Type::BAR);

    this->addChild(_progressTimeBar);
    _progressTimeBar->runAction(ProgressTo::create(60, 0));

    auto timeOutLine = Sprite::create("timeoutline.png");
    timeOutLine->setPosition(Vec2(_visible.width * 0.5 , 27));
    this->addChild(timeOutLine);

    initGameCoin();

    this->schedule(schedule_selector(HelloWorld::timeCount), 1.0f);
    
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    // ####   추가   ####
    // backbutton 이 가능하게 해주기 위해서 
    // this->setKeyboardEnabled( true );



    // touch Event setting
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    auto keyListener = EventListenerKeyboard::create();
    keyListener->onKeyReleased = [=] (EventKeyboard::KeyCode keycode, Event *event) {
      if (keycode == EventKeyboard::KeyCode::KEY_BACK) {
        Director::getInstance()->end();
      } 
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);
    
    return true;
}



// ####   추가   ####
// void HelloWorld::onKeyReleased( cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event *event )
// {
//   if (keycode == EventKeyboard::KeyCode::KEY_BACK) {
//         Director::getInstance()->end();
//     }
// }


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::initGameCoin() {
  int coinXPos = 0;
  int coinYPos = 0;

  _score = 0;

  _lastCoin = -1 ;
  _selectedCoinCount = 0;
  
  // screen size
  // x : 1080 , y : 1776 
  int diffX = _visible.width * 0.1356f;
  int diffY = _visible.height * 0.09445f;
  // int diffX = 134;
  // int diffY = 155;

  log("screen x : %f , screen y : %f", _visible.width , _visible.height);

  // int initCoinXPos = 141;
  // int initCoinYPos = 1063;

  int initCoinXPos = _visible.width * 0.098f;
  int initCoinYPos = _visible.height * 0.608f;
  
  GameCoin* gameCoin;

  srand((unsigned int) time(NULL));

  for (int i = 0; i < BOARDX; i++){
    coinXPos = initCoinXPos + (i * diffX);
    coinYPos = initCoinYPos;
    if (i % 2 == 0) 
      coinYPos -= diffY/2;

    for (int j = 0; j < BOARDY; j++){
      gameCoin = createGameCoin(Vec2(coinXPos , coinYPos),
                                rand() % TOTALCOINTYPE + 1,
                                GameCoin::LIVE);

      _gameCoins.pushBack(gameCoin);

      // log("now x: %d , y: %d\n" , i, j);

      coinYPos -= diffY;
    }
  }

  Sprite * selectMask ;

  for (int i = 0; i < BOARDX; i++){
    coinXPos = initCoinXPos + (i * diffX);
    coinYPos = initCoinYPos;
    if(i % 2 == 0)
      coinYPos -= diffY/2;

    for (int j = 0; j< BOARDY ; j++){
      selectMask = Sprite::create("selectTile.png");
      selectMask->setVisible(false);
      selectMask->setPosition(Vec2(coinXPos, coinYPos));
      selectMask->setScale(0.6f);
      this->addChild(selectMask);

      _selectMask.pushBack(selectMask);

      coinYPos -= diffY;
    }
    
  }

  _gameTime = 60;
}

GameCoin* HelloWorld::createGameCoin(const cocos2d::Vec2& pos, int type, int state) {
  GameCoin* gameCoin;
  

  std::string name = StringUtils::format("coin_0%i.png", type);
  gameCoin = GameCoin::spriteWithFile(name.c_str());
  gameCoin->setVisible(true);
  gameCoin->setPosition(pos);
  gameCoin->setScaleX(scale_x);
  gameCoin->setScaleY(scale_y);  
  // gameCoin->setScale(1.4f);
  gameCoin->setState(state);
  gameCoin->setType(type);

  this->addChild(gameCoin);

  return gameCoin;
}


bool HelloWorld::onTouchBegan(Touch *touch, Event *event) {
  auto touchLocation = touch->getLocation();
  log("onTouchBegan : loc %f , %f\n" , touchLocation.x , touchLocation.y);
  _lastCoin = checkPushGameCoin(touchLocation);

  // 현재 셀렉션을 추가하는 부분이 들어가야 한다.
  if (_lastCoin >= 0) 
    addSelectCoins(_lastCoin);
  return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *event) {
  auto touchPoint = touch->getLocation();

  if (inLastCoin(touchPoint) == false) {
    int newCoin = checkAdjacentCoin(touchPoint);

    if (compareCoinType (_lastCoin, newCoin)) {
      _lastCoin = newCoin;
      addSelectCoins(_lastCoin);
    }
  }
}

void HelloWorld::onTouchEnded(Touch *touch, Event *event) {


  clearSelectCoin();
  moveUpDeadCoin();
  addNewCoin();
}

int HelloWorld::checkPushGameCoin(Vec2& touchPos) {
  int index;
  GameCoin * tmpCoin ;

  for (int i = 0; i < _gameCoins.size(); i++){
    tmpCoin = (GameCoin*) _gameCoins.at(i);

    if (tmpCoin->getBoundingBox().containsPoint(touchPos) == true) {

      return i;
    }
  }

  return -1;
}


bool HelloWorld::inLastCoin(Vec2& touchPos) {

  if(_lastCoin == -1)
    return false;

  GameCoin * lastCoin = (GameCoin *)_gameCoins.at(_lastCoin);
  if(lastCoin->getBoundingBox().containsPoint(touchPos) == true)
    return true;

  return false;
}

int HelloWorld::checkAdjacentCoin(Vec2& touchPos) {
  if(_lastCoin < 0)
    return -1;

  for (int i = 0; i < 6; i++){
    if(_adjCoin[_lastCoin][i] == -1)
      continue;

    GameCoin* tmpCoin = (GameCoin *) _gameCoins.at(_adjCoin[_lastCoin][i]);

    if(tmpCoin->getBoundingBox().containsPoint(touchPos) == true)
      return _adjCoin[_lastCoin][i];
  }

  return -1;

}

bool HelloWorld::compareCoinType(int index1, int index2) {
  if (index1 < 0 || index2 < 0)
    return false;

  GameCoin* tempCoin1 = (GameCoin *) _gameCoins.at(index1);
  GameCoin* tempCoin2 = (GameCoin *) _gameCoins.at(index2);

  if(tempCoin1->getType() == tempCoin2->getType())
    return true;

  return false;
}


int HelloWorld::addSelectCoins(int index) {
  if(index < 0)
    return -1;

  GameCoin* tmpCoin = (GameCoin*) _gameCoins.at(index);
  Sprite * selectMask = (Sprite *) _selectMask.at(index);

  if (tmpCoin->getState() != GameCoin::SELECT) {
    tmpCoin->setState(GameCoin::SELECT);
    _selectCoins.pushBack(tmpCoin);

    selectMask->setVisible(true);
  }

  _selectedCoinCount ++ ;

  return 0;
}

void HelloWorld::clearSelectCoin() {

  if (_selectedCoinCount >= 3) {
    addGameScore(_selectedCoinCount);
    
    for (int i = 0; i < _selectCoins.size() ; i++){
      GameCoin* tmpCoin = (GameCoin*) _selectCoins.at(i);
      tmpCoin->setState(GameCoin::DEAD);
      tmpCoin->setVisible(false);
    }
  } else {
    for (int i = 0; i < _selectCoins.size(); i++){
      auto tmpCoin = (GameCoin*) _selectCoins.at(i);
      tmpCoin->setState(GameCoin::LIVE);
    }
  }

  resetSelectMask();
  resetGameInfo();
}


void HelloWorld::resetSelectMask() {

  // 추후에는 GameCoin 에 mask sprite 를
  // child 로 붙여서 같이 움직이게 하면 좋을 것으로 보인다. 
  
  for (int i = 0; i < _selectMask.size(); i++){
    auto selectMask = _selectMask.at(i);
    selectMask->setVisible(false);
  }

}

void HelloWorld::resetGameInfo() {
  _selectedCoinCount = 0;
  _lastCoin = -1;
  _selectCoins.clear();
}


void HelloWorld::moveUpDeadCoin() {

  for (int i = 0; i < BOARDX; i++){
    int bottomPos = ((i + 1) * BOARDY) - 1;
    int deadCoinNum = 0;

    for (int y = bottomPos ; y > bottomPos - BOARDY ; y--){
      auto coin = (GameCoin*) _gameCoins.at(y);
      if (coin->getState() == GameCoin::DEAD) {
        deadCoinNum++;
        continue;
      }

      if (deadCoinNum > 0)
        changeCoin(y, y + deadCoinNum);
    }
  }
}

void HelloWorld::changeCoin(int index1, int index2) {
  auto tmpCoin1 = (GameCoin*) _gameCoins.at(index1);
  auto tmpCoin2 = (GameCoin*) _gameCoins.at(index2);

  auto tmpPos = tmpCoin2->getPosition();
  tmpCoin2->setPosition(tmpCoin1->getPosition());
  //tmpCoin1->setPosition(tmpPos);
  moveCoin(tmpCoin1, tmpPos);

  _gameCoins.swap(index1, index2);
}


void HelloWorld::moveCoin(GameCoin* coin, Vec2& pos) {
  float duration = 0.0f;
  float coinSpeed = 1000.0f;
  auto prevPos = coin->getPosition();

  coin->setState(GameCoin::MOVE);
  coin->stopAllActions();

  duration = prevPos.getDistance(pos) / coinSpeed;


  auto action = Sequence::create(
        MoveTo::create(duration, pos),
        CallFuncN::create( CC_CALLBACK_1(HelloWorld::coinMoveDone, this, coin)),
        nullptr);
  
  coin->runAction(action);
}

void HelloWorld::coinMoveDone(Node* pSender, GameCoin * pCoin)
{
  // GameCoin* coin = (GameCoin*)pSender;
 
  pCoin->stopAllActions();
  pCoin->setState(GameCoin::LIVE);
}


void HelloWorld::addNewCoin() {
  GameCoin * coin;


  for (int i = 0; i < BOARDX; i++){
    _lineDeadCoin[i] = 0;
  }

  for (int i = 0; i < _gameCoins.size(); i++){
    auto coin = (GameCoin *) _gameCoins.at(i);

    if (coin->getState() == GameCoin::DEAD) {
      int line = (int) (i / BOARDY);
      _lineDeadCoin[line] += 1;

      setNewCoin(coin);
    }
  }

  addNewCoinAction();
}

void HelloWorld::setNewCoin(GameCoin* coin) {
  // srand((unsigned int) time(NULL));  
  auto type = rand() % TOTALCOINTYPE + 1;

  log("setNew coin : %d" , type);
  
  std::string name = StringUtils::format("coin_0%i.png", type);
  auto tex = Director::getInstance()->getTextureCache()->addImage(name.c_str());

  coin->setTexture(tex);
  coin->setVisible(true);
  coin->setType(type);
  coin->setState(GameCoin::LIVE);

}

void HelloWorld::addNewCoinAction() {
  int diffY = _visible.height * 0.09445f;

  for (int i = 0; i < BOARDX; i++){
    if (_lineDeadCoin[i] > 0) {
      auto startIndex = i * BOARDY ;

      for (int j = startIndex; j < startIndex + _lineDeadCoin[i] ; j++){
        auto coin = (GameCoin*) _gameCoins.at(j);
        auto pos = coin->getPosition();
        coin->setPosition(Vec2(pos.x , pos.y + (_lineDeadCoin[i] * diffY)));

        moveCoin(coin, pos);
      }
    }
  }

}

void HelloWorld::addGameScore(int deadCoinNum) {
  char score[100] = {0,};

  _score += (deadCoinNum * 100);

  sprintf(score, "%i" , _score);
  _scoreFont->setString(score);

}


void HelloWorld::timeCount(float dt) {
  if ( --_gameTime == 0)
    changeToOpeningScene();
}

void HelloWorld::changeToOpeningScene() {

  this->unschedule(schedule_selector(HelloWorld::timeCount));

  auto scene = Opening::createScene();
  Director::getInstance()->replaceScene(TransitionFade::create(1.0f, scene));
}
