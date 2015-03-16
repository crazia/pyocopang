#ifndef _GAMECOIN_H_
#define _GAMECOIN_H_

#include "cocos2d.h"

class GameCoin : public cocos2d::Sprite
{

 public:
  enum gameState {
    LIVE,
    DEAD,
    SELECT,
    MOVE
  };

  CC_SYNTHESIZE(int, _type, Type);
  CC_SYNTHESIZE(int, _state, State);

  static GameCoin* spriteWithFile (const char* pszFileName);

  GameCoin();
  ~GameCoin();
};

#endif /* _GAMECOIN_H_ */
